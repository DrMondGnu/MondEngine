//
// Created by MondGnu on 2/16/2024.
//

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
            // positions         // colors
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,   // bottom left
            0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // top
    };

    void Engine::wait_for_exit_loop()
    {
        if (m_Window == nullptr)
        {
            MOE_ERROR("Cannot enter engine loop: Window not initialized!");
            return;
        }
        mondengine::Shader shader("resources/shader/default.frag", "resources/shader/default.vert");
        auto *vao = new mondengine::graphics::VAO();
        auto *vbo = new mondengine::graphics::VBO(vertices, sizeof(vertices));
        vao->add_vbo(3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0, vbo);
        vao->add_vbo(3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)), vbo);

        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::rotate(trans, glm::radians(90.f), glm::vec3(0.0, 0.0, 1.0));
        trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));

        while (!m_Window->ShouldClose())
        {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            shader.bind();
            shader.setMat4("transform", trans);
            vao->draw();
            m_Window->OnUpdate();
        }

        glfwTerminate();
    }

    void Engine::OnEvent(Event &event)
    {
        MOE_INFO("Event: {0}", event);
    }
} // mondengine