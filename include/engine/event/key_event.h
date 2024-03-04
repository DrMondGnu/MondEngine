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

        [[nodiscard]] std::string ToString() const override;

    protected:
        KeyEvent(int mKeyCode, int mScancode, int mAction, int mMods, EventId id);

        int m_KeyCode;
        int m_Scancode;
        int m_Action;
        int m_Mods;
    };

    class KeyDownEvent : public KeyEvent {
    public:
        EVENT_NAME("KeyDownEvent")
        KeyDownEvent(int mKeyCode, int mScancode, int mAction, int mMods) : KeyEvent(mKeyCode, mScancode, mAction,
                                                                                     mMods,

                                                                                     EVENT_TYPE_TO_ID(KeyDown)) {}
    };

    class KeyPressedEvent : public KeyEvent {
    public:
        EVENT_NAME("KeyPressedEvent")

        KeyPressedEvent(int mKeyCode, int mScancode, int mAction, int mMods) : KeyEvent(mKeyCode, mScancode, mAction,
                                                                                        mMods, EVENT_TYPE_TO_ID(KeyPressed)) {}
    };

    class KeyUpEvent : public KeyEvent {
    public:
        EVENT_NAME("KeyUpEvent")

        KeyUpEvent(int mKeyCode, int mScancode, int mAction, int mMods) : KeyEvent(mKeyCode, mScancode, mAction,
                                                                                   mMods, EVENT_TYPE_TO_ID(KeyUp)) {}
    };



    class KeyEventHandler {
    public:
        void Add(EventConsumer<KeyEvent>* consumer);
        void DispatchPressed();
        void Dispatch(KeyEvent& event);
    protected:
        std::unordered_map<EventCategory, std::vector<EventConsumer<KeyEvent>*>> m_consumers;
        std::unordered_set<int> pressedKeys;
    };
} // event
// mondengine

#endif //NINDO_KEY_EVENT_H
