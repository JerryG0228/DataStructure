//
//  StackType.hpp
//  Lab02-2
//
//  Modified by Jeman Park on 2023/09/25.

#ifndef StackType_H
#define StackType_H

#include <iostream>

#define MAX_ITEMS 50

// ItemType == int
typedef int ItemType;


class StackType
{
public:
    
    StackType();
    bool IsFull() const;
    bool IsEmpty() const;
    void Push(ItemType item);
    ItemType Pop();
    
    void printStack();
    void ReplaceItem(ItemType oldItem,ItemType newItem);
    
    
private:
    int top;
    ItemType items[MAX_ITEMS];
};



#endif /* StackType_hpp */
