//
// Created by MondGnu on 2/29/2024.
//

#ifndef NINDO_GAME_OBJECT_H
#define NINDO_GAME_OBJECT_H

#include <library.h>
#include <set>
#include "util/general.h"


namespace mondengine {

    class TickObject{
    public:
        MOND_API virtual void Tick() = 0;
    };

    // Offload m_children into interface class
    class TickObjectHandler : TickObject{
    public:
        void Tick() override;
        void AddTickObject(TickObject*&& object);
    private:
        std::set<TickObject*> m_children;
    };



} // mondengine

#endif //NINDO_GAME_OBJECT_H
