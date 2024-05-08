//
// Created by MondGnu on 4/28/2024.
//

#ifndef MONDENGINE_DRAWABLESHADER_H
#define MONDENGINE_DRAWABLESHADER_H

#include "glm/matrix.hpp"

#include "Shader.h"

namespace Mond {

    class DrawableShader : public Shader {
    public:
        DrawableShader();

        virtual void SetModelMatrix(const glm::mat4& model) const = 0;
        virtual void SetColor(const glm::vec4& color) const = 0;
    };

} // Mond

#endif //MONDENGINE_DRAWABLESHADER_H
