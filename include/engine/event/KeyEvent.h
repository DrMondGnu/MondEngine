//
// Created by MondGnu on 4/27/2024.
//

#ifndef MONDENGINE_KEYEVENT_H
#define MONDENGINE_KEYEVENT_H

#include <concepts>

#include <Event.h>
#include <EventListener.h>

#define KEY_DOWN_EVENT_ID 1
#define KEY_PRESSED_EVENT_ID 2
#define KEY_UP_EVENT_ID 3

namespace mondengine {

    enum KeyEventType : EventType {
        None = 0,
        KeyDownEventType = KEY_DOWN_EVENT_ID,
        KeyPressedEventType = KEY_PRESSED_EVENT_ID,
        KeyUpEventType = KEY_UP_EVENT_ID
    };

    bool KeyEventTypeMatch(const EventType & lhs, const KeyEventType& rhs);
    /**
     * @class
     * Any KeyEvent
     */
    class KeyEvent : public Event {
    public:
        KeyEvent(KeyEventType type, int keyCode, int scancode, int mods);
        ~KeyEvent() override = 0;

        [[nodiscard]] int GetKeyCode() const;

        [[nodiscard]] int GetScancode() const;

        [[nodiscard]] int GetMods() const;

    protected:
        const int keyCode;
        const int scancode;
        const int mods;
    };

    /**
     * @class
     * KeyDownEvent
     */
    class KeyDownEvent : public KeyEvent {
    public:
        KeyDownEvent(int keyCode, int scancode, int mods);
    };

    /**
     * @class
     * KeyPressedEvent
     */
    class KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(int keyCode, int scancode, int mods);
    };

    /**
     * @class
     * KeyUpEvent
     */
    class KeyUpEvent : public KeyEvent {
    public:
        KeyUpEvent(int keyCode, int scancode, int mods);
    };

    template <typename T>
    concept IsKeyEvent = std::derived_from<T, KeyEvent>;

    template <typename T>
    requires IsKeyEvent<T>
    struct KeyEventToType {};

    template <>
    struct KeyEventToType<KeyEvent> {
        static constexpr KeyEventType value = None;
    };
    template <>
    struct KeyEventToType<KeyDownEvent> {
        static constexpr KeyEventType value = KeyDownEventType;
    };
    template <>
    struct KeyEventToType<KeyPressedEvent> {
        static constexpr KeyEventType value = KeyPressedEventType;
    };
    template <>
    struct KeyEventToType<KeyUpEvent> {
        static constexpr KeyEventType value = KeyUpEventType;
    };

    template <typename T, KeyEventType type = KeyEventToType<T>::value>
    requires IsKeyEvent<T>
    class KeyEventListener : public DefaultEventListener<T> {
    public:
        void HandleEvent(const KeyEvent &event) override
        {
            if(KeyEventTypeMatch(event.GetType(), type)) {
                this->callHandlers((const T&)event);
            }
        }
    };
} // mondengine

#endif //MONDENGINE_KEYEVENT_H
