//
// Created by MondGnu on 4/27/2024.
//

#ifndef MONDENGINE_PLATFORM_H
#define MONDENGINE_PLATFORM_H

#include "window.h"
#include "platform/windows/windows_window.h"

using namespace Mond;
namespace Mond {
    Window* MakeWindow(const WindowProperties& properties);

    template <typename T>
    struct PlatformCreator {
        virtual ~PlatformCreator() = 0;
    };

    template <typename T>
    T MakePlatformIndependent() {
        PlatformCreator<T> creator;
        return creator.Create();
    }

} // Mond

#endif //MONDENGINE_PLATFORM_H

