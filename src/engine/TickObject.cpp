//
// Created by MondGnu on 2/29/2024.
//

#include "engine/TickObject.h"

namespace mondengine {


    void TickObjectHandler::Tick()
    {
        for (const auto &item: m_children) {
            if(item == nullptr) {
                m_children.erase(item);
                continue;
            }
            item->Tick();
        }
    }

    void TickObjectHandler::AddTickObject(TickObject *object)
    {
        if(object == nullptr) {
            return;
        }
        m_children.insert(object);
    }
} // mondengine