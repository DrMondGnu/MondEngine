//
// Created by MondGnu on 2/29/2024.
//

#ifndef NINDO_NODE_H
#define NINDO_NODE_H

#include <unordered_set>

template<typename T>
class Node {
public:
    explicit Node() : m_Children(){}

    bool HasParent()
    {
        return m_Parent != nullptr;
    }

    bool HasChild(Node<T>* child)
    {
        return m_Children.contains(child);
    }
    void AddChild(Node<T>* child)
    {
        m_Children.insert(child);
        child->SetParent(this);
    }
    T* Get()
    {
        return (T*)this;
    }
    Node<T>* GetParent()
    {
        return m_Parent;
    }
protected:
    /**
     * Called before a parent change.
     * @param newParent the new parent which is going to be set
     */
    virtual void onSetParent(Node<T>* newParent)
    {
        m_Parent = newParent;
    }
    /**
     * Called when a child changes parent
     * @param child the child which changes parent
     */
    virtual void onChildNewParent(Node<T>* child)
    {
        m_Children.erase(child);
    }
    /**
     * Calls onChildChange on the old parent
     * Calls onSetParent on this node
     * @param newParent the new parent for this Node
     */
    void SetParent(Node<T>* newParent)
    {
        if(m_Parent != nullptr)
        {
            m_Parent->onChildNewParent(newParent);
        }
        onSetParent(newParent);
    }
    Node<T>* m_Parent = nullptr;
    std::unordered_set<Node<T>*> m_Children;
};



#endif //NINDO_NODE_H
