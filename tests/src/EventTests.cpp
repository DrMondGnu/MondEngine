//
// Created by MondGnu on 4/27/2024.
//
#include "../doctest.h"
#include <EventNode.h>
#include <engine/event/KeyEvent.h>

using namespace mondengine;

template <typename T>
requires IsKeyEvent<T>
class TestKeyEventHandler : public EventHandler<T>{
public:
    const T* Handled = nullptr;
    void HandleEvent(const T &event) override
    {
        Handled = &event;
    }
};

TEST_CASE("KeyEventTests") {
    EventNode root;
    SUBCASE("KeyDownEventTest") {
        KeyEventListener<KeyDownEvent> listener;
        TestKeyEventHandler<KeyDownEvent> handler;
        KeyDownEvent event(20, 30, 40);

        listener.AddHandler(&handler);
        root.AddListener(&listener);
        root.Dispatch(event);

        REQUIRE(handler.Handled);
        CHECK_EQ(handler.Handled, &event);
    }
    SUBCASE("KeyPressedEventTest") {
        KeyEventListener<KeyPressedEvent> listener;
        TestKeyEventHandler<KeyPressedEvent> handler;
        KeyPressedEvent event(20, 30, 40);

        listener.AddHandler(&handler);
        root.AddListener(&listener);
        root.Dispatch(event);

        REQUIRE(handler.Handled);
        CHECK_EQ(handler.Handled, &event);
    }
    SUBCASE("KeyUpEventTest") {
        KeyEventListener<KeyUpEvent> listener;
        TestKeyEventHandler<KeyUpEvent> handler;
        KeyUpEvent event(20, 30, 40);

        listener.AddHandler(&handler);
        root.AddListener(&listener);
        root.Dispatch(event);

        REQUIRE(handler.Handled);
        CHECK_EQ(handler.Handled, &event);
    }
    SUBCASE("KeyEventTest") {
        KeyEventListener<KeyEvent> listener;
        TestKeyEventHandler<KeyEvent> handler;
        KeyDownEvent event(20, 30, 40);

        listener.AddHandler(&handler);
        root.AddListener(&listener);
        root.Dispatch(event);

        REQUIRE(handler.Handled);
        CHECK_EQ(handler.Handled, &event);
    }
}