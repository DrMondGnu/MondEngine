//
// Created by MondGnu on 2/29/2024.
//

#include "engine/graphics/cube.h"


namespace mondengine::graphics {
    
    Cube::Cube(float size)
    {
        if(ms_Vao == nullptr) {
            init_cube_vao();
        }
        m_Vao = ms_Vao;
    }

    void Cube::Draw()
    {
        m_Vao->DrawEBO(36, GL_UNSIGNED_INT, 0);
    }

    VAO* Cube::ms_Vao = nullptr;

    void Cube::init_cube_vao()
    {
        float vertices[] = {
                // positions
                -1.0f, -1.0f, -1.0f, // Front-Bottom-Left 0
                1.0f, -1.0f, -1.0f, // Front-Bottom-Right 1
                1.0f, 1.0f, -1.0f, // Front-Top-Right 2
                -1.0f, 1.0f, -1.0f, // Front-Top-Left 3

                -1.0f, -1.0f, 1.0f, // Back-Bottom-Left 4
                1.0f, -1.0f, 1.0f, // Back-Bottom-Right 5
                1.0f, 1.0f, 1.0f, // Back-Top-Right 6
                -1.0f, 1.0f, 1.0f, // Back-Top-Left 7
        };
        int indices[] = {
                1, 0, 3, // Front-T-Bottom-Left
                1, 2, 3, // Front-T-Top-Right

                0, 4, 7, // Left-T-Bottom-Left
                0, 3, 7, // Left-T-Top-Right

                2, 1, 5, // Right-T-Bottom-Left
                2, 6, 5, // Right-T-Top-Right

                2, 3, 7, // Top-T-Bottom-Left
                2, 6, 7, // Top-T-Top-Right

                1, 0, 4, // Bottom-T-Bottom-Left
                1, 5, 4, // Bottom-T-Top-Right

                5, 4, 7, // Back-T-Bottom-Left
                5, 6, 7, // Back-T-Top-Right
        };
        VBO vbo(vertices, sizeof(vertices));
        EBO ebo(indices, sizeof(indices));
        ms_Vao = new VAO();
        ms_Vao->AddAttribPointer(3, GL_FLOAT, GL_FALSE, 3 * sizeof (float), 0, vbo);
        ms_Vao->SetEBO(ebo);
    }
} // graphics
// mondengine