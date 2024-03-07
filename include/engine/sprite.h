//
// Created by MondGnu on 3/1/2024.
//

#ifndef NINDO_SPRITE_H
#define NINDO_SPRITE_H

#include "game_object.h"
#include "shapes/rectangle.h"

namespace mondengine {
using namespace graphics;
    class Sprite : public Rectangle{
    public:
        MOND_API explicit Sprite(Texture2D &texture);

        MOND_API void Render(Renderer &renderer, float lag) override;
    protected:
        Texture2D& texture;
    };


} // mondengine

#endif //NINDO_SPRITE_H
