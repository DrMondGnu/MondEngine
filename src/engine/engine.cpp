//
// Created by MondGnu on 2/16/2024.
//

#include <engine/graphics/cube.h>
#include "engine/engine.h"

namespace mondengine {
    Engine::Engine()
    {
        init();
        wait_for_exit_loop();
    }

    int Engine::init()
    {
        MOE_TRACE("Initializing engine");
        WindowProperties properties;
        properties.title = "MondEngine";
        properties.width = 1280;
        properties.height = 780;
        properties.vsync = true;
        m_Window = new WindowsWindow(properties);
        m_Window->SetEventCallback(std::bind(&Engine::OnEvent, this, std::placeholders::_1));
        return 0;
    }

    float vertices[] = {
            // positions
            -0.5f, -0.5f, -0.5f, // Front-Bottom-Left 0
            0.5f, -0.5f, -0.5f, // Front-Bottom-Right 1
            0.5f,  0.5f, -0.5f, // Front-Top-Right 2
            -0.5f,  0.5f, -0.5f, // Front-Top-Left 3

            -0.5f, -0.5f, 0.5f, // Back-Bottom-Left 4
            0.5f, -0.5f, 0.5f, // Back-Bottom-Right 5
            0.5f,  0.5f, 0.5f, // Back-Top-Right 6
            -0.5f,  0.5f, 0.5f, // Back-Top-Left 7
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

    void Engine::wait_for_exit_loop()
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        if (m_Window == nullptr)
        {
            MOE_ERROR("Cannot enter engine loop: Window not initialized!");
            return;
        }
        mondengine::Shader shader("resources/shader/default.frag", "resources/shader/default.vert");
        graphics::Cube cube(1.0f);
        GL_CHECK_ERROR();
        //vao->AddAttribPointer(3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)), vbo);

        auto model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, -4.0f));

        model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        auto view = glm::mat4(1.0f);
        view = glm::translate(view ,glm::vec3(0.0f, 0.0f, -3.0f));
        auto projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);


        shader.setMat4("model", model);
        shader.setMat4("view", view);
        shader.setMat4("projection", projection);

        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::rotate(trans, glm::radians(90.f), glm::vec3(0.0, 0.0, 1.0));
        trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));

        while (!m_Window->ShouldClose())
        {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            shader.bind();
//            shader.setMat4("transform", trans);
            cube.Draw();
            m_Window->OnUpdate();
        }

        glfwTerminate();
    }

    void Engine::OnEvent(Event &event)
    {
        MOE_INFO("Event: {0}", event);
    }
} // mondengine