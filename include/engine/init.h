//
// Created by MondGnu on 2/16/2024.
//

#ifndef MONDENGINE_INIT_H
#define MONDENGINE_INIT_H

#include "log.h"
#include <GL/glew.h>
#include <SDL.h>

namespace mondengine {

    SDL_Window* init_window(const char *title, int x, int y, int w, int h, uint32_t flags);
    SDL_GLContext init_glew(SDL_Window* window, int major, int minor, bool glew_experimental);

} // mondengine

#endif //MONDENGINE_INIT_H
