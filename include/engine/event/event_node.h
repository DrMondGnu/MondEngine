//
// Created by MondGnu on 2/27/2024.
//

#ifndef NINDO_EVENT_NODE_H
#define NINDO_EVENT_NODE_H

#include <memory>
#include <unordered_map>
#include <typeindex>
#include <vector>
#include "library.h"

namespace mondengine {
    namespace event {

        class EventNode {
        public:

            template<class T>
            void add_event_listener(void(*callback)(T))
            {
                m_listeners[typeid(T)].push_back(callback);
            }
            template<class T>
            void push_event(T* event)
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

            MOND_API void add_child(EventNode* eventNode);
        private:
            std::unordered_map<std::type_index, std::vector<void(*)>> m_listeners;
            std::vector<EventNode*> m_children;
        };



    } // event
} // mondengine

#endif //NINDO_EVENT_NODE_H
