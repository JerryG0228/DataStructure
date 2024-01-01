//
//  StackType.h
//  Lab04-1
//
//  Modified by Jeman Park on 2023/10/17.
//

#ifndef STACKTYPE_H
#define STACKTYPE_H

typedef int ItemType;
struct NodeType;


class StackType
{
public:
    
    StackType();
    ~StackType();
    bool IsFull();
    bool IsEmpty();
    void Push(ItemType item);
    ItemType Pop();
    void ReplaceItem(ItemType oldItem, ItemType newItem);
    void printStack();
    
private:
    NodeType* topPtr;
};

struct NodeType
{
    ItemType info;
    NodeType* next;
};

#endif
