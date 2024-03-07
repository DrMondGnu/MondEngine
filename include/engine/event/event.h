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
        MOND_API explicit EventTyped(EventType eventType) : eventType(eventType) {};
        MOND_API explicit EventTyped(EventCategory category) : eventType(CATEGORIZE(category, 0)) {};
        MOND_API EventTyped(EventId id, EventCategory category) : eventType(CATEGORIZE(category, id)) {};
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

    typedef std::function<void(const Event &)> EventConsumer;

    /**
     * Event handler to handle every event and store multiple callbacks
     */
    class EventManager {
    public:

        void Add(EventTyped filter, const EventConsumer& consumer) {
//            MOE_TRACE("Event added: (filter: {})", filter.GetEventType());
            m_consumers[filter.GetEventCategory()].push_back({consumer,filter.GetEventId()});
        }
        /*+
         * Dispatches event to all matching callback functions
         */
        void Dispatch(const Event& event) {
//            MOE_TRACE("Dispatching event: {}", event.ToString());
            for (const auto &item: m_consumers[event.GetEventCategory()]) {
                if(item.id == event.GetEventId() || item.id == 0) {
                    item.consumer(event);
                }
            }
        }
    private:
        struct RegisteredEventConsumer {
            const EventConsumer consumer;
            EventId id;
        };
        std::unordered_map<EventCategory, std::vector<RegisteredEventConsumer>> m_consumers;
    };

} // event
// mondengine
template<>
struct fmt::formatter<mondengine::Event>: fmt::formatter<std::string> {
    fmt::basic_appender<char>  format(mondengine::Event &e, format_context &ctx) const;
};

#endif //NINDO_EVENT_H
