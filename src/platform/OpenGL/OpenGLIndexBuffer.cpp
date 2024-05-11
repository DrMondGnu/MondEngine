//
// Created by MondGnu on 5/1/2024.
//

#include "Platform/OpenGL/OpenGLIndexBuffer.h"



namespace Mond::Graphics::OpenGL {

    OpenGLIndexBuffer::OpenGLIndexBuffer(GLsizeiptr size, const void *data, OpenGLBufferInfo::Usage usage)
            : OpenGLBuffer(size, data, usage) {}
} // OpenGL
// Graphics
// Mond