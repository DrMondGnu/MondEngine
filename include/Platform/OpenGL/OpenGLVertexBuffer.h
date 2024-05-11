//
// Created by MondGnu on 5/1/2024.
//

#ifndef MONDENGINE_OPENGLVERTEXBUFFER_H
#define MONDENGINE_OPENGLVERTEXBUFFER_H

#include "Engine/Graphics/Core/VertexBuffer.h"

#include "OpenGLBuffer.h"
#include "Engine/PlatformUtils.h"

namespace Mond::Graphics::OpenGL {

    class OpenGLVertexBuffer : public OpenGLBuffer<OpenGLBufferInfo::Array, VertexBuffer> {
    public:
        OpenGLVertexBuffer(GLsizeiptr size, const void *data, OpenGLBufferInfo::Usage usage, const VertexBufferLayout& layout);

        [[nodiscard]] const VertexBufferLayout &GetLayout() const override;

        void SetLayout(const VertexBufferLayout &layout) override;
    protected:
        VertexBufferLayout layout;
    };
}

#ifdef MOND_ENGINE_OPENGL
namespace Mond {
    template <> struct PlatformCreator<Graphics::VertexBuffer*> {
        Graphics::OpenGL::OpenGLVertexBuffer* Create(GLsizeiptr size, const void *data, Graphics::OpenGL::OpenGLBufferInfo::Usage usage, const Graphics::VertexBufferLayout& layout) {
            return new Graphics::OpenGL::OpenGLVertexBuffer(size, data, usage, layout);
        }
    };
}
#endif

// OpenGL
// Graphics
// Mond

#endif //MONDENGINE_OPENGLVERTEXBUFFER_H
