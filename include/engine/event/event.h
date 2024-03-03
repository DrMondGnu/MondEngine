//
// Created by MondGnu on 2/27/2024.
//

#ifndef NINDO_EVENT_H
#define NINDO_EVENT_H

#include <functional>
#include <string>
#include "fmt/format.h"
#include "engine/log.h"

namespace mondengine {

#define EVENT_CATEGORY_SIZE 8
#define EVENT_ID_SIZE 16

#define BIT(x) (1 << x)
#define CATEGORIZE(c, x) ((x << EVENT_CATEGORY_SIZE)+c)
#define REMOVE_CATEGORY(x) (x >> EVENT_CATEGORY_SIZE)
#define CATEGORY_OF(x) (x&255)
#define EVENT_TYPE_TO_ID(x) REMOVE_CATEGORY(x)
#define EVENT_TYPE_TO_CATEGORY(x) CATEGORY_OF(x)
#define EVENT_TYPE(c, x) CATEGORIZE(c, x)
    // EventType consists of EventCategory and EventId
    // The first 8 bits are used for the EventCategory
    // The 16 bits after are used for the EventId, event id of zero is reserved for no event id and just the category
    // The last 8 bits are not used yet
    typedef uint16_t EventId; // Id
    typedef uint8_t EventCategory; // Category as a BitMask
    typedef uint32_t EventType; // Encapsulates Category and Id

    enum EventCategories : EventCategory {
        None = 0,
        EventCategoryEngine = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryWindow = BIT(2),
        EventCategoryKeyboard = BIT(3),
        EventCategoryMouse = BIT(4),
        EventCategoryMouseButton = BIT(5),
        EventCategoryCustom = BIT(6)
    };

#define EVENT_CLASS_TYPE(type, name)    [[nodiscard]] virtual EventType GetEventType() const override { return type; } \
                                        [[nodiscard]] virtual EventId GetEventId() const override { return REMOVE_CATEGORY(type); }\
                                        [[nodiscard]] virtual const char* GetName() const override { return name; }


#define EVENT_CLASS_CATEGORY(category) [[nodiscard]] virtual EventCategory GetEventCategory() const override { return category; }


    class Event {
        friend class EventDispatcher;

    public:
        [[nodiscard]] virtual const char *GetName() const = 0;

        [[nodiscard]] virtual EventType GetEventType() const = 0;

        [[nodiscard]] virtual EventId GetEventId() const = 0;

        [[nodiscard]] virtual EventCategory GetEventCategory() const = 0;

        [[nodiscard]] virtual std::string ToString() const = 0;

    protected:
    };

    class IEventConsumer {
    public:
        virtual bool ConsumeEvent(Event& event) const = 0;
    };

    template<typename E>
    class EventConsumer : public IEventConsumer{
        using EventFn = std::function<bool(E &)>;
    public:
        explicit EventConsumer(const EventFn &fn, EventType eventType) : function(fn), m_EventType(eventType) {}

        bool ConsumeEvent(Event &event) const override
        {
            if (*this == event) {
                return function(*(E *) &event); // Downcast and call function
            }
            return false;
        }

        bool operator==(Event &event) const
        {
            return event.GetEventType() == m_EventType ||
                   (REMOVE_CATEGORY(m_EventType) == 0 && event.GetEventCategory() == CATEGORY_OF(m_EventType));
        }

        void operator()(E &event) const
        {
            function(event);
        }

        const EventFn &GetFunction() const
        {
            return function;
        }

        [[nodiscard]] EventCategory GetCategory() const
        {
            return EVENT_TYPE_TO_CATEGORY(m_EventType);
        }

        [[nodiscard]] EventType GetEventType() const
        {
            return m_EventType;
        }

    protected:
        EventFn function;
    private:
        EventType m_EventType;
    };

    class EventDispatcher {
        template<typename T>
        using EventFn = std::function<bool(T &)>;
    public:
        explicit EventDispatcher(Event &event) : m_Event(event) {}

        /**
         *
         * @tparam T the event type which must have:
         * @code
         * static EventType GetStaticType();
         * static CategoryType GetStaticCategory();
         * @endcode
         * @param func function that consumes event
         * @return if it was able to consume event
         */
        template<typename T>
        [[deprecated("Replaced by Dispatch(EventConsumer)")]]
        bool Dispatch(EventFn<T> func)
        {
            if (m_Event.GetEventType() == T::GetStaticType()) {
                return dispatch(func);
            }
            return false;
        }


        bool Dispatch(IEventConsumer &consumer)
        {
            return consumer.ConsumeEvent(m_Event);
        }

    protected:
        template<typename T>
        bool dispatch(EventFn<T> func)
        {
            return func(*(T *) &m_Event);
        }

    private:
        Event &m_Event;
    };

    class EventHandler {
    public:
        template<typename T>
        void Add(EventConsumer<T>* consumer) {
            MOE_TRACE("Event added: (type: {}, category: {})", consumer->GetEventType(), consumer->GetCategory());
            Add(consumer->GetCategory(), consumer);
        }
        void Add(EventCategory category, IEventConsumer* consumer) {
            MOE_TRACE("Event added: (category: {})", category);
            m_consumers[category].push_back(consumer);
        }
        bool Dispatch(Event& event) {
            MOE_TRACE("Dispatching event: (type:{}, category:{})", event.GetEventType(), event.GetEventCategory());
            for (const auto &item: m_consumers[event.GetEventCategory()]) {
                if(item == nullptr) {
                    continue;
                }
                item->ConsumeEvent(event);
            }
            return false;
        }
    private:
        std::unordered_map<EventCategory, std::vector<IEventConsumer*>> m_consumers;
    };

} // event
// mondengine
template<>
struct fmt::formatter<mondengine::Event>: fmt::formatter<std::string> {
    fmt::basic_appender<char>  format(mondengine::Event &e, format_context &ctx) const;
};

#endif //NINDO_EVENT_H
