//
// Created by MondGnu on 2/29/2024.
//

#ifndef NINDO_GAME_OBJECT_H
#define NINDO_GAME_OBJECT_H

#include "util/general.h"
#include "node.h"

namespace mondengine {

    class IRenderObject : public Node<IRenderObject>{
    public:
        virtual void Render(float lag) = 0;
    };

    class ITickObject : public Node<ITickObject>{
    public:
        virtual void Tick() = 0;
    };

    class IStaticGameObject : public IRenderObject {
    };

    class IGameObject : public IRenderObject, public ITickObject {

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
