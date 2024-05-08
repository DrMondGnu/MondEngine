//
// Created by MondGnu on 5/1/2024.
//

#ifndef MONDENGINE_BUFFER_H
#define MONDENGINE_BUFFER_H

#include <concepts>

#include "Bindable.h"

namespace Mond::Graphics {

    class Buffer : public Bindable{

    };

    template <typename T>
    concept IsBuffer = std::derived_from<T, Buffer>;

} // Graphics
// Mond

#endif //MONDENGINE_BUFFER_H
