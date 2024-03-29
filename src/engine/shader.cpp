//
// Created by MondGnu on 2/21/2024.
//

#include "engine/shader.h"

namespace mondengine {
    Shader::Shader(const char *fShaderFile, const char *vShaderFile)
    {
        GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

        const char* fShaderString = file::read_file(fShaderFile);
        if (fShaderFile == nullptr)
        {
            MOE_ERROR("Failed to load fragment shader");
            return;
        }
        const char* vShaderString = file::read_file(vShaderFile);
        if (vShaderString == nullptr)
        {
            MOE_ERROR("Failed to load vertex shader");
            return;
        }
        GLint result = GL_FALSE;
        int infoLogLength;

        MOE_TRACE("Compiling fragment shader: {}", fShaderFile);
        glShaderSource(FragmentShaderID, 1, &fShaderString, nullptr);
        glCompileShader(FragmentShaderID);

        glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &result);
        glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
        if(infoLogLength > 0) {
            auto* msg = new GLchar[infoLogLength+1];
            glGetShaderInfoLog(FragmentShaderID, infoLogLength, nullptr, &msg[0]);
            MOE_ERROR("Error compiling fragment shader: {}", msg);
            free(msg);
        }

        MOE_TRACE("Compiling vertex shader: {}", vShaderFile);
        glShaderSource(VertexShaderID, 1, &vShaderString, nullptr);
        glCompileShader(VertexShaderID);

        glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &result);
        glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
        if(infoLogLength > 0) {
            auto* msg = new GLchar[infoLogLength+1];
            glGetShaderInfoLog(VertexShaderID, infoLogLength, nullptr, &msg[0]);
            MOE_ERROR("Error compiling vertex shader: {}", msg);
            free(msg);
        }

        // Link shaders
        MOE_TRACE("Linking programm");
        m_id = glCreateProgram();
        glAttachShader(m_id, VertexShaderID);
        glAttachShader(m_id, FragmentShaderID);
        glLinkProgram(m_id);

        // Check linking status
        glGetProgramiv(m_id, GL_LINK_STATUS, &result);
        glGetProgramiv(m_id, GL_INFO_LOG_LENGTH, &infoLogLength);
        if(infoLogLength > 0) {
            auto* msg = new GLchar[infoLogLength+1];
            glGetShaderInfoLog(VertexShaderID, infoLogLength, nullptr, &msg[0]);
            MOE_ERROR("Error linking programm: {}", msg);
            free(msg);
        }
        glDeleteShader(VertexShaderID);
        glDeleteShader(FragmentShaderID);
    }

    void Shader::bind()
    {
        RETURN_IF_BOUND
        glUseProgram(m_id);
        m_bound = true;
    }

    void Shader::unbind()
    {
        RETURN_IF_NOT_BOUND
        glUseProgram(0);
        m_bound = false;
    }

    void Shader::SetMat4(const char * name, glm::mat4& mat)
    {
        BIND_IF_NOT
        GLuint loc = GL_CHECK_ERROR_FN(glGetUniformLocation(m_id, name));
//        MOE_TRACE("Setting matrix4: (name: {}, location: {})", name, loc);
        GL_CHECK_ERROR_FN(glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mat)));
    }

    void Shader::SetVector3f(const char *name, glm::vec3 vec)
    {
        BIND_IF_NOT
        GLuint loc = GL_CHECK_ERROR_FN(glGetUniformLocation(m_id, name));
        GL_CHECK_ERROR_FN(glUniform3f(loc, vec.x, vec.y, vec.z));
    }

    void Shader::SetBool(const char *name, bool b)
    {
        BIND_IF_NOT
        GLuint loc = GL_CHECK_ERROR_FN(glGetUniformLocation(m_id, name));
        GL_CHECK_ERROR_FN(glUniform1i(loc, b));
    }
}