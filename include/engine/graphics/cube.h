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
        MOND_API explicit Cube(float size);
        MOND_API void Draw();
    private:
       VAO* m_Vao{};
       static void init_cube_vao();
       static VAO* ms_Vao;
    };

} // graphics
// mondengine

#endif //NINDO_CUBE_H
