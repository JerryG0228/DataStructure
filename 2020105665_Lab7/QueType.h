//
//  QueType.h
//  Lab07
//
//  Modified by Jeman Park on 2023/11/15.
//

#include <new>
#include <cstddef>

#ifndef QUETYPE_H
#define QUETYPE_H

typedef int ItemType;


struct TreeNode
{
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

struct NodeType
{
    TreeNode* info;
    NodeType* next;
};


class QueType
{
public:
    QueType();
    ~QueType();
    QueType(const QueType& anotherQue);
    void operator=(const QueType& originalQueue);
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(TreeNode* newItem);
    TreeNode* Dequeue();
    void printQueue();

private:
    NodeType* front;
    NodeType* rear;
};


#endif
