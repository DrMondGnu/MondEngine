//
// Created by MondGnu on 2/27/2024.
//

#include "engine/event/event.h"


namespace mondengine {


/*    void EventNode::AddNode(EventNode *node)
    {
        if (node == nullptr) {
            return;
        }
        node->parent->RemoveNode(node);
        node->parent = this;
        children.insert(parent);
    }

    void EventNode::RemoveNode(EventNode *node)
    {
        node->parent = nullptr;
        children.erase(node);
    }

    void EventNode::DispatchEvent(Event &event)
    {
        if (filter(event)) {
            onEvent(event);
        }
    }

    void EventNode::onEvent(Event &event)
    {
        handler.Dispatch(event);
    }

    bool EventNode::filter(Event &event)
    {
        return true;
    }*/

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

    EventTyped::EventTyped(EventType eventType) : eventType(eventType) {}

    EventTyped::EventTyped(EventId id, EventCategory category) : eventType(CATEGORIZE(category, id))
    {

    }

    bool EventTyped::EqualsCategory(EventTyped &eventTyped) const
    {
        return *this == eventTyped
        || ((eventTyped.GetEventId() == 0 || GetEventId() == 0) && eventTyped.GetEventCategory() == GetEventCategory());;
    }

    Event::Event(EventType eventType) : EventTyped(eventType) {}

    Event::Event(EventId id, EventCategory category) : EventTyped(id, category) {}

    IEventConsumer::IEventConsumer(EventType eventType) : EventTyped(eventType) {}

    IEventConsumer::IEventConsumer(EventId id, EventCategory category) : EventTyped(id, category) {}
} // event
// mondengine

fmt::basic_appender<char>
fmt::formatter<mondengine::Event>::format(mondengine::Event &e, fmt::format_context &ctx) const
{
    return formatter<std::string>::format(e.ToString(), ctx);
}