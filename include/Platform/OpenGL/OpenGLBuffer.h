//
// Created by MondGnu on 5/1/2024.
//

#ifndef MONDENGINE_OPENGLBUFFER_H
#define MONDENGINE_OPENGLBUFFER_H

#include <GL/glew.h>
#include "Engine/Graphics/Core/Buffer.h"

namespace Mond::Graphics::OpenGL {

    class OpenGLBufferInfo {
    public:
        enum Type : GLenum {
            Array = GL_ARRAY_BUFFER,
            AtomicCounter = GL_ATOMIC_COUNTER_BUFFER,
            CopyRead = GL_COPY_READ_BUFFER,
            CopyWrite = GL_COPY_WRITE_BUFFER,
            DispatchIndirect = GL_DISPATCH_INDIRECT_BUFFER,
            DrawIndirect = GL_DRAW_INDIRECT_BUFFER,
            ElementArray = GL_ELEMENT_ARRAY_BUFFER,
            PixelPack = GL_PIXEL_PACK_BUFFER,
            PixelUnpack = GL_PIXEL_UNPACK_BUFFER,
            Query = GL_QUERY_BUFFER,
            ShaderStorage = GL_SHADER_STORAGE_BUFFER,
            Texture = GL_TEXTURE_BUFFER,
            TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER,
            Uniform = GL_UNIFORM_BUFFER,
        };
        enum Usage : GLenum {
            STREAM_DRAW = GL_STREAM_DRAW,
            STREAM_READ = GL_STREAM_READ,
            STREAM_COPY= GL_STREAM_COPY,

            STATIC_DRAW = GL_STATIC_DRAW,
            STATIC_READ = GL_STATIC_READ,
            STATIC_COPY = GL_STATIC_READ,

            DYNAMIC_DRAW = GL_DYNAMIC_DRAW,
            DYNAMIC_READ = GL_DYNAMIC_READ,
            DYNAMIC_COPY = GL_DYNAMIC_COPY,
        };
    };



    template <OpenGLBufferInfo::Type type, typename T>
    requires IsBindable<T>
    class OpenGLBuffer : public T {
    public:

        OpenGLBuffer(GLsizeiptr size, const void* data, OpenGLBufferInfo::Usage usage) {
            glGenBuffers(1, &id);
            glBindBuffer(type, id);
            glBufferData(type, size, data, usage);
            glBindBuffer(type, 0);
        }
        void Bind() const override
        {
            glBindBuffer(type, id);
        }

        void Unbind() const override
        {
            glBindBuffer(type, 0);
        }
        ~OpenGLBuffer() override
        {
            glDeleteBuffers(1, &id);
        }
    protected:
        GLuint id = 0;
    };

} // OpenGL
// Graphics
// Mond

#endif //MONDENGINE_OPENGLBUFFER_H
