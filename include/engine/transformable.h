//
// Created by MondGnu on 3/1/2024.
//

#ifndef NINDO_TRANSFORMABLE_H
#define NINDO_TRANSFORMABLE_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace mondengine {

    class Transformable {
    public:
        Transformable() = default;
        Transformable(const glm::vec2 &position, const glm::vec2 &size, float rotation);
        [[nodiscard]] glm::mat4 ModelMatrix() const;
    protected:
        glm::vec2 position = glm::vec2(0.0f);
        glm::vec2 size = glm::vec2(0.0f);
        float rotation = 0.0f;
    };

} // mondengine

#endif //NINDO_TRANSFORMABLE_H
