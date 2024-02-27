//
// Created by MondGnu on 2/27/2024.
//

#ifndef NINDO_EVENT_NODE_H
#define NINDO_EVENT_NODE_H

#include <memory>
#include <unordered_map>
#include <typeindex>
#include <vector>
#include "event.h"

namespace mondengine {
    namespace event {

        class EventNode {
        public:

            template<class T>
            void add_event_listener(void(*callback)(T));

            template<class T>
            void push_event(T* event);

            void add_child(EventNode* eventNode);
        private:
            std::unordered_map<std::type_index, std::vector<void(*)>> m_listeners;
            std::vector<EventNode*> m_children;
        };



    } // event
} // mondengine

#endif //NINDO_EVENT_NODE_H
