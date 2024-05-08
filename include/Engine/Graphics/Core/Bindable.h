//
// Created by MondGnu on 5/1/2024.
//

#ifndef MONDENGINE_BINDABLE_H
#define MONDENGINE_BINDABLE_H

#include <concepts>

namespace Mond {
    class Bindable {
    public:
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
        virtual ~Bindable() = 0;
    };

    template <typename T>
    concept IsBindable = std::derived_from<T, Bindable>;
}


#endif //MONDENGINE_BINDABLE_H
