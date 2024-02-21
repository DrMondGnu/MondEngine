//
// Created by MondGnu on 2/21/2024.
//

#include "engine/shader.h"

namespace mondengine {
    Shader::Shader(const char* fShaderFile, const char* vShaderFile)
    {
        MEcstr fShaderString = file::read_file(fShaderFile);
        MEcstr vShaderString = file::read_file(vShaderFile);

    }
}