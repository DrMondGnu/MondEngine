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

        explicit WindowsWindow(const WindowProperties& properties);

        void SetVisibility(bool visibility) override;

        void FetchInput() override;
        void ShutDown() override;
        bool ShouldClose() override;

        void OnRender() override;

        void SetEventCallback(EventCallbackFn callbackFn) override;
    private:
        void Init(const WindowProperties& properties);

        GLFWwindow* m_Window;
        struct WindowData
        {
            EventCallbackFn eventCallback;
        };
        WindowData m_Data;
    };

} // mondengine

#endif //NINDO_WINDOWS_WINDOW_H
