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
        m_Window->SetEventCallback([this](auto && PH1) { OnEvent(std::forward<decltype(PH1)>(PH1)); });
        return 0;
    }

    /*
     * On event callback for window
     */
    void Engine::OnEvent(Event &event)
    {
        MOE_INFO("Event: {0}", event.GetType());
    }



} // mondengine