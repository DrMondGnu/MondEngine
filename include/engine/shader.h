//
// Created by MondGnu on 2/21/2024.
//

#ifndef MONDENGINE_SHADER_H
#define MONDENGINE_SHADER_H

#include "GL/glew.h"
#include "library.h"
#include "util/file.h"

namespace mondengine {
    class Shader {
        ME_SHADER_ID ID;
        public:
            Shader(const char* fShaderFile, const char* vShaderFile);
    };
}
#endif //MONDENGINE_SHADER_H
