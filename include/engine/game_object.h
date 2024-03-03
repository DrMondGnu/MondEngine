//
// Created by MondGnu on 2/29/2024.
//

#ifndef NINDO_GAME_OBJECT_H
#define NINDO_GAME_OBJECT_H

#include "util/general.h"
#include "node.h"
#include "graphics/renderer.h"

namespace mondengine {
using namespace graphics;

    class IRenderObject{
    public:
        MOND_API virtual void Render(Renderer &renderer, float lag) = 0;
    };

    class ITickObject{
    public:
        MOND_API virtual void Tick() = 0;
    };


    class IStaticGameObject : IRenderObject{
    };


    class IGameObject : public IRenderObject, public ITickObject {

    };

    // Offload m_children into interface class
    class TickObjectHandler : ITickObject{
    public:
        void Tick() override;
        void Add(ITickObject* object);
    private:
        std::unordered_set<ITickObject*> m_children;
    };

    class RenderObjectHandler : IRenderObject{
    public:
        void Render(Renderer &renderer, float lag) override;
        void Add(IRenderObject* object);
    private:
        std::unordered_set<IRenderObject*> m_children;
    };


} // mondengine

#endif //NINDO_GAME_OBJECT_H
