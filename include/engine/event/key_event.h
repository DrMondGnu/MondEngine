//
// Created by MondGnu on 2/27/2024.
//

#ifndef NINDO_KEY_EVENT_H
#define NINDO_KEY_EVENT_H


#include "event.h"
#include "fmt/format.h"

namespace mondengine {


    enum EventCategoryKeyboard : EventType {
        KeyDown = CATEGORIZE(EventCategoryKeyboard, 1),
        KeyPressed = CATEGORIZE(EventCategoryKeyboard, 2),
        KeyUp = CATEGORIZE(EventCategoryKeyboard, 3)
    };

    class KeyEvent : public Event{
    public:

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard);
        [[nodiscard]] int GetKeyCode() const;
        [[nodiscard]] int GetScancode() const;
        [[nodiscard]] int GetAction() const;
        [[nodiscard]] int GetMods() const;
    protected:
        KeyEvent(int mKeyCode, int mScancode, int mAction, int mMods);

        int m_KeyCode;
        int m_Scancode;
        int m_Action;
        int m_Mods;
    };
    class KeyDownEvent : public KeyEvent {
    public:
        EVENT_CLASS_TYPE(KeyDown, "KeyDownEvent");

        KeyDownEvent(int mKeyCode, int mScancode, int mAction, int mMods) : KeyEvent(mKeyCode, mScancode, mAction,
                                                                                     mMods) {}

        [[nodiscard]] std::string ToString() const override;
    };
    class KeyPressedEvent : public KeyEvent {
    public:
        EVENT_CLASS_TYPE(KeyPressed, "KeyPressedEvent");

        KeyPressedEvent(int mKeyCode, int mScancode, int mAction, int mMods) : KeyEvent(mKeyCode, mScancode, mAction,
                                                                                        mMods) {}

        [[nodiscard]] std::string ToString() const override;
    };
    class KeyUpEvent : public KeyEvent {
    public:
        EVENT_CLASS_TYPE(KeyUp, "KeyUpEvent");

        KeyUpEvent(int mKeyCode, int mScancode, int mAction, int mMods) : KeyEvent(mKeyCode, mScancode, mAction,
                                                                                   mMods) {}

        [[nodiscard]] std::string ToString() const override;
    };

} // event
// mondengine

#endif //NINDO_KEY_EVENT_H
