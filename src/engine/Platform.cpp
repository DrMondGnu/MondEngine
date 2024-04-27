//
// Created by MondGnu on 4/27/2024.
//
#include "../../include/engine/Platform.h"

namespace mondengine {
#ifdef _WIN32
    Window* MakeWindow(const WindowProperties& properties) {
        return new WindowsWindow(properties);
    }
#endif
}