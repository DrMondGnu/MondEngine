//
// Created by MondGnu on 2/29/2024.
//

#ifndef NINDO_RENDERER_H
#define NINDO_RENDERER_H

#include "engine/shader.h"
#include "library.h"
#include "vao.h"
#include "engine/texture.h"

namespace mondengine::graphics {

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
        explicit Renderer(Shader *shader);
        MOND_API void SetPos(glm::mat4& mat);
        MOND_API Shader* GetShader();
    private:
        Shader* m_Shader;
    };

} // graphics
// mondgnu

#endif //NINDO_RENDERER_H
