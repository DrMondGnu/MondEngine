//
// Created by MondGnu on 4/28/2024.
//

#ifndef MONDENGINE_TRANSFORM_H
#define MONDENGINE_TRANSFORM_H

#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace mondengine {

    struct Transform {
    public:
        Transform() = default;
        Transform(const glm::vec2 &position, const glm::vec2 &size, float rotation);
        [[nodiscard]] glm::mat4 ModelMatrix() const;
    protected:
        glm::vec2 position = glm::vec2(0.0f);
        glm::vec2 size = glm::vec2(0.0f);
        float rotation = 0.0f;
    };

} // mondengine

#endif //MONDENGINE_TRANSFORM_H
