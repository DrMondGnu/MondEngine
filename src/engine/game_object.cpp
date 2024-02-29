//
// Created by MondGnu on 2/29/2024.
//

#include "engine/game_object.h"

namespace mondengine {


    void TickObjectHandler::Tick()
    {
        for (const auto &item: m_Children) {
            if(item == nullptr) {
                m_Children.erase(item);
                continue;
            }
            item->Get()->Tick();
        }
    }

    void RenderObjectHandler::Render(float lag)
    {
        for (const auto &item: m_Children) {
            if(item == nullptr) {
                m_Children.erase(item);
                continue;
            }
            item->Get()->Render(lag);
        }
    }
} // mondengine