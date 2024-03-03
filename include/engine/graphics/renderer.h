//
// Created by MondGnu on 2/29/2024.
//

#ifndef NINDO_RENDERER_H
#define NINDO_RENDERER_H

#include "engine/shader.h"
#include "library.h"
#include "vao.h"
#include "engine/texture.h"

namespace mondengine{
    using namespace graphics;
    class SpriteRenderer {
    public:
        MOND_API explicit SpriteRenderer(Shader &shader);
        MOND_API void DrawSprite(Texture2D texture, glm::vec2 position, glm::vec2 size, float rotation = 0.0f, glm::vec3 color = glm::vec3(1.0f));
    private:
        Shader& m_Shader;
        VAO m_Vao;
    };

class Renderer {
    public:
        explicit Renderer(Shader &shader) : shader(shader) {}

        void SetModel(glm::mat4 model) const
        {
            shader.SetMat4("model", model);
        }

        void SetColor(glm::vec3 color) const
        {
            shader.SetVector3f("color", color);
        }
        void SetUseTexture(bool b) const{
            shader.SetBool("useTexture", b);
        }
    protected:
        Shader& shader;
    };

} // graphics
// mondgnu

#endif //NINDO_RENDERER_H
