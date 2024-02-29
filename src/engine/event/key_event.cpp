//
// Created by MondGnu on 2/27/2024.
//

#include "engine/event/key_event.h"


namespace mondengine{
    KeyEvent::KeyEvent(int mKeyCode, int mScancode, int mAction, int mMods) : m_KeyCode(mKeyCode),
                                                                              m_Scancode(mScancode), m_Action(mAction),
                                                                              m_Mods(mMods) {}

    int KeyEvent::GetKeyCode() const
    {
        return m_KeyCode;
    }

    int KeyEvent::GetScancode() const
    {
        return m_Scancode;
    }

    int KeyEvent::GetAction() const
    {
        return m_Action;
    }

    int KeyEvent::GetMods() const
    {
        return m_Mods;
    }

    std::string KeyDownEvent::ToString() const {
        return fmt::format("KeyDownEvent(KeyCode: {}, Scancode: {}, Action: {}, Mods: {})", m_KeyCode, m_Scancode, m_Action, m_Mods);
    }

    std::string KeyPressedEvent::ToString() const {
        return fmt::format("KeyPressedEvent(KeyCode: {}, Scancode: {}, Action: {}, Mods: {}", m_KeyCode, m_Scancode, m_Action, m_Mods);
    }

    std::string KeyUpEvent::ToString() const {
        return fmt::format("KeyUpEvent(KeyCode: {}, Scancode: {}, Action: {}, Mods: {}", m_KeyCode, m_Scancode, m_Action, m_Mods);
    }
} // event
// mondengine