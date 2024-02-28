//
// Created by MondGnu on 2/27/2024.
//
#include "gtest/gtest.h"
#include "engine/event/event.h"

using namespace mondengine::event;

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

class EventTestsFixture : public ::testing::Test {
protected:
    void SetUp() override
    {

    }

    void TearDown() override
    {

    }
};

bool TestEventFunction(TestEvent &event)
{
    return true;
}

TEST_F(EventTestsFixture, EventDispatcherStdFunctionTest)
{
    TestEvent event("TestEvent", CATEGORIZE(EventCategoryCustom, 0), EventCategoryCustom);
    EventDispatcher dispatcher(event);
    std::function<bool(TestEvent &)> func = &TestEventFunction;
    dispatcher.Dispatch<TestEvent>(func);
    ASSERT_TRUE(event.IsHandled());
}

TEST_F(EventTestsFixture, EventDispatcherEventConsumerTest)
{
    TestEvent event("TestEvent", CATEGORIZE(EventCategoryCustom, 0), EventCategoryCustom);
    EventDispatcher dispatcher(event);
    EventConsumer<TestEvent> func(&TestEventFunction, CATEGORIZE(EventCategoryCustom, 0));
    EXPECT_TRUE(dispatcher.Dispatch(func));
    ASSERT_TRUE(event.IsHandled());
}

TEST(CATEGORIZE, RightOutputTest)
{
    ASSERT_EQ(513,  CATEGORIZE(0x00000001, 2));
}

TEST(REMOVE_CATEGORY, RightOutputTest) {
    ASSERT_EQ(2, REMOVE_CATEGORY(513));
}

TEST(CATEGORY_OF, RightOutputTest) {
    ASSERT_EQ(1, CATEGORY_OF(513));
}