//
// Created by MondGnu on 2/29/2024.
//

#ifndef NINDO_WINDOW_H
#define NINDO_WINDOW_H

#include <Event.h>

namespace mondengine {
    struct WindowProperties {
        std::string title;
        unsigned int width, height;
        bool visible;
        bool vsync;
    };
    class Window {
    public:
        using EventCallbackFn = std::function<void(Event &)>;
        virtual ~Window() = default;

        virtual void SetVisibility(bool visibility) = 0;
        virtual void FetchInput() = 0;
        virtual void OnRender() = 0;
        virtual void ShutDown() = 0;
        virtual bool ShouldClose() = 0;
        virtual void SetEventCallback(EventCallbackFn callbackFn) = 0;
        // TODO: Vsync
    private:

    };

} // mondengine

#endif //NINDO_WINDOW_H
