//
// Created by MondGnu on 5/1/2024.
//

#include "engine/Graphics/Shapes/Rectangle.h"

namespace Mond::Graphics {
    void Rectangle::Draw() const
    {
        Vao->Bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        Vao->Unbind();
    }

    void Rectangle::initVao()
    {
        Vao = PlatformCreator<VertexArray*>().Create();
        float vertices[] = {
                // first triangle
                0.5f,  0.5f, 0.0f,  // top right
                0.5f, -0.5f, 0.0f,  // bottom right
                -0.5f,  0.5f, 0.0f,  // top left
                // second triangle
                0.5f, -0.5f, 0.0f,  // bottom right
                -0.5f, -0.5f, 0.0f,  // bottom left
                -0.5f,  0.5f, 0.0f   // top left
        };
        // TODO: make usage abstract
        VertexBufferLayout layout{};
        layout.size = 3;
        layout.type = GL_FLOAT;
        layout.normalized = false;
        layout.stride = 3 * sizeof(float);
        VertexBuffer* vbo = PlatformCreator<VertexBuffer*>() // TODO: think about deletion
                .Create(sizeof(vertices), vertices, Graphics::OpenGL::OpenGLBufferInfo::STATIC_DRAW, layout);
        Vao->AddVertexBuffer(*vbo);

    }

    Rectangle::Rectangle() {
        if(!Vao)
            initVao();
    }


}
