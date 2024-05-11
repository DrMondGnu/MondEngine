//
// Created by MondGnu on 5/11/2024.
//
#include "doctest.h"
#include "Engine/Graphics/Shapes/Rectangle.h"
#include "Engine/PlatformUtils.h"

#include "TestingUtil.cpp"

using namespace Mond::Graphics;

class TestRect : public Rectangle {
public:
    const Mond::DrawableShader &GetShader() const override
    {
        return shader;
    }

    const glm::vec4 &GetColor() const override
    {
        return glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
    }

protected:
    TestShader shader;
};

TEST_CASE("RectangleTest") {
    WindowProperties settings = {"Tests", 1200, 800, true, false};
    Window* window = MakeWindow(settings);
    TestRect rect;
    Renderer<RenderObject> renderer;
    renderer.Render(rect);
}