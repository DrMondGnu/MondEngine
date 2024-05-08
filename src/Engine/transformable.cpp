//
// Created by MondGnu on 3/1/2024.
//

#include "engine/transformable.h"

namespace Mond {
    glm::mat4 Transformable::ModelMatrix() const
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

    Transformable::Transformable(const glm::vec2 &position, const glm::vec2 &size, float rotation) : position(position),
                                                                                                     size(size),
                                                                                                     rotation(
                                                                                                             rotation) {}

} // Mond