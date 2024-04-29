//
// Created by MondGnu on 2/16/2024.
//

#ifndef MONDENGINE_ENGINE_H
#define MONDENGINE_ENGINE_H

#include <EventNode.h>
#include "event/KeyEvent.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "log.h"
#include "engine/graphics/Core/vao.h"
#include "engine/Shader/Shader.h"
#include "util/opengl.h"
#include "window.h"
#include "platform/windows/windows_window.h"
#include "TickObject.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#define CURRENT_TIME_MILLIS() std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()
#define MS_PER_UPDATE (1000.0 / 60.0)

namespace mondengine {
    class Engine {
    public:
        MOND_API Engine();

        int init();

        MOND_API void Start();

        void OnEvent(Event &event);



        MOND_API void AddTickObject(TickObject *object);


    private:



        TickObjectHandler m_TickHandler;
        Window *m_Window = nullptr;
        EventNode m_eventNode;
    };

} // mondengine

#endif //MONDENGINE_ENGINE_H
