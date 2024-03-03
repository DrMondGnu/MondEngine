//
// Created by MondGnu on 3/1/2024.
//

#ifndef NINDO_RECTANGLE_H
#define NINDO_RECTANGLE_H

#include "engine/graphics/vao.h"
#include "shape.h"

namespace mondengine {
    using namespace graphics;

    class Rectangle : public Shape {
    public:
        MOND_API Rectangle();
        MOND_API Rectangle(const glm::vec2 &position, const glm::vec2 &size, float rotation, const glm::vec3 &color);
    protected:
        void Draw() const override;
    private:
        static void InitVao();
        inline static VAO* Vao = nullptr;
    };

} // mondengine

#endif //NINDO_RECTANGLE_H
