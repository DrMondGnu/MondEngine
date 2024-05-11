//
// Created by MondGnu on 5/11/2024.
//

#ifndef MONDENGINE_PLATFORMUTILS_H
#define MONDENGINE_PLATFORMUTILS_H

#include "window.h"
#include "Platform/windows/windows_window.h"

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
#endif //MONDENGINE_PLATFORMUTILS_H
