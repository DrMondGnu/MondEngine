//
// Created by MondGnu on 3/1/2024.
//

#ifndef NINDO_SHAPE_H
#define NINDO_SHAPE_H

#include "engine/graphics/renderer.h"
#include "engine/transformable.h"
#include "engine/game_object.h"

namespace mondengine {
    using namespace graphics;


    class Shape : public Transformable, public IRenderObject{
    public:
        explicit Shape() = default;

        Shape(const glm::vec2 &position, const glm::vec2 &size, float rotation, const glm::vec3 &color);
        void Render(Renderer &renderer, float lag) override = 0;
    protected:
        glm::vec3 color = glm::vec3(0.0f);
//        virtual void Draw(glm::vec2 position, glm::vec2 size, float rotation, glm::vec3 color) const = 0;
    };
} // mondengine

#endif //NINDO_SHAPE_H
