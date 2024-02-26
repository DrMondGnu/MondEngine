//
// Created by MondGnu on 2/16/2024.
//

#include "engine/init.h"

namespace mondengine {
    int init_engine()
    {
        MOE_TRACE("Initializing engine");
        glewExperimental = true; // Needed for core profile
        if( !glfwInit() )
        {
            MOE_ERROR("Failed to initialize GLFW\n" );
            return -1;
        }

        glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWwindow* window;
        window = glfwCreateWindow(1024, 768, "MondEngine", nullptr, nullptr);
        if(window == nullptr) {
            MOE_ERROR("Failed to open GLFW window.");
            glfwTerminate();
            return -1;
        }

        glfwMakeContextCurrent(window);
        glewExperimental = true;
        if(glewInit() != GLEW_OK) {
            MOE_ERROR("Failed to initialize GLFW");
            return -1;
        }
        return 0;
    }


} // mondengine