//
// Created by MondGnu on 3/1/2024.
//

#ifndef NINDO_SHAPE_H
#define NINDO_SHAPE_H

#include "engine/graphics/renderer.h"
#include "engine/transformable.h"

namespace mondengine {
    using namespace graphics;


    class Shape : public Transformable {
        friend class ShapeRenderer;
    public:
        Shape();
        Shape(const glm::vec2 &position, const glm::vec2 &size, float rotation, const glm::vec3 &color);
    protected:
        virtual void Draw() const = 0;
        glm::vec3 color = glm::vec3(0.0f);
//        virtual void Draw(glm::vec2 position, glm::vec2 size, float rotation, glm::vec3 color) const = 0;
    };

    class ShapeRenderer : public Renderer<Shape>{
    public:
        MOND_API explicit ShapeRenderer(Shader &shader);
        MOND_API void Render(Shape &r) override;
    };

} // mondengine

#endif //NINDO_SHAPE_H
