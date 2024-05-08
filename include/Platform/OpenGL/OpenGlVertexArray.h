//
// Created by MondGnu on 5/1/2024.
//

#ifndef MONDENGINE_OPENGLVERTEXARRAY_H
#define MONDENGINE_OPENGLVERTEXARRAY_H

#include "Engine/Graphics/Core/VertexArray.h"
#include "Engine/Platform.h"

namespace Mond::Graphics::OpenGL {

    class OpenGLVertexArray : public VertexArray{
    public:
        void Bind() const override;

        void Unbind() const override;

        ~OpenGLVertexArray() override;

        void AddVertexBuffer(VertexBuffer &buffer) override;

        void SetIndexBuffer(IndexBuffer &buffer) override;

    protected:
        GLuint attributeIndex = 0;
        GLuint id = 0;
    };

} // OpenGL
// Graphics
// Mond
#ifdef MOND_ENGINE_OPENGL
namespace Mond {
    template <> struct PlatformCreator<Graphics::VertexArray*> {
        Graphics::OpenGL::OpenGLVertexArray* Create() {
            return new Graphics::OpenGL::OpenGLVertexArray();
        }
    };
}
#endif
#endif //MONDENGINE_OPENGLVERTEXARRAY_H
