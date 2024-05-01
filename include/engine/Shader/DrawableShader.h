//
// Created by MondGnu on 4/28/2024.
//

#ifndef MONDENGINE_DRAWABLESHADER_H
#define MONDENGINE_DRAWABLESHADER_H

#include "glm/matrix.hpp"

#include "Shader.h"

namespace mondengine {

    class DrawableShader : public Shader {
    public:
        DrawableShader();

        explicit DrawableShader(const GLuint &id);

        virtual void SetModelMatrix(const glm::mat4& model) const = 0;
        virtual void SetColor(const glm::vec4& color) const = 0;
    };

} // mondengine

#endif //MONDENGINE_DRAWABLESHADER_H
