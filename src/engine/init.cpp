//
// Created by MondGnu on 2/16/2024.
//

#include "engine/init.h"

namespace mondengine {
    SDL_Window *init_window(const char *title, int x, int y, int w, int h, uint32_t flags)
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            MOE_ERROR("SDL could not initialize! SDL Error: {}", SDL_GetError());
            return nullptr;
        }
        SDL_Window *window = SDL_CreateWindow(title, x, y, w, h, flags);
        if (window == nullptr)
        {
            MOE_ERROR("Window could not be created! SDL Error: {}", SDL_GetError());
            SDL_Quit();
            return nullptr;
        }
        return window;
    }

    SDL_GLContext init_glew(SDL_Window *window, int major, int minor, bool glew_experimental)
    {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major); // Tell SDL Which GL version we are working with
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        SDL_GLContext ctx = SDL_GL_CreateContext(window); // Bind SDL window to gl
        glewExperimental = glew_experimental;

        // Init GL
        GLenum glew_status = glewInit();
        if (glew_status != GLEW_OK)
        {
            MOE_ERROR("Error initializing glew: {}", *glewGetErrorString(glew_status));
            return nullptr;
        }
        return ctx;
    }


} // mondengine