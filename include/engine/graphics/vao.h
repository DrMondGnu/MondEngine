//
// Created by MondGnu on 2/24/2024.
//

#ifndef NINDO_VAO_H
#define NINDO_VAO_H

#include <GL/glew.h>
#include "engine/glid.h"
#include "vbo.h"
#include "ebo.h"

namespace mondengine::graphics {

    class VAO : GLID{
    public:
        VAO();
        void draw();
        void DrawEBO(GLsizei count, GLenum type, const void* index);
        void AddAttribPointer(GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer, VBO& vbo);
        void SetEBO(EBO& ebo);
        void bind() override;
        void unbind() override;

    private:
        GLuint mc_attrib;
    };

} // graphics
// mondengine

#endif //NINDO_VAO_H
