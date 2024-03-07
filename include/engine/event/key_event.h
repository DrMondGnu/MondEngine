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

    class KeyEvent : public Event {
    public:
        MOND_API [[nodiscard]] int GetKeyCode() const;

        MOND_API [[nodiscard]] int GetScancode() const;

        MOND_API [[nodiscard]] int GetAction() const;

        MOND_API [[nodiscard]] int GetMods() const;

        MOND_API [[nodiscard]] std::string ToString() const override;

        KeyEvent(const KeyEvent &k) : Event(k.eventType), m_KeyCode(k.m_KeyCode), m_Scancode(k.m_Scancode), m_Action(k.m_Action), m_Mods(k.m_Mods) {}

        bool operator==(const KeyEvent &rhs) const;

        bool operator!=(const KeyEvent &rhs) const;

    protected:
        MOND_API KeyEvent(int mKeyCode, int mScancode, int mAction, int mMods, EventId id);
        int m_KeyCode;
        int m_Scancode;
        int m_Action;
        int m_Mods;
    };

    class KeyDownEvent : public KeyEvent {
    public:
        EVENT_NAME("KeyDownEvent")
        MOND_API KeyDownEvent(int mKeyCode, int mScancode, int mMods) : KeyEvent(mKeyCode, mScancode, GLFW_PRESS,
                                                                                     mMods,
                                                                                     EVENT_TYPE_TO_ID(KeyDown)) {}

        explicit KeyDownEvent(const KeyEvent &k) : KeyEvent(k)
        {
            m_Action = GLFW_PRESS;
            eventType = KeyDown;
        }
    };

    class KeyPressedEvent : public KeyEvent {
    public:
        EVENT_NAME("KeyPressedEvent")

        KeyPressedEvent(int mKeyCode, int mScancode, int mMods) : KeyEvent(mKeyCode, mScancode, GLFW_REPEAT,
                                                                                        mMods, EVENT_TYPE_TO_ID(KeyPressed)) {}

        explicit KeyPressedEvent(const KeyEvent &k) : KeyEvent(k)
        {
            m_Action = GLFW_REPEAT;
            eventType = KeyPressed;
        }
    };

    class KeyUpEvent : public KeyEvent {
    public:
        EVENT_NAME("KeyUpEvent")

        KeyUpEvent(int mKeyCode, int mScancode, int mMods) : KeyEvent(mKeyCode, mScancode, GLFW_RELEASE,
                                                                                   mMods, EVENT_TYPE_TO_ID(KeyUp)) {}

        explicit KeyUpEvent(const KeyEvent &k) : KeyEvent(k)
        {
            m_Action = GLFW_RELEASE;
            eventType = KeyUp;
        }
    };

} // event
// mondengine

#endif //NINDO_KEY_EVENT_H
