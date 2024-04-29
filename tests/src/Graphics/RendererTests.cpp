//
// Created by MondGnu on 4/29/2024.
//
#include "doctest.h"
#include "engine/Graphics/Renderer.h"

using namespace mondengine;

class TestRenderedObject {
public:
    bool Rendered = false;
    [[nodiscard]] const char* GetName() const {
        return "Test Object";
    }
};

class SubTestRenderedObject : public TestRenderedObject {

};

template <typename T>
requires std::derived_from<T, TestRenderedObject>
class Renderer<T> {
public:
    bool Rendered = false;
    void Render(T& object) {
        Rendered = true;
        object.Rendered = true;
    }
};

class RenderFinder {
public:
    template<typename T>
    void Render(T& t) {
        Renderer<T> renderer;
        renderer.Render(t);
    }
};

TEST_CASE("RendererTest") {
    Renderer<TestRenderedObject> r;
    TestRenderedObject object;

    REQUIRE_FALSE(r.Rendered);
    REQUIRE_FALSE(object.Rendered);

    r.Render(object);

    CHECK(r.Rendered);
    CHECK(object.Rendered);
}

TEST_CASE("RenderFinderTests") {
    RenderFinder finder;
    SUBCASE("FindTestObject") {
        TestRenderedObject object;

        REQUIRE_FALSE(object.Rendered);

        finder.Render(object);

        CHECK(object.Rendered);
    }
    SUBCASE("FindInheritanceObject") {
        SubTestRenderedObject object;

        REQUIRE_FALSE(object.Rendered);

        finder.Render(object);

        CHECK(object.Rendered);
    }
}