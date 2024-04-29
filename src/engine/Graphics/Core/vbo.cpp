//
// Created by MondGnu on 2/26/2024.
//

#include "engine/graphics/Core/vbo.h"


namespace mondengine::graphics {
    VBO::VBO(const void* data, GLsizeiptr size)
    {
        GL_CHECK_ERROR_FN(glGenBuffers(1, &m_id));
        GL_CHECK_ERROR_FN(glBindBuffer(GL_ARRAY_BUFFER, m_id));
        GL_CHECK_ERROR_FN(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
        GL_CHECK_ERROR_FN(glBindBuffer(GL_ARRAY_BUFFER, 0));
    }

    void VBO::bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
    }

    void VBO::unbind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
} // graphics
// mondengine