//
// Created by MondGnu on 5/1/2024.
//

#ifndef MONDENGINE_SHADERCOMPILER_H
#define MONDENGINE_SHADERCOMPILER_H

#include "../log.h"


namespace mondengine {

    class ShaderCompiler {
    public:
        /**
         * Compile shaders into a shader programm
         * @param vertex vertex shader string
         * @param fragment fragment shader string
         * @return shader id
         */
        GLuint Compile(const std::string& vertex, const std::string& fragment);
    };

} // mondengine

#endif //MONDENGINE_SHADERCOMPILER_H
