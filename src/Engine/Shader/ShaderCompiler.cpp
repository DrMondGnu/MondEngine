//
// Created by MondGnu on 5/1/2024.
//

#include "engine/Shader/ShaderCompiler.h"

namespace Mond {
    GLuint ShaderCompiler::Compile(const std::string &vertex, const std::string &fragment)
    {
        GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

        GLint result = GL_FALSE;
        int infoLogLength;

        MOE_TRACE("Compiling vertex shader: {}", vertex);
        const char* c_str = vertex.c_str();
        glShaderSource(VertexShaderID, 1, &c_str, nullptr);
        glCompileShader(VertexShaderID);

        glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &result);
        glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
        if(infoLogLength > 0) {
            auto* msg = new GLchar[infoLogLength+1];
            glGetShaderInfoLog(VertexShaderID, infoLogLength, nullptr, &msg[0]);
            MOE_ERROR("Error compiling vertex shader: {}", msg);
            free(msg);
        }

        MOE_TRACE("Compiling fragment shader!");
        c_str = fragment.c_str();
        glShaderSource(FragmentShaderID, 1, &c_str, nullptr);
        glCompileShader(FragmentShaderID);

        glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &result);
        glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
        if(infoLogLength > 0) {
            auto* msg = new GLchar[infoLogLength+1];
            glGetShaderInfoLog(FragmentShaderID, infoLogLength, nullptr, &msg[0]);
            MOE_ERROR("Error compiling fragment shader: {}", msg);
            free(msg);
        }



        // Link shaders
        MOE_TRACE("Linking program");
        GLuint id = glCreateProgram();
        glAttachShader(id, VertexShaderID);
        glAttachShader(id, FragmentShaderID);
        glLinkProgram(id);

        // Check linking status
        glGetProgramiv(id, GL_LINK_STATUS, &result);
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &infoLogLength);
        if(infoLogLength > 0) {
            auto* msg = new GLchar[infoLogLength+1];
            glGetShaderInfoLog(VertexShaderID, infoLogLength, nullptr, &msg[0]);
            MOE_ERROR("Error linking programm: {}", msg);
            free(msg);
        }
        glDeleteShader(VertexShaderID);
        glDeleteShader(FragmentShaderID);
        return id;
    }
} // Mond