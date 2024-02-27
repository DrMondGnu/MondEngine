//
// Created by MondGnu on 2/27/2024.
//

#include "engine/event/event_node.h"

namespace mondengine {
    namespace event {

        template<class T>
        void EventNode::add_event_listener(void(*callback)(T))
        {
            m_listeners[typeid(T)].push_back(callback);
        }

        template<class T>
        void EventNode::push_event(T* event)
        {
            auto callbacks = m_listeners[typeid(T *)];
            for (const auto &item: callbacks)
            {
                void (*callback)(T*) = (void (*)(T*)) item;
                callback(event);
            }
            for (const auto &item: m_children) {
                item->push_event(event);
            }
        }

        void EventNode::add_child(EventNode *eventNode)
        {
            m_children.push_back(eventNode);
        }
    } // event
} // mondengine