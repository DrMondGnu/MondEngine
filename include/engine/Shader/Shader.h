//
// Created by MondGnu on 2/21/2024.
//

#ifndef MONDENGINE_SHADER_H
#define MONDENGINE_SHADER_H

#include "GL/glew.h"
#include "library.h"
#include "util/file.h"

#include "util/opengl.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


namespace mondengine {
    class Shader {
    public:
        Shader();

        void Bind() const;
        void Unbind() const;

        [[nodiscard]] virtual const GLuint& GetId() const = 0;

        virtual void SetMat4(const char* name, const glm::mat4& mat) const;
        virtual void SetVector3f(const char* name, const glm::vec3 &vec) const;
        virtual void SetVector4f(const char* name, const glm::vec4 &vec) const;
        virtual void SetBool(const char* name, const bool &b) const;
    protected:
    };
}
#endif //MONDENGINE_SHADER_H
