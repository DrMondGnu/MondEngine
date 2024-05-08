//
// Created by MondGnu on 5/1/2024.
//

#ifndef MONDENGINE_VERTEXARRAY_H
#define MONDENGINE_VERTEXARRAY_H

#include "Bindable.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace Mond::Graphics {

    class VertexArray : public Bindable {
    public:
        virtual void AddVertexBuffer(VertexBuffer& buffer) = 0;
        virtual void SetIndexBuffer(IndexBuffer& buffer) = 0;
    };
} // Mond

#endif //MONDENGINE_VERTEXARRAY_H
