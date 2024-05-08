//
// Created by MondGnu on 5/1/2024.
//

#ifndef MONDENGINE_VERTEXBUFFER_H
#define MONDENGINE_VERTEXBUFFER_H

#include "Buffer.h"


namespace Mond::Graphics {
    struct VertexBufferLayout {
        GLint size;
        GLenum type;
        GLboolean normalized;
        GLsizei stride;
        const void* offset;
    };

    class VertexBuffer : public Buffer {
    public:
        virtual const VertexBufferLayout& GetLayout() const = 0;
        virtual void SetLayout(const VertexBufferLayout& layout) = 0;
    };

}


#endif //MONDENGINE_VERTEXBUFFER_H
