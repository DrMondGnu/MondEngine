//
// Created by MondGnu on 2/29/2024.
//

#include "platform/windows/windows_window.h"
#include "engine/event/key_event.h"

namespace mondengine {
    void WindowsWindow::SetEventCallback(Window::EventCallbackFn callbackFn)
    {
        m_Data.eventCallback = callbackFn;
    }

    WindowsWindow::WindowsWindow(WindowProperties &properties)
    {
        Init(properties);
    }

    void WindowsWindow::ShutDown()
    {
        glfwDestroyWindow(m_Window);
    }

    void WindowsWindow::Init(WindowProperties &properties)
    {
        MOE_TRACE("Creating window {0} ({1}, {2}", properties.title, properties.width, properties.height);
        glewExperimental = true; // Needed for core profile
        if (!glfwInit())
        {
            MOE_ERROR("Failed to initialize GLFW");
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // OpenGL 3.3
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_Window = glfwCreateWindow((int) properties.width, (int) properties.height, properties.title.c_str(), nullptr,
                                    nullptr);
        if (m_Window == nullptr)
        {
            MOE_ERROR("Failed to open GLFW window.");
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_Window);
        glewExperimental = true;
        if (glewInit() != GLEW_OK)
        {
            MOE_ERROR("Failed to initialize GLFW");
            return;
        }
        glfwSetWindowUserPointer(m_Window, &m_Data);
//        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
//        {
//
//        })

        glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData*) glfwGetWindowUserPointer(window);

            if(action == GLFW_PRESS)
            {
                KeyDownEvent event(key, scancode, mods);
                data.eventCallback(event);
            }else if(action == GLFW_RELEASE)
            {
                KeyUpEvent event(key, scancode, mods);
                data.eventCallback(event);
            } else if(action == GLFW_REPEAT)
            {
                KeyPressedEvent event(key, scancode, mods);
                data.eventCallback(event);
            }

        });
    }

    bool WindowsWindow::ShouldClose()
    {
        return glfwWindowShouldClose(m_Window);
    }

    void WindowsWindow::OnRender()
    {
        glfwSwapBuffers(m_Window);
    }
    void WindowsWindow::FetchInput()
    {
        glfwPollEvents();
    }

} // mondengine