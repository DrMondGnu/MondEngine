//
// Created by MondGnu on 2/27/2024.
//

#ifndef NINDO_EBO_H
#define NINDO_EBO_H


#include "engine/glid.h"

namespace mondengine::graphics {

    class EBO : GLID{
    public:
        EBO(const void* data, GLsizeiptr size);

        void bind() override;
        void unbind() override;

    };

} // graphics
// mondengine

#endif //NINDO_EBO_H
