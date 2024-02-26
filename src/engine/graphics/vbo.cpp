//
// Created by MondGnu on 2/26/2024.
//

#include "engine/graphics/vbo.h"


namespace mondengine::graphics {
    VBO::VBO(const void* data, GLsizeiptr size)
    {
        GL_CHECK_ERROR(glGenBuffers(1, &m_id));
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        GL_CHECK_ERROR(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
        glBindBuffer(GL_ARRAY_BUFFER, 0);
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