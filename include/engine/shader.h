//
// Created by MondGnu on 2/21/2024.
//

#ifndef MONDENGINE_SHADER_H
#define MONDENGINE_SHADER_H

#include "GL/glew.h"
#include "library.h"
#include "util/file.h"
#include "glid.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace mondengine {
    class Shader : GLID {
    public:
        MOND_API Shader(const char* fShaderFile, const char* vShaderFile);

        void bind() override;
        void unbind() override;

        void setMat4(const char* name, glm::mat4 mat);
    };
}
#endif //MONDENGINE_SHADER_H
