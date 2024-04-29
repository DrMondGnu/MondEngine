//
// Created by MondGnu on 4/28/2024.
//

#ifndef MONDENGINE_RENDEROBJECT_H
#define MONDENGINE_RENDEROBJECT_H

#include "Renderer.h"

namespace mondengine {

    class RenderObject {
    public:
        virtual void Render() const = 0;
    };

    template <> class Renderer<RenderObject> {
        void Render(const RenderObject& object) {
            object.Render();
        }
    };
} // mondengine

#endif //MONDENGINE_RENDEROBJECT_H
