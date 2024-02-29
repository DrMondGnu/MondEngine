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

        double previous = CURRENT_TIME_MILLIS();
        double lag = 0.0f;
        while (!m_Window->ShouldClose())
        {
            double current = CURRENT_TIME_MILLIS();
            double elapsed = current - previous;
            previous = current;
            lag += elapsed;

            process_input();

            while(lag >= MS_PER_UPDATE) {
                tick();
                lag -= MS_PER_UPDATE;
            }
            render(lag / MS_PER_UPDATE);
        }

        glfwTerminate();
    }

    void Engine::OnEvent(Event &event)
    {
        MOE_INFO("Event: {0}", event);
    }


    void Engine::process_input()
    {

    }

    void Engine::tick()
    {

    }

    void Engine::render(float lag)
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_Window->OnUpdate();
    }

} // mondengine