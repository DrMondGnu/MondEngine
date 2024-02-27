//
// Created by MondGnu on 2/27/2024.
//

#include "engine/event/event_node.h"

namespace mondengine {
    namespace event {

        void EventNode::add_child(EventNode *eventNode)
        {
            m_children.push_back(eventNode);
        }
    } // event
} // mondengine