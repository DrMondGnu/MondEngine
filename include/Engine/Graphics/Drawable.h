//
// Created by MondGnu on 4/28/2024.
//

#ifndef MONDENGINE_DRAWABLE_H
#define MONDENGINE_DRAWABLE_H

#include "glm/matrix.hpp"

#include "RenderObject.h"
#include "Renderer.h"
#include "Engine/Transform.h"
#include "Engine/Shader/DrawableShader.h"

namespace Mond {

    class Drawable : public Transform, public RenderObject {
    public:
        void Render() const override;

        /**
         * draws should not set any shaders or model matrices
         */
        virtual void Draw() const = 0;
        [[nodiscard]] virtual const DrawableShader& GetShader() const = 0;
        [[nodiscard]] virtual const glm::vec4& GetColor() const = 0;
    };
} // Mond

#endif //MONDENGINE_DRAWABLE_H
