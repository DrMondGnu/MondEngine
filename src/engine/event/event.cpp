//
// Created by MondGnu on 2/27/2024.
//

#include "engine/event/event.h"


namespace mondengine {

    EventType EventTyped::GetEventType() const
    {
        return eventType;
    }

    EventId EventTyped::GetEventId() const
    {
        return EVENT_TYPE_TO_ID(eventType);
    }

    EventCategory EventTyped::GetEventCategory() const
    {
        return EVENT_TYPE_TO_CATEGORY(eventType);
    }

    bool EventTyped::operator==(EventTyped &eventTyped) const
    {
        return eventTyped.GetEventType() == GetEventType();

    }

    bool EventTyped::EqualsCategory(EventTyped &eventTyped) const
    {
        return *this == eventTyped
        || ((eventTyped.GetEventId() == 0 || GetEventId() == 0) && eventTyped.GetEventCategory() == GetEventCategory());;
    }

    Event::Event(EventType eventType) : EventTyped(eventType) {}

    Event::Event(EventId id, EventCategory category) : EventTyped(id, category) {}

} // event
// mondengine

fmt::basic_appender<char>
fmt::formatter<mondengine::Event>::format(mondengine::Event &e, fmt::format_context &ctx) const
{
    return formatter<std::string>::format(e.ToString(), ctx);
}