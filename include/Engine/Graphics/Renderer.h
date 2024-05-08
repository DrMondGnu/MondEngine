//
// Created by MondGnu on 4/29/2024.
//

#ifndef MONDENGINE_RENDERER_H
#define MONDENGINE_RENDERER_H

namespace Mond {

    template <typename T>
    class Renderer {
    public:
        /**
         * Render the inputs
         * @param object object to render
         */
        void Render(const T& object);

        virtual ~Renderer() = 0;
    };


} // Mond

#endif //MONDENGINE_RENDERER_H
