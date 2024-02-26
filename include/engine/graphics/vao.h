//
// Created by MondGnu on 2/24/2024.
//

#ifndef NINDO_VAO_H
#define NINDO_VAO_H

#include <GL/glew.h>
#include "engine/glid.h"
#include "vbo.h"

namespace mondengine::graphics {

    class VAO : GLID{
    public:
        VAO();
        void draw();
        void add_vbo(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer, VBO* vbo);
        void bind() override;
        void unbind() override;
    private:
        GLuint mc_attrib;
    };

} // graphics
// mondengine

#endif //NINDO_VAO_H
