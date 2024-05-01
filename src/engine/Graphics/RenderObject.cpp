//
// Created by MondGnu on 4/28/2024.
//

#include "engine/Graphics/RenderObject.h"

namespace mondengine {
    void RenderObjectHandler::Render() const
    {
        Renderer<RenderObject*> renderer;
        for (const auto &item: objects) {
            renderer.Render((const RenderObject *&) item);
        }
    }

    void RenderObjectHandler::AddRenderObject(RenderObject *&object)
    {
        objects.insert(object);
    }
} // mondengine