//
// Created by MondGnu on 2/29/2024.
//

#ifndef NINDO_RENDERER_H
#define NINDO_RENDERER_H

#include "engine/shader.h"
#include "library.h"
#include "vao.h"
#include "engine/texture.h"
#include "engine/game_object.h"

namespace mondengine::graphics {

    class SpriteRenderer {
    public:
        MOND_API explicit SpriteRenderer(Shader &shader);
        MOND_API void DrawSprite(Texture2D texture, glm::vec2 position, glm::vec2 size, float rotation = 0.0f, glm::vec3 color = glm::vec3(1.0f));
    private:
        Shader& m_Shader;
        VAO m_Vao;
    };

    template<typename R>
    class Renderer {
    public:
        explicit Renderer(Shader &shader) : shader(shader) {}
        virtual void Render(R& r) = 0;
    protected:
        void setModel(glm::mat4 model) const
        {
            shader.SetMat4("model", model);
        }

        void setColor(glm::vec3 color) const
        {
            shader.SetVector3f("color", color);
        }
        void setUseTexture(bool b) const{
            shader.SetBool("useTexture", b);
        }
        Shader& shader;
    };

} // graphics
// mondgnu

#endif //NINDO_RENDERER_H
