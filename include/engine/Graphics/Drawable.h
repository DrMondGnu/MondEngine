//
// Created by MondGnu on 4/28/2024.
//

#ifndef MONDENGINE_DRAWABLE_H
#define MONDENGINE_DRAWABLE_H

#include "glm/matrix.hpp"

#include "RenderObject.h"
#include "Renderer.h"
#include "engine/Transform.h"
#include "engine/Shader/Shader.h"

namespace mondengine {

    class Drawable : public Transform, public RenderObject {
    public:
        void Render() const override;

        /**
         * draws should not set any shaders or model matrices
         */
        virtual void Draw() = 0;
        [[nodiscard]] virtual const Shader& GetShader() const = 0;
        [[nodiscard]] virtual const glm::vec4& GetColor() const = 0;
    };

    template <typename T>
    concept IsDrawable = std::derived_from<T, Drawable>;

    template <typename T>
    requires IsDrawable<T>
    class Renderer<T> {
        void Render(const T& object) {
            // TODO: Set shader usw
        }
    };
} // mondengine

#endif //MONDENGINE_DRAWABLE_H
