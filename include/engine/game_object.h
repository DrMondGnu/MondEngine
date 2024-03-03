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

    template<typename R>
    class IRenderObject : public Node<IRenderObject<R>>{
    public:
        virtual void Render(Renderer<R> render, float lag) = 0;
    };

    class ITickObject : public Node<ITickObject>{
    public:
        virtual void Tick() = 0;
    };

    template<typename R>
    class IStaticGameObject : public IRenderObject<R> {
    };

    template<typename R>
    class IGameObject : public IRenderObject<R>, public ITickObject {

    };

    class TickObjectHandler : public ITickObject{
    public:
        void Tick() override;
    private:

    };
    class RenderObjectHandler : public IRenderObject {
    public:
        void Render(float lag) override;
    };


} // mondengine

#endif //NINDO_GAME_OBJECT_H
