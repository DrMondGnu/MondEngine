//
// Created by MondGnu on 2/29/2024.
//

#include "engine/game_object.h"

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

    void TickObjectHandler::Add(ITickObject *object)
    {
        if(object == nullptr) {
            return;
        }
        m_children.insert(object);
    }

    void RenderObjectHandler::Render(Renderer &renderer, float lag)
    {
        for (const auto &item: m_children) {
            if(item == nullptr) {
                m_children.erase(item);
                continue;
            }
            item->Render(renderer, lag);
        }
    }

    void RenderObjectHandler::Add(IRenderObject *object)
    {
        if(object == nullptr) {
            return;
        }
        m_children.insert(object);
    }
} // mondengine