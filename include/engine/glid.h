//
// Created by MondGnu on 2/26/2024.
//

#ifndef NINDO_GLID_H
#define NINDO_GLID_H

#include <GL/glew.h>

namespace mondengine {

#define IF_BOUND if(IsBound())
#define RETURN_IF_BOUND if(IsBound()) { return; }
#define RETURN_IF_NOT_BOUND if(!IsBound()) { return; }
#define BIND_IF_NOT if(!IsBound()) { bind(); }

    class GLID {
    public:
        explicit GLID();
        // TODO: move bind methods to protected and handle as onBind fn. Add m_bound safe guard to new not virtual Bind and Unbind methods
        virtual void bind() = 0;
        virtual void unbind() = 0;
        bool IsBound() const;
        GLuint GetId() const;
    protected:
        GLuint m_id = 0;
        bool m_bound = false;
    };

} // mondengine

#endif //NINDO_GLID_H
