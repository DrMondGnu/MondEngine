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


    void KeyEventHandler::DispatchPressed()
    {

    }

    void KeyEventHandler::Dispatch(KeyEvent &event)
    {
        if(event.GetAction() == GLFW_PRESS) {
            pressedKeys.insert(event.GetKeyCode());
            return;
        }
        for (const auto &item: m_consumers[event.GetEventCategory()]) {
            if(item == nullptr) {
                continue;
            }
            item->ConsumeEvent(event);
        }
    }

    void KeyEventHandler::Add(EventConsumer<KeyEvent>* consumer)
    {
        m_consumers[consumer->GetEventCategory()].push_back(consumer);
    }


} // event
// mondengine