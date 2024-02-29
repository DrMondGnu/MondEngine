//
// Created by MondGnu on 2/29/2024.
//

#ifndef NINDO_WINDOWS_WINDOW_H
#define NINDO_WINDOWS_WINDOW_H

#include "engine/window.h"
#include "engine/log.h"

namespace mondengine {

    class WindowsWindow : public Window{
    public:

        explicit WindowsWindow(WindowProperties& properties);

        void OnUpdate() override;
        void ShutDown() override;
        bool ShouldClose() override;
        void SetEventCallback(EventCallbackFn callbackFn) override;
    private:
        void Init(WindowProperties& properties);

        GLFWwindow* m_Window;
        struct WindowData
        {
            EventCallbackFn eventCallback;
        };
        WindowData m_Data;
    };

} // mondengine

#endif //NINDO_WINDOWS_WINDOW_H
