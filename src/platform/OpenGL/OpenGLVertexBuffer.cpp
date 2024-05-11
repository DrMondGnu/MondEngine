//
// Created by MondGnu on 5/1/2024.
//

#include "Platform/OpenGL/OpenGLVertexBuffer.h"


namespace Mond::Graphics::OpenGL {

    OpenGLVertexBuffer::OpenGLVertexBuffer(GLsizeiptr size, const void *data, OpenGLBufferInfo::Usage usage,
                                           const VertexBufferLayout &layout) : OpenGLBuffer(size,
                                                                                            data,
                                                                                            usage),
                                                                               layout(layout) {}

    const VertexBufferLayout &OpenGLVertexBuffer::GetLayout() const
    {
        return layout;
    }

    void OpenGLVertexBuffer::SetLayout(const VertexBufferLayout &layout)
    {
        this->layout = layout;
    }


} // OpenGL
// Graphics
// Mond