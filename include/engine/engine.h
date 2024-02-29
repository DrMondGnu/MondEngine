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
#include "util/opengl.h"
#include "window.h"
#include "event/event.h"
#include "platform/windows/windows_window.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace mondengine {
    class Engine {
    public:
        MOND_API Engine();
        int init();
        void OnEvent(Event& event);
    private:
        void wait_for_exit_loop();
        Window* m_Window = nullptr;
    };

} // mondengine

#endif //MONDENGINE_ENGINE_H
