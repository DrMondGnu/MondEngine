//
// Created by MondGnu on 2/29/2024.
//

#include "engine/graphics/renderer.h"


namespace mondengine::graphics {

    void Renderer::SetPos(glm::mat4 &mat)
    {
        m_Shader->SetMat4("model", mat);
    }

    Renderer::Renderer(Shader *shader) : m_Shader(shader) {}

    Shader *Renderer::GetShader()
    {
        return m_Shader;
    }

    SpriteRenderer::SpriteRenderer(Shader &shader) : m_Shader(shader)
    {
        float vertices[] = {
                // pos      // tex
                0.0f, 1.0f, 0.0f, 1.0f,
                1.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 0.0f, 0.0f,

                0.0f, 1.0f, 0.0f, 1.0f,
                1.0f, 1.0f, 1.0f, 1.0f,
                1.0f, 0.0f, 1.0f, 0.0f
        };
        m_Vao = VAO();
        VBO vbo(vertices, sizeof(vertices));
        m_Vao.AddAttribPointer(4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr, vbo);
    }



    void SpriteRenderer::DrawSprite(Texture2D texture, glm::vec2 position, glm::vec2 size, float rotation, glm::vec3 color)
    {
//        MOE_TRACE("Drawing Sprite: (position: {}, {}; size: {}, {})", position.x, position.y, size.x, size.y);
        m_Shader.bind();
        auto model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(position, 0.0f));

        model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
        model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

        model = glm::scale(model, glm::vec3(size, 1.0f));

        m_Shader.SetMat4("model", model);
        m_Shader.SetVector3f("spriteColor", color);

       glActiveTexture(GL_TEXTURE0);
       texture.bind();

        m_Vao.draw(0, 6);
        m_Vao.unbind();
    }
} // graphics
// mondgnu