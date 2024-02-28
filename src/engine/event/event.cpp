//
// Created by MondGnu on 2/27/2024.
//

#include "engine/event/event.h"


namespace mondengine::event {

    bool Event::IsHandled() const
    {
        return m_Handled;
    }


} // event
// mondengine