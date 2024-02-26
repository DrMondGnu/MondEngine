// Created by MondGnu on 2/24/2024.
//

#include "engine/graphics/vao.h"

namespace mondengine::graphics {
    VAO::VAO() : mc_attrib(0)
    {
        glGenVertexArrays(1, &m_id); // Create the VAO
        glBindVertexArray(0);
    }

    void VAO::draw()
    {
        glBindVertexArray(m_id);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void VAO::add_vbo(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer,
                      VBO *vbo)
    {
        bind();
        vbo->bind();
        glVertexAttribPointer(index, size, type, normalized, stride, pointer);

        glEnableVertexAttribArray(mc_attrib);
        mc_attrib++;
        vbo->unbind();
        unbind();
    }

    void VAO::bind()
    {
        glBindVertexArray(m_id);
    }

    void VAO::unbind()
    {
        glBindVertexArray(0);
    }
}