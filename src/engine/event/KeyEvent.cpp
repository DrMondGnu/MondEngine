//
// Created by MondGnu on 4/27/2024.
//

#include "engine/event/KeyEvent.h"

namespace mondengine {
    bool KeyEventTypeMatch(const EventType & lhs, const KeyEventType& rhs) {
        return lhs== rhs || lhs == None || rhs ==  None;
    }

    KeyEvent::~KeyEvent() = default;

    KeyEvent::KeyEvent(KeyEventType type, const int keyCode, const int scancode, const int mods) : Event(type),
                                                                                                   keyCode(keyCode),
                                                                                                   scancode(scancode),
                                                                                                   mods(mods) {}

    int KeyEvent::GetKeyCode() const
    {
        return keyCode;
    }

    int KeyEvent::GetScancode() const
    {
        return scancode;
    }

    int KeyEvent::GetMods() const
    {
        return mods;
    }

    KeyDownEvent::KeyDownEvent(const int keyCode, const int scancode, const int mods) : KeyEvent(KeyDownEventType,
                                                                                                 keyCode, scancode,
                                                                                                 mods) {}

    KeyPressedEvent::KeyPressedEvent(const int keyCode, const int scancode, const int mods) : KeyEvent(
            KeyPressedEventType,
            keyCode, scancode,
            mods) {}

    KeyUpEvent::KeyUpEvent(const int keyCode, const int scancode, const int mods) : KeyEvent(KeyUpEventType,
                                                                                             keyCode, scancode,
                                                                                             mods) {}

} // mondengine