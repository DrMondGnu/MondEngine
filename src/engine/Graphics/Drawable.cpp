//
// Created by MondGnu on 4/28/2024.
//

#include "engine/graphics/Drawable.h"

namespace mondengine {
    const Shader &Drawable::GetShader() const
    {
        return shader;
    }

    const glm::vec4 &Drawable::GetColor() const
    {
        return color;
    }

    void Drawable::Render() const
    {
        shader.Bind();
        shader.SetMat4("model", ModelMatrix());
        shader.SetVector4f("color", color);
    }
} // mondengine