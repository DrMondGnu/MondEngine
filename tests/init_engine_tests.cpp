//
// Created by MondGnu on 2/16/2024.
//
#include "gtest/gtest.h"
#include "engine/init.h"

TEST(InitWindowTest, HandlesNullptr)
{
    ASSERT_TRUE(mondengine::init_window("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 20, 20, SDL_WINDOW_OPENGL) != nullptr);
}


TEST(InitGlewTest, HandleNullptr)
{
    SDL_Window* window = mondengine::init_window("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 20, 20, SDL_WINDOW_OPENGL);
    ASSERT_TRUE(mondengine::init_glew(window, 4, 3, false) != nullptr);
}
