//
// Created by MondGnu on 2/26/2024.
//

#ifndef NINDO_OPENGL_H
#define NINDO_OPENGL_H

#include "GL/glew.h"
#include "engine/log.h"
#include "util/file.h"

#define GL_DEBUG

#ifdef GL_DEBUG
#define GL_CHECK_ERROR_FN(fn) fn; \
PrintOpenglErrors(__FILE__, __LINE__)
#define GL_CHECK_ERROR() PrintOpenglErrors(__FILE__, __LINE__)

#else
#define GL_CHECK_ERROR_FN(m_function) m_function
#endif
inline void PrintOpenglErrors(const char* file, int line)
{
    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR)
    {
        const char* fileName = mondengine::file::get_file_name(file);
        MOE_ERROR("OpenGL error in {} {}:{} : {}, {:x}",file, fileName,line, (char*)gluErrorString(err), err);
    }
}

#endif //NINDO_OPENGL_H
