//
// Created by MondGnu on 2/29/2024.
//

#ifndef NINDO_TEXTURE_H
#define NINDO_TEXTURE_H

#include "glid.h"
#include "library.h"

namespace Mond {

    class Texture2D : public GLID{
    public:
        // texture image dimensions
        unsigned int Width, Height; // width and height of loaded image in pixels
        // texture Format
        unsigned int Internal_Format; // format of texture object
        unsigned int Image_Format; // format of loaded image
        // texture configuration
        unsigned int Wrap_S; // wrapping mode on S axis
        unsigned int Wrap_T; // wrapping mode on T axis
        unsigned int Filter_Min; // filtering mode if texture pixels < screen pixels
        unsigned int Filter_Max; // filtering mode if texture pixels > screen pixels
        // constructor (sets default texture modes)
        MOND_API Texture2D();
        // generates texture from image data
        MOND_API void Generate(unsigned int width, unsigned int height, unsigned char* data);
        MOND_API void bind() override;
        MOND_API void unbind() override;
    };

} // Mond

#endif //NINDO_TEXTURE_H
