//
// Created by MondGnu on 2/26/2024.
//

#ifndef NINDO_VBO_H
#define NINDO_VBO_H

#include "GL/glew.h"
#include "engine/glid.h"
#include "util/opengl.h"

namespace mondengine::graphics {

    class VBO : GLID{
    public:
        VBO(const void* data, GLsizeiptr size);
        void bind() override;
        void unbind() override;
    private:


    private:
    };

} // graphics
// mondengine

#endif //NINDO_VBO_H
