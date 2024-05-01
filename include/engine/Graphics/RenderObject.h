//
// Created by MondGnu on 4/28/2024.
//

#ifndef MONDENGINE_RENDEROBJECT_H
#define MONDENGINE_RENDEROBJECT_H

#include <set>

#include "Renderer.h"


namespace mondengine {

    class RenderObject {
    public:
        virtual void Render() const = 0;
    };

    template <> class Renderer<RenderObject> {
    public:
        void Render(const RenderObject& object) {
            object.Render();
        }
    };
    template <> class Renderer<RenderObject*> {
    public:
        void Render(const RenderObject*& object) {
            object->Render();
        }
    };

    class RenderObjectHandler : public RenderObject{
    public:
        void Render() const override;
        void AddRenderObject(RenderObject*&& object);
    protected:
        std::set<RenderObject*> objects;
    };
} // mondengine

#endif //MONDENGINE_RENDEROBJECT_H
