//
// Created by MondGnu on 2/16/2024.
//


#include "engine/engine.h"

namespace mondengine {
    Engine::Engine()
    {
        init();
    }

    int Engine::init() // Init window usw
    {
        MOE_TRACE("Initializing engine");
        WindowProperties properties;
        properties.title = "MondEngine";
        properties.width = 1366;
        properties.height = 768;
        properties.vsync = true;
        m_Window = new WindowsWindow(properties);
        m_Window->SetEventCallback(std::bind(&Engine::OnEvent, this, std::placeholders::_1));
        return 0;
    }



    void Engine::wait_for_exit_loop() // current function which handles loops
    {
        if (m_Window == nullptr)
        {
            MOE_ERROR("Cannot enter engine loop: Window not initialized!");
            return;
        }
        mondengine::Shader shader("resources/shader/default.frag", "resources/shader/default.vert");
        GL_CHECK_ERROR();

        // Projection mat for 2d rendering
        auto projection = glm::ortho(0.0f, 1366.0f, 768.0f, 0.0f, -1.0f, 1.0f);
        shader.SetMat4("projection", projection);
        shader.bind();

        // Renderer for render function
        Renderer renderer(shader);


        double previous = CURRENT_TIME_MILLIS(); // Time when last frame started
        double lag = 0.0f; // the current "lag" how much time is still left after doing ticks
        long ticks = 0; // ticks passed
        while (!m_Window->ShouldClose())
        {
            double current = CURRENT_TIME_MILLIS(); // Get current time
            double elapsed = current - previous; // Calculate elapsed time since last frame

            previous = current;
            lag += elapsed;

            // Fetch glfw inputs usw
            process_input();

            // Tick every object with a rate of 60 per second
            while(lag >= MS_PER_UPDATE) {
                tick();
                ticks++;
                lag -= MS_PER_UPDATE;
            }

            // render objects
            render(renderer, lag / MS_PER_UPDATE);
        }

        glfwTerminate();
    }

    /*
     * On event callback for window
     */
    void Engine::OnEvent(Event &event)
    {
        MOE_INFO("Event: {0}", event);
        if(event.GetEventCategory() == EventCategoryKeyboard) {
            auto& keyEvent = (KeyEvent&)event;
            auto action = keyEvent.GetAction();
            switch (action) {
                case GLFW_PRESS:
                    m_keys.insert((KeyPressedEvent)keyEvent);
                    break;
                case GLFW_RELEASE:
                    m_keys.erase((KeyPressedEvent)  keyEvent);
                    break;
                case GLFW_REPEAT:
                    return;
                    break;
                default:
                    break;
            }

        }
        m_eventManager.Dispatch(event);
    }

    /*
     *  Handle input stuff
     */
    void Engine::process_input()
    {
        m_Window->FetchInput();
        for (const auto &item: m_keys) {
            m_eventManager.Dispatch(item);
        }
    }


    double last_second = 0;
    double tick_rate = 0;
    /**
     *  tick each object usw
     */
    void Engine::tick()
    {
        // Prints tick rate
        if(last_second+1000 <= CURRENT_TIME_MILLIS()) {
            last_second = CURRENT_TIME_MILLIS();
            MOE_TRACE("Tick rate: {}", tick_rate);
            GL_CHECK_ERROR();
            tick_rate = 0;
        }
        tick_rate++;
        m_TickHandler.Tick();
    }

    /**
     * Render every object clear buffers, color and render window
     * @param renderer
     * @param lag
     */
    void Engine::render(Renderer renderer, float lag)
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

//        Testing
//        Rectangle rectangle(glm::vec2(last, 200.0f), glm::vec2(40.0f, 40.0f), 0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
//        rectangle.Render(renderer, lag);

        m_RenderHandler.Render(renderer, lag);

        m_Window->OnRender();

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