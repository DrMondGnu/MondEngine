//
// Created by MondGnu on 2/27/2024.
//
#include "gtest/gtest.h"
#include "engine/event/event.h"
#include "engine/event/key_event.h"

using namespace mondengine;

class TestEvent : public Event {
public:

    TestEvent(const char *mName, EventType mEventType, EventCategory mEventCategory) : m_Name(mName),
                                                                                       m_EventType(mEventType),
                                                                                       m_EventCategory(
                                                                                               mEventCategory) {}

    EventId GetEventId() const override
    {
        return REMOVE_CATEGORY(m_EventType);
    }

    const char *GetName() const override
    {
        return m_Name;
    }

    EventType GetEventType() const override
    {
        return m_EventType;
    }

    EventCategory GetEventCategory() const override
    {
        return m_EventCategory;
    }

    static EventType GetStaticType() { return CATEGORIZE(EventCategoryCustom, 0); }

    inline std::string ToString() const override
    {
        std::stringstream ss;
        ss << "TestEvent";
        return ss.str();
    }

protected:
    const char *m_Name;
    EventType m_EventType;
    EventCategory m_EventCategory;
};

bool TestEventFunction(TestEvent &event)
{
    return true;
}

TEST(EventDispatcherTests, EventDispatcherStdFunctionTest)
{
    TestEvent event("TestEvent", CATEGORIZE(EventCategoryCustom, 0), EventCategoryCustom);
    EventDispatcher dispatcher(event);
    std::function<bool(TestEvent &)> func = &TestEventFunction;
    dispatcher.Dispatch<TestEvent>(func);
    ASSERT_TRUE(event.IsHandled());
}

TEST(EventDispatcherTests, EventDispatcherEventConsumerTest)
{
    TestEvent event("TestEvent", CATEGORIZE(EventCategoryCustom, 0), EventCategoryCustom);
    EventDispatcher dispatcher(event);
    EventConsumer<TestEvent> func(&TestEventFunction, CATEGORIZE(EventCategoryCustom, 0));
    EXPECT_TRUE(dispatcher.Dispatch(func));
    ASSERT_TRUE(event.IsHandled());
}

TEST(CATEGORIZETests, RightOutputTest)
{
    ASSERT_EQ(513,  CATEGORIZE(0x00000001, 2));
}

TEST(REMOVE_CATEGORYTests, RightOutputTest) {
    ASSERT_EQ(2, REMOVE_CATEGORY(513));
}

TEST(CATEGORY_OFTests, RightOutputTest) {
    ASSERT_EQ(1, CATEGORY_OF(513));
}

bool KeyEventTestFunction(KeyEvent& keyEvent) {
    return true;
}


class KeyEventTests : public ::testing::Test {
protected:
    void SetUp() override
    {
        m_Consumer = new EventConsumer<KeyEvent>(&KeyEventTestFunction,mondengine::EventCategoryKeyboard);
    }

    void TearDown() override
    {
        delete m_Consumer;
    }

    EventConsumer<KeyEvent>* m_Consumer;

};


TEST_F(KeyEventTests, KeyDownEventDispatchTest)
{
    KeyDownEvent event(2, 3, 4, 5);
    EventDispatcher dispatcher(event);
    dispatcher.Dispatch(*m_Consumer);
    ASSERT_TRUE(event.IsHandled());
}
TEST_F(KeyEventTests, KeyPressedEventDispatchTest)
{
    KeyPressedEvent event(2, 3, 4, 5);
    EventDispatcher dispatcher(event);
    dispatcher.Dispatch(*m_Consumer);
    ASSERT_TRUE(event.IsHandled());
}
TEST_F(KeyEventTests, KeyUpEventDispatchTest)
{
    KeyUpEvent event(2, 3, 4, 5);
    EventDispatcher dispatcher(event);
    dispatcher.Dispatch(*m_Consumer);
    ASSERT_TRUE(event.IsHandled());
}
