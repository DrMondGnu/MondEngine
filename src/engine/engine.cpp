//
// Created by MondGnu on 2/16/2024.
//


#include "engine/engine.h"

namespace mondengine {
    Engine::Engine()
    {
        init();
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
//        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

//        glEnable(GL_DEPTH_TEST);
        if (m_Window == nullptr)
        {
            MOE_ERROR("Cannot enter engine loop: Window not initialized!");
            return;
        }
        mondengine::Shader shader("resources/shader/default.frag", "resources/shader/default.vert");

        GL_CHECK_ERROR();
        //vao->AddAttribPointer(3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)), vbo);

        auto projection = glm::ortho(0.0f, 1280.0f, 780.0f, 0.0f, -1.0f, 1.0f);


        shader.SetMat4("projection", projection);
        shader.bind();


        Renderer renderer(shader);
        double previous = CURRENT_TIME_MILLIS();
        double lag = 0.0f;
        long ticks = 0;
        while (!m_Window->ShouldClose())
        {
            double current = CURRENT_TIME_MILLIS();
            double elapsed = current - previous;
            previous = current;
            lag += elapsed;

            process_input();

            while(lag >= MS_PER_UPDATE) {
                tick();
                ticks++;
                lag -= MS_PER_UPDATE;
            }

            render(renderer, lag / MS_PER_UPDATE);
        }

        glfwTerminate();
    }

    void Engine::OnEvent(Event &event)
    {
        MOE_INFO("Event: {0}", event);
        m_eventHandler.Dispatch(event);
    }


    void Engine::process_input()
    {

    }
    double last_second = 0;
    double tick_rate = 0;
    void Engine::tick()
    {
        if(last_second+1000 <= CURRENT_TIME_MILLIS()) {
            last_second = CURRENT_TIME_MILLIS();
            MOE_TRACE("Tick rate: {}", tick_rate);
            tick_rate = 0;
        }
        tick_rate++;
        m_TickHandler.Tick();
    }

    void Engine::render(Renderer renderer, float lag)
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        m_RenderHandler.Render(renderer, lag);

        m_Window->OnUpdate();
    }

    void Engine::AddTickObject(ITickObject *object)
    {
        m_TickHandler.Add(object);
    }

    void Engine::AddRenderObject(IRenderObject *object)
    {
        m_RenderHandler.Add(object);
    }

    void Engine::AddGameObject(IGameObject *object)
    {
        AddTickObject(object);
        AddRenderObject(object);
    }

    void Engine::Start()
    {
        wait_for_exit_loop();
    }


} // mondengine