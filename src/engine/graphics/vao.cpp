// Created by MondGnu on 2/24/2024.
//

#include "engine/graphics/vao.h"

namespace mondengine::graphics {
    VAO::VAO() : mc_attrib(0)
    {
        GL_CHECK_ERROR_FN(glGenVertexArrays(1, &m_id)); // Create the VAO
        GL_CHECK_ERROR_FN(glBindVertexArray(0));
    }

    void VAO::draw(GLint first, GLsizei count)
    {
        bind();
        glDrawArrays(GL_TRIANGLES, first, count);
0
    }

    void VAO::AddAttribPointer(GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer,
                               VBO& vbo)
    {
        bind();
        vbo.bind();
        GL_CHECK_ERROR_FN(glEnableVertexAttribArray(mc_attrib));
        GL_CHECK_ERROR_FN(glVertexAttribPointer(mc_attrib, size, type, normalized, stride, pointer));
        mc_attrib++;
        vbo.unbind();
        unbind();
    }

    void VAO::bind()
    {
        RETURN_IF_BOUND
        glBindVertexArray(m_id);
        m_bound = true;
    }

    void VAO::unbind()
    {
        RETURN_IF_NOT_BOUND
        glBindVertexArray(0);
        m_bound = false;
    }

    void VAO::SetEBO(EBO &ebo)
    {
        bind();
        ebo.bind();
        unbind();
        ebo.unbind();
    }

    void VAO::DrawEBO(GLsizei count, GLenum type, const void* index)
    {
        bind();
        glDrawElements(GL_TRIANGLES, count, type, index);
    }
}