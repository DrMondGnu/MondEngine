//
// Created by MondGnu on 2/24/2024.
//

#ifndef NINDO_VAO_H
#define NINDO_VAO_H

#include <GL/glew.h>


namespace mondengine::graphics {

    class VAO {
    public:
        explicit VAO(GLfloat *vertices, GLsizeiptr size);
        void draw();

    private:
        GLuint m_ID;
        GLuint m_vertexbuffer;
    };

} // graphics
// mondengine

#endif //NINDO_VAO_H
