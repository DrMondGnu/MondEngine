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
    public:
        MOND_API Shader(const char* fShaderFile, const char* vShaderFile);
        GLuint ID;
    };
}
#endif //MONDENGINE_SHADER_H
