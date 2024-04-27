//
// Created by MondGnu on 4/27/2024.
//
#include "../doctest.h"
#include "engine/Platform.h"

using namespace mondengine;

TEST_CASE("MakeWindow") {
#ifdef _WIN32
    WindowProperties properties{"TestWindow" , 600, 600, false, false};
    Window* window = MakeWindow(properties);
    CHECK_EQ(typeid(WindowsWindow), typeid(*window));
#endif
}