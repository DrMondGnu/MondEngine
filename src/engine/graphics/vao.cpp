// Created by MondGnu on 2/24/2024.
//

#include "engine/graphics/vao.h"

namespace mondengine::graphics {
    VAO::VAO() : mc_attrib(0)
    {
        GL_CHECK_ERROR(glGenVertexArrays(1, &m_id)); // Create the VAO
        GL_CHECK_ERROR(glBindVertexArray(0));
    }

    void VAO::draw()
    {
        bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);

    }

    void VAO::add_vbo(GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer,
                      VBO *vbo)
    {
        bind();
        vbo->bind();
        GL_CHECK_ERROR(glVertexAttribPointer(mc_attrib, size, type, normalized, stride, pointer));
        GL_CHECK_ERROR(glEnableVertexAttribArray(mc_attrib));
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

    void VAO::set_ebo(EBO *ebo)
    {
        bind();
        ebo->bind();
        unbind();
        ebo->unbind();
    }

    void VAO::draw_ebo(GLsizei count, GLenum type, const void* index)
    {
        bind();
        glDrawElements(GL_TRIANGLES, count, type, index);
    }
}