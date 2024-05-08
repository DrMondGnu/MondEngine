//
// Created by MondGnu on 4/28/2024.
//

#include <utility>

#include "engine/graphics/Drawable.h"

namespace Mond {

    void Drawable::Render() const
    {
        auto& shader = GetShader();
        shader.Bind();
        shader.SetModelMatrix(ModelMatrix());
        shader.SetColor(GetColor());
        Draw();
    }

} // Mond