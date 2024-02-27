//
// Created by MondGnu on 2/16/2024.
//

#include "engine/engine.h"

namespace mondengine {
    Engine::Engine() : mp_window(nullptr)
    {
        init();
        wait_for_exit_loop();
    }

    int Engine::init()
    {
        MOE_TRACE("Initializing engine");
        glewExperimental = true; // Needed for core profile
        if (!glfwInit())
        {
            MOE_ERROR("Failed to initialize GLFW\n");
            return -1;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        mp_window = glfwCreateWindow(1024, 768, "MondEngine", nullptr, nullptr);
        if (mp_window == nullptr)
        {
            MOE_ERROR("Failed to open GLFW window.");
            glfwTerminate();
            return -1;
        }

        glfwMakeContextCurrent(mp_window);
        glewExperimental = true;
        if (glewInit() != GLEW_OK)
        {
            MOE_ERROR("Failed to initialize GLFW");
            return -1;
        }
        return 0;
    }

    float vertices[] = {
            // positions         // colors
            0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
            -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
            0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top
    };
    void Engine::wait_for_exit_loop()
    {
        if (mp_window == nullptr)
        {
            MOE_ERROR("Cannot enter engine loop: Window not initialized!");
            return;
        }
        mondengine::Shader shader("resources/shader/default.frag", "resources/shader/default.vert");
        auto* vao = new mondengine::graphics::VAO();
        auto* vbo = new mondengine::graphics::VBO(vertices, sizeof(vertices));
        vao->add_vbo(3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0, vbo);
        vao->add_vbo(3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)), vbo);

        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::rotate(trans, glm::radians(90.f), glm::vec3(0.0, 0.0, 1.0));
        trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));

        glfwSetInputMode(mp_window, GLFW_STICKY_KEYS, GL_TRUE);
        while (glfwGetKey(mp_window, GLFW_KEY_ESCAPE) != GLFW_PRESS
               && glfwWindowShouldClose(mp_window) == 0)
        {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            shader.bind();
            shader.setMat4("transform", trans);
            vao->draw();
            glfwSwapBuffers(mp_window);
            glfwPollEvents();
        }

        glfwTerminate();
    }
} // mondengine