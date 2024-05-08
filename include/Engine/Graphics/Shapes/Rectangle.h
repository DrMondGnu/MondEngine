//
// Created by MondGnu on 5/1/2024.
//

#ifndef MONDENGINE_RECTANGLE_H
#define MONDENGINE_RECTANGLE_H

#include "Shape.h"
#include "../Core/VertexArray.h"

namespace Mond::Graphics {


    class Rectangle : public Shape {
    public:
        void Draw() const override;
    protected:
        inline static VertexArray* Vao;
    };
}


#endif //MONDENGINE_RECTANGLE_H
