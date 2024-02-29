//
// Created by MondGnu on 2/29/2024.
//

#ifndef NINDO_CUBE_H
#define NINDO_CUBE_H

#include "vao.h"
#include "vbo.h"
#include "ebo.h"

namespace mondengine::graphics {

    class Cube {
    public:
        explicit Cube(float size);
        void Draw();
    private:
       VAO m_Vao;
    };

} // graphics
// mondengine

#endif //NINDO_CUBE_H
