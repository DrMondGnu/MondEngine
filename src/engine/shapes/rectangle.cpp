//
// Created by MondGnu on 3/1/2024.
//

#include "engine/shapes/rectangle.h"

namespace mondengine {
    void Rectangle::InitVao()
    {
        float vertices[] = {
                // Triangle 1
                -1.0f, -1.0f, // Bottom-Right
                1.0f, -1.0f, // Bottom-Left
                1.0f, 1.0f, // Top-Left
                // Triangle 2
                -1.0f, 1.0f, // Top-Right
                1.0f, 1.0f, // Top-Left
                -1.0f, -1.0f, // Bottom-Right
        };

        Vao = new VAO();
        VBO vbo(vertices, sizeof(vertices));
        Vao->AddAttribPointer(2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr, vbo);
    }

    Rectangle::Rectangle()
    {
        if (Vao == nullptr)
        {
            InitVao();
        }
    }

    void Rectangle::Draw() const
    {
        Vao->draw(0, 6);
    }

    Rectangle::Rectangle(const glm::vec2 &position, const glm::vec2 &size, float rotation, const glm::vec3 &color)
            : Shape(position, size, rotation, color)
    {
        if (Vao == nullptr)
        {
            InitVao();
        }
    }

} // mondengine