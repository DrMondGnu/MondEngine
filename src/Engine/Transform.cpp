//
// Created by MondGnu on 4/28/2024.
//

#include <engine/Transform.h>

namespace Mond {
    Transform::Transform(const glm::vec2 &position, const glm::vec2 &size, float rotation) : position(position),
                                                                                             size(size),
                                                                                             rotation(rotation) {}

    glm::mat4 Transform::ModelMatrix() const
    {
        auto model = glm::mat4(1.0f);
        // scale first
        model = glm::translate(model, glm::vec3(position, 0.0f));

        // change rotation point
        model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
        // rotate
        model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
        // change back
        model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
        // scale
        model = glm::scale(model, glm::vec3(size, 1.0f));

        return model;
    }
} // Mond