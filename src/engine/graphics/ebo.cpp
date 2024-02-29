//
// Created by MondGnu on 2/27/2024.
//

#include "engine/graphics/ebo.h"


namespace mondengine::graphics {
    void EBO::bind()
    {
        RETURN_IF_BOUND
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
        m_bound = true;
    }

    void EBO::unbind()
    {
        RETURN_IF_NOT_BOUND
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        m_bound = false;
    }

    EBO::EBO(const void* data, GLsizeiptr size) {
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
} // graphics
// mondengine