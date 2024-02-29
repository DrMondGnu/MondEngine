//
// Created by MondGnu on 2/29/2024.
//

#include "gtest/gtest.h"
#include "node.h"

class TestNode : public Node<TestNode> {
public:
    const char* GetName() { return "TestNode"; };
};

TEST(NodeTests, NodeAddChildTest)
{
    auto* root = new TestNode;
    auto* childNode = new TestNode;
    root->AddChild(childNode);
    ASSERT_TRUE(root->HasChild(childNode));
    ASSERT_EQ(childNode->GetParent(), root);
}
