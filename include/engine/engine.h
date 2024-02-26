//
// Created by MondGnu on 2/16/2024.
//

#ifndef MONDENGINE_ENGINE_H
#define MONDENGINE_ENGINE_H

#include "log.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "graphics/vao.h"
#include "shader.h"

namespace mondengine {
    class Engine {
    public:
        MOND_API Engine();
        int init();
    private:
        void wait_for_exit_loop();
        GLFWwindow* mp_window;
    };

} // mondengine

#endif //MONDENGINE_ENGINE_H
