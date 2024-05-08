//
// Created by MondGnu on 2/21/2024.
//

#include "engine/Shader/Shader.h"

namespace Mond {

    void Shader::Bind() const
    {
        glUseProgram(GetId());
    }

    void Shader::Unbind() const
    {
        glUseProgram(0);
    }

    void Shader::SetMat4(const char * name, const glm::mat4& mat) const
    {
        // TODO: Bind shader
        GLuint loc = GL_CHECK_ERROR_FN(glGetUniformLocation(GetId(), name));
//        MOE_TRACE("Setting matrix4: (name: {}, location: {})", name, loc);
        GL_CHECK_ERROR_FN(glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mat)));
    }

    void Shader::SetVector3f(const char *name, const glm::vec3 &vec) const
    {
        GLuint loc = GL_CHECK_ERROR_FN(glGetUniformLocation(GetId(), name));
        GL_CHECK_ERROR_FN(glUniform3f(loc, vec.x, vec.y, vec.z));
    }

    void Shader::SetBool(const char *name, const bool &b) const
    {
        GLuint loc = GL_CHECK_ERROR_FN(glGetUniformLocation(GetId(), name));
        GL_CHECK_ERROR_FN(glUniform1i(loc, b));
    }

    Shader::Shader() = default;

    void Shader::SetVector4f(const char *name, const glm::vec4 &vec) const
    {
        GLuint loc = GL_CHECK_ERROR_FN(glGetUniformLocation(GetId(), name));
        GL_CHECK_ERROR_FN(glUniform4f(loc, vec.x, vec.y, vec.z, vec.w));
    }

}