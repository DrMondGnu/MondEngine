//
// Created by MondGnu on 5/1/2024.
//

#ifndef MONDENGINE_OPENGLINDEXBUFFER_H
#define MONDENGINE_OPENGLINDEXBUFFER_H

#include "OpenGlBuffer.h"
#include "Engine/Graphics/Core/IndexBuffer.h"
#include "Engine/Platform.h"

namespace Mond::Graphics::OpenGL {

    class OpenGLIndexBuffer : public OpenGLBuffer<OpenGLBufferInfo::ElementArray, IndexBuffer> {
    public:
        OpenGLIndexBuffer(GLsizeiptr size, const void *data, OpenGLBufferInfo::Usage usage);
    };
} // OpenGL
// Graphics
// Mond
#ifdef MOND_ENGINE_OPENGL
namespace Mond {
    template <> struct PlatformCreator<Graphics::IndexBuffer*> {
        Graphics::OpenGL::OpenGLIndexBuffer* Create(GLsizeiptr size, const void *data, Graphics::OpenGL::OpenGLBufferInfo::Usage usage) {
            return new Graphics::OpenGL::OpenGLIndexBuffer(size, data, usage);
        }
    };
}
#endif
#endif //MONDENGINE_OPENGLINDEXBUFFER_H
