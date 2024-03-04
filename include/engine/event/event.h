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

#define EVENT_NAME(name) virtual const char* GetName() const { return name; }

    class EventTyped {
    public:
        MOND_API [[nodiscard]] EventType GetEventType() const;
        MOND_API [[nodiscard]] EventId GetEventId() const;
        MOND_API [[nodiscard]] EventCategory GetEventCategory() const;
        /**
         *
         * @param eventTyped
         * @return true if category and id is same
         */
        MOND_API bool operator==(EventTyped& eventTyped) const;
        /**
         *
         * @param eventTyped
         * @return true if EventType is same or id is 0 for either and category matches
         */
        MOND_API bool EqualsCategory(EventTyped& eventTyped) const;
    protected:
        MOND_API explicit EventTyped(EventType eventType);
        MOND_API EventTyped(EventId id, EventCategory category);
        EventType eventType;
    };

    class Event : public EventTyped{
        friend class EventDispatcher;
    public:
        MOND_API [[nodiscard]] virtual const char *GetName() const = 0;
        MOND_API [[nodiscard]] virtual std::string ToString() const = 0;
    protected:
        explicit Event(EventType eventType);
        Event(EventId id, EventCategory category);
    };

    template<typename T>
    class IEventConsumerBase {
        MOND_API virtual void ConsumeEvent(T& event) const = 0;
    };

    class IEventConsumer : public IEventConsumerBase<Event>, public EventTyped{
    public:
        MOND_API explicit IEventConsumer(EventType eventType);

        MOND_API IEventConsumer(EventId id, EventCategory category);

        void ConsumeEvent(Event& event) const override = 0;
    };

    template<typename E>
    class EventConsumer : public IEventConsumer {
        using EventFn = std::function<void(E&)>;
    public:
        explicit EventConsumer(const EventFn fn, EventType eventType) : function(fn), IEventConsumer(eventType) {}

        void ConsumeEvent(Event &event) const override
        {
            if (EqualsCategory(event)) {
                function(*(E *) &event); // Downcast and call function
            }
        }

        /**
         * Calls internal callback function
         * @param event event to use on callback
         */
        void operator()(E &event) const
        {
            function(event);
        }
        /**
         *
         * @return internal callback function
         */
        const EventFn &GetFunction() const
        {
            return function;
        }

    protected:
        /**
         * Internal callback function
         */
        EventFn function;
    };

    /**
     * Used to dispatch events
     * May be deprecated in the future
     */
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
        void Dispatch(EventFn<T> func)
        {
            if (m_Event.GetEventType() == T::GetStaticType()) {
                dispatch(func);
            }
        }


        void Dispatch(IEventConsumer &consumer)
        {
            consumer.ConsumeEvent(m_Event);
        }

    protected:
        template<typename T>
        void dispatch(EventFn<T> func)
        {
            func(*(T *) &m_Event);
        }

    private:
        Event &m_Event;
    };

    /**
     * Event handler to handle every event and store multiple callbacks
     */
    class EventHandler {
    public:
        /**
         * Adds consumer to callback list, filters with event type and category
         * @tparam T Event type
         * @param consumer callback
         */
        template<typename T>
        void Add(EventConsumer<T>* consumer) {
            MOE_TRACE("Event added: (type: {}, category: {})", consumer->GetEventType(), consumer->GetEventCategory());
            Add(consumer->GetEventCategory(), consumer);
        }
        void Add(EventCategory category, IEventConsumer* consumer) {
            MOE_TRACE("Event added: (category: {})", category);
            m_consumers[category].push_back(consumer);
        }
        /*+
         * Dispatches event to all matching callback functions
         */
        bool Dispatch(Event& event) {
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

    /*class EventNode {
    public:
        void DispatchEvent(Event& event);
        void RemoveNode(EventNode* node);
        void AddNode(EventNode* node);
        template<typename T>
        void AddConsumer(EventConsumer<T>* consumer)
        {
            handler.Add(consumer);
        }
    protected:
        virtual void onEvent(Event& event);
        virtual bool filter(Event& event);
        EventNode* parent;
        EventHandler handler;
        std::unordered_set<EventNode*> children;
    };*/


} // event
// mondengine
template<>
struct fmt::formatter<mondengine::Event>: fmt::formatter<std::string> {
    fmt::basic_appender<char>  format(mondengine::Event &e, format_context &ctx) const;
};

#endif //NINDO_EVENT_H
