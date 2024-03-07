//
// Created by MondGnu on 2/27/2024.
//

#include "engine/event/key_event.h"


namespace mondengine{
    KeyEvent::KeyEvent(int mKeyCode, int mScancode, int mAction, int mMods, EventId id) : m_KeyCode(mKeyCode),
                                                                              m_Scancode(mScancode), m_Action(mAction),
                                                                              m_Mods(mMods), Event(id, EventCategoryKeyboard) {}

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

    std::string KeyEvent::ToString() const
    {
        return fmt::format("{}(KeyCode: {}, Scancode: {}, Action: {}, Mods: {})", GetName(),m_KeyCode, m_Scancode, m_Action, m_Mods);
    }

    bool KeyEvent::operator==(const KeyEvent &rhs) const
    {
        return m_KeyCode == rhs.m_KeyCode &&
               m_Scancode == rhs.m_Scancode &&
               m_Action == rhs.m_Action &&
               m_Mods == rhs.m_Mods;
    }

    bool KeyEvent::operator!=(const KeyEvent &rhs) const
    {
        return !(rhs == *this);
    }

} // event
// mondengine