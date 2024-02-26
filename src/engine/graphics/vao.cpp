// Created by MondGnu on 2/24/2024.
//

#include "engine/graphics/vao.h"

namespace mondengine::graphics {
    VAO::VAO(GLfloat *vertices, GLsizeiptr size) : m_ID(0), m_vertexbuffer(0)
    {
        glGenVertexArrays(1, &m_ID); // Create the VAO
        glGenBuffers(1, &m_vertexbuffer); // Create the VBO

        glBindVertexArray(m_ID); // set current VAO

        glBindBuffer(GL_ARRAY_BUFFER, m_vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
        glEnableVertexAttribArray(0);

        // Unbind
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void VAO::draw()
    {
        glBindVertexArray(m_ID);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
}