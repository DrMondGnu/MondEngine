//
// Created by MondGnu on 2/26/2024.
//

#ifndef NINDO_GLID_H
#define NINDO_GLID_H

#include <GL/glew.h>

namespace mondengine {

    class GLID {
    public:
        explicit GLID();
        virtual void bind() = 0;
        virtual void unbind() = 0;
        GLuint get_id() const;
    protected:
        GLuint m_id;
    };

} // mondengine

#endif //NINDO_GLID_H
