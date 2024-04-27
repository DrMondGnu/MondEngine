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
#include "graphics/vao.h"
#include "shader.h"
#include "util/opengl.h"
#include "window.h"
#include "platform/windows/windows_window.h"
#include "game_object.h"


#include <engine/graphics/cube.h>
#include <engine/shapes/shape.h>
#include <engine/shapes/rectangle.h>

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



        MOND_API void AddTickObject(ITickObject *object);

        MOND_API void AddRenderObject(IRenderObject *object);

        MOND_API void AddGameObject(IGameObject *object);

    private:
        void wait_for_exit_loop();
        void process_input();
        void tick();
        void render(Renderer renderer, float lag);


        TickObjectHandler m_TickHandler;
        RenderObjectHandler m_RenderHandler;
        Window *m_Window = nullptr;
        EventNode m_eventNode;
    };

} // mondengine

#endif //MONDENGINE_ENGINE_H
