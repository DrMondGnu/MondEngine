//
// Created by MondGnu on 2/29/2024.
//

#include "doctest.h"
#include "node.h"

class TestNode : public Node<TestNode> {
public:
    const char* GetName() { return "TestNode"; };
};

TEST_CASE("NodeTests")
{
    auto* root = new TestNode;
    auto* childNode = new TestNode;
    root->AddChild(childNode);
    CHECK(root->HasChild(childNode));
    CHECK_EQ(childNode->GetParent(), root);
}
