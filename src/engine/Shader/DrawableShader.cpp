//
// Created by MondGnu on 4/28/2024.
//

#include "engine/Shader/DrawableShader.h"

namespace mondengine {


    DrawableShader::DrawableShader() = default;

    DrawableShader::DrawableShader(const GLuint &id) : Shader(id) {}
} // mondengine