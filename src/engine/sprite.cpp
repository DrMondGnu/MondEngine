//
// Created by MondGnu on 3/1/2024.
//

#include "engine/sprite.h"

namespace mondengine {
    void Sprite::Render(Renderer &renderer, float lag)
    {
        renderer.SetModel(ModelMatrix());
        renderer.SetUseTexture(true);
        renderer.SetColor(color);
        glActiveTexture(GL_TEXTURE0);
        texture.bind();
        draw();
    }

    Sprite::Sprite(Texture2D &texture) : texture(texture) {}
} // mondengine