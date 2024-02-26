//
// Created by MondGnu on 2/26/2024.
//

#include "engine/glid.h"

namespace mondengine {
    GLID::GLID() : m_id(0) {
    }

    GLuint GLID::get_id() const
    {
        return m_id;
    }
} // mondengine