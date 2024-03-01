//
// Created by MondGnu on 2/21/2024.
//

#ifndef MONDENGINE_SHADER_H
#define MONDENGINE_SHADER_H

#include "GL/glew.h"
#include "library.h"
#include "util/file.h"
#include "glid.h"
#include "util/opengl.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace mondengine {
    class Shader : public GLID {
    public:
        MOND_API Shader(const char* fShaderFile, const char* vShaderFile);

        void bind() override;
        void unbind() override;

        MOND_API void SetMat4(const char* name, glm::mat4& mat);
        MOND_API void SetVector3f(const char* name, glm::vec3 vec);
    };
}
#endif //MONDENGINE_SHADER_H
