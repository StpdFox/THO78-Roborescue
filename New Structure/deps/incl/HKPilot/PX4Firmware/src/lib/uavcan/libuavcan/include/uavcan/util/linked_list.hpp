/*
 * Singly-linked list.
 * Copyright (C) 2014 Pavel Kirienko <pavel.kirienko@gmail.com>
 */

#pragma once

#include <cstdlib>
#include <cassert>
#include <uavcan/build_config.hpp>

namespace uavcan
{
/**
 * Classes that are supposed to be linked-listed should derive this.
 */
template <typename T>
class UAVCAN_EXPORT LinkedListNode
{
    T* next_;

protected:
    LinkedListNode()
        : next_(NULL)
    { }

    ~LinkedListNode() { }

public:
    T* getNextListNode() const { return next_; }

    void setNextListNode(T* node)
    {
        next_ = node;
    }
};

/**
 * Linked list root.
 */
template <typename T>
class UAVCAN_EXPORT LinkedListRoot
{
    T* root_;

public:
    LinkedListRoot()
        : root_(NULL)
    { }

    T* get() const { return root_; }
    bool isEmpty() const { return get() == NULL; }

    /**
     * Complexity: O(N)
     */
    unsigned getLength() const;

    /**
     * Inserts the node to the beginning of the list.
     * If the node is already present in the list, it will be relocated to the beginning.
     * Complexity: O(N)
     */
    void insert(T* node);

    /**
     * Inserts the node immediately before the node X where predicate(X) returns true.
     * If the node is already present in the list, it can be relocated to a new position.
     * Complexity: O(2N) (calls remove())
     */
    template <typename Predicate>
    void insertBefore(T* node, Predicate predicate);

    /**
     * Removes only the first occurence of the node.
     * Complexity: O(N)
     */
    void remove(const T* node);
};

// ----------------------------------------------------------------------------

/*
 * LinkedListRoot<>
 */
template <typename T>
unsigned LinkedListRoot<T>::getLength() const
{
    T* node = root_;
    unsigned cnt = 0;
    while (node)
    {
        cnt++;
        node = node->getNextListNode();
    }
    return cnt;
}

template <typename T>
void LinkedListRoot<T>::insert(T* node)
{
    UAVCAN_ASSERT(node);
    if (node == NULL)
    {
        return;
    }
    remove(node);  // Making sure there will be no loops
    node->setNextListNode(root_);
    root_ = node;
}

template <typename T>
template <typename Predicate>
void LinkedListRoot<T>::insertBefore(T* node, Predicate predicate)
{
    UAVCAN_ASSERT(node);
    if (node == NULL)
    {
        return;
    }

    remove(node);

    if (root_ == NULL || predicate(root_))
    {
        node->setNextListNode(root_);
        root_ = node;
    }
    else
    {
        T* p = root_;
        while (p->getNextListNode())
        {
            if (predicate(p->getNextListNode()))
            {
                break;
            }
            p = p->getNextListNode();
        }
        node->setNextListNode(p->getNextListNode());
        p->setNextListNode(node);
    }
}

template <typename T>
void LinkedListRoot<T>::remove(const T* node)
{
    if (root_ == NULL || node == NULL)
    {
        return;
    }

    if (root_ == node)
    {
        root_ = root_->getNextListNode();
    }
    else
    {
        T* p = root_;
        while (p->getNextListNode())
        {
            if (p->getNextListNode() == node)
            {
                p->setNextListNode(p->getNextListNode()->getNextListNode());
                break;
            }
            p = p->getNextListNode();
        }
    }
}

}
