//
// Created by MondGnu on 4/27/2024.
//

#ifndef MONDENGINE_PLATFORM_H
#define MONDENGINE_PLATFORM_H

#include "window.h"
#include "platform/windows/windows_window.h"

namespace mondengine {
    Window* MakeWindow(const WindowProperties& properties);
} // mondengine

#endif //MONDENGINE_PLATFORM_H

