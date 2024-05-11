//
// Created by MondGnu on 5/1/2024.
//

#ifndef MONDENGINE_RECTANGLE_H
#define MONDENGINE_RECTANGLE_H

#include "Shape.h"
#include "Engine/Platform.h"
#include "../Core/VertexArray.h"

namespace Mond::Graphics {

    class Rectangle : public Shape {
    public:
        Rectangle();

        void Draw() const override;
    protected:
        static void initVao();
        inline static VertexArray* Vao = nullptr;
    };
}


#endif //MONDENGINE_RECTANGLE_H
