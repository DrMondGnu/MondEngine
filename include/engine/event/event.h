//
// Created by MondGnu on 2/27/2024.
//

#ifndef NINDO_EVENT_H
#define NINDO_EVENT_H

#include <functional>
#include <string>




namespace mondengine::event {

#define EVENT_CATEGORY_SIZE 8
#define EVENT_ID_SIZE 16

#define BIT(x) (1 << x)
#define CATEGORIZE(c, x) ((x << 8)+c)
#define REMOVE_CATEGORY(x) (x>>8)
#define CATEGORY_OF(x) (x&255)

    // EventType consists of EventCategory and EventId
    // The first 8 bits are used for the EventCategory
    // The 16 bits after are used for the EventId
    // The last 8 bits are not used yet
    typedef uint16_t EventId; // Id
    typedef uint8_t EventCategory; // Category as a BitMask
    typedef uint32_t EventType; // Encapsulates Category and Id

    enum EventCategories : EventCategory {
        None = 0,
        EventCategoryEngine         = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryWindow         = BIT(2),
        EventCategoryKeyboard       = BIT(3),
        EventCategoryMouse          = BIT(4),
        EventCategoryMouseButton    = BIT(5),
        EventCategoryCustom         = BIT(6)
    };

    enum EventCategoryKeyboard : EventType {
        KeyDown = CATEGORIZE(EventCategoryKeyboard, 0),
        KeyPressed = CATEGORIZE(EventCategoryKeyboard, 1),
        KeyReleased = CATEGORIZE(EventCategoryKeyboard, 2)
    };






#define EVENT_CLASS_TYPE(type, name) ([[nodiscard]] static EventType GetStaticType() { return type; } \
                                [[nodiscard]] virtual EventType GetEventType() const override { return type; }\
                                [[nodiscard]] virtual const char* GetName() const override { return name; })

#define EVENT_CLASS_CATEGORY(category) [[nodiscard]] virtual EventCategory GetEventCategory() const override { return category; }


    class Event {
        friend class EventDispatcher;

    public:
        [[nodiscard]] virtual const char *GetName() const = 0;
        [[nodiscard]] virtual EventType GetEventType() const = 0;
        [[nodiscard]] virtual EventCategory GetEventCategory() const = 0;
        [[nodiscard]] virtual std::string ToString() const = 0;
        [[nodiscard]] bool IsHandled() const;

    protected:
        bool m_Handled = false;
    };

    template<typename E>
    class EventConsumer {
        template<typename T>
        using EventFn = std::function<bool(T &)>;
    public:
        EventConsumer(const EventFn<E> &fn, EventType eventType) : m_function(fn), m_EventType(eventType) {}

        bool operator==(Event& event)
        {
            return event.GetEventType() == m_EventType;
        }

        const EventFn<E> &GetFunction() const
        {
            return m_function;
        }

    protected:
        EventFn<E> m_function;
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
        bool Dispatch(EventFn<T> func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                dispatch(func);
                return true;
            }
            return false;
        }

        template<typename T>
        bool Dispatch(EventConsumer<T> consumer)
        {
            if(m_Event == consumer) {
                dispatch(consumer.GetFunction());
                return true;
            }
            return false;
        }
    protected:
        template<typename T>
        bool dispatch(EventFn<T> func) {
            m_Event.m_Handled = func(*(T *) &m_Event);
            return true;
        }
    private:
        Event &m_Event;
    };

} // event
// mondengine

#endif //NINDO_EVENT_H
