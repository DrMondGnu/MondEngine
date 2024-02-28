//
// Created by MondGnu on 2/27/2024.
//

#ifndef NINDO_KEY_EVENT_H
#define NINDO_KEY_EVENT_H

namespace mondengine {
    namespace event {

        struct KeyEvent {
            int key;
            int scancode;
            int action;
            int mods;
        };

    } // event
} // mondengine

#endif //NINDO_KEY_EVENT_H
