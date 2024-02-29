//
// Created by MondGnu on 2/29/2024.
//

#include "engine/graphics/cube.h"

namespace mondengine {
    namespace graphics {
   
        Cube::Cube(float size) : m_Vao(VAO())
        {
            float vertices[] = {
                    // positions
                    -size, -size, -size, // Front-Bottom-Left 0
                    size, -size, -size, // Front-Bottom-Right 1
                    size,  size, -size, // Front-Top-Right 2
                    -size,  size, -size, // Front-Top-Left 3

                    -size, -size, size, // Back-Bottom-Left 4
                    size, -size, size, // Back-Bottom-Right 5
                    size,  size, size, // Back-Top-Right 6
                    -size,  size, size, // Back-Top-Left 7
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
            m_Vao.AddAttribPointer(3, GL_FLOAT, GL_FALSE, 3*sizeof(float), 0, vbo);
            m_Vao.SetEBO(ebo);
        }

        void Cube::Draw()
        {
            m_Vao.DrawEBO(36, GL_UNSIGNED_INT, 0);
        }
    } // graphics
} // mondengine