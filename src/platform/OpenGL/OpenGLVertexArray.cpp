//
// Created by MondGnu on 5/1/2024.
//

#include "Platform/OpenGL/OpenGLVertexArray.h"



namespace Mond::Graphics::OpenGL {
    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(id);
    }

    void OpenGLVertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &id);
    }

    void OpenGLVertexArray::AddVertexBuffer(VertexBuffer &buffer)
    {
        Bind();
        buffer.Bind();
        auto layout = buffer.GetLayout();
        glVertexAttribPointer(attributeIndex, layout.size, layout.type, layout.normalized, next + layout.stride, (void*)&next);
        glEnableVertexAttribArray(attributeIndex);
        attributeIndex++;
        next += layout.stride;
        buffer.Unbind();
        Unbind();
    }

    void OpenGLVertexArray::SetIndexBuffer(IndexBuffer &buffer)
    {
        Bind();
        buffer.Bind();
        Unbind();
        buffer.Unbind();
    }
} // OpenGL
// Graphics
// Mond