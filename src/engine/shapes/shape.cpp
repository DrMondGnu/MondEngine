//
// Created by MondGnu on 3/1/2024.
//

#include "engine/shapes/shape.h"

namespace mondengine {
    void ShapeRenderer::Render(Shape &r)
    {
        setModel(r.ModelMatrix());
        setColor(r.color);
        setUseTexture(false);
        r.Draw();
    }

    ShapeRenderer::ShapeRenderer(Shader &shader) : Renderer(shader) {}

    Shape::Shape(const glm::vec2 &position, const glm::vec2 &size, float rotation, const glm::vec3 &color)
            : Transformable(position, size, rotation), color(color) {}

    Shape::Shape() {}
} // mondengine