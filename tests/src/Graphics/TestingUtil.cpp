//
// Created by MondGnu on 5/11/2024.
//
#include "doctest.h"
#include "Engine/Shader/DrawableShader.h"
#include "Engine/Shader/ShaderCompiler.h"

using namespace Mond;
class TestShader : public DrawableShader {
public:
    TestShader() {
        if(!ShaderID)
            LoadShader();
    }

    const GLuint& GetId() const
    {
        return ShaderID;
    }

    void SetModelMatrix(const glm::mat4 &model) const
    {
        SetMat4("model", model);
    }

    void SetColor(const glm::vec4 &color) const
    {
        SetVector4f("color", color);
    }
    static void LoadShader()
    {
        const char* frag = "#version 430 core\n"
                           "\n"
                           "in vec2 TexCoords;\n"
                           "out vec4 outColor;\n"
                           "\n"
                           "uniform vec4 color;\n"
                           "\n"
                           "void main() {\n"
                           "        outColor = color;\n"
                           "}";
        const char* vert = "#version 430 core\n"
                           "\n"
                           "layout(location = 0) in vec2 vertex;\n"
                           "\n"
                           "uniform mat4 model;\n"
                           "uniform mat4 projection;\n"
                           "\n"
                           "void main() {\n"
                           "    gl_Position = projection * model * vec4(vertex.xy, 0.0f, 1.0f);\n"
                           "}";
        ShaderCompiler compiler;
        ShaderID = compiler.Compile(vert, frag);
    }

private:
    inline static GLuint ShaderID = 0;
};