//
//  double_stack.h
//  Lab02-3
//
//  Modified by Jeman Park on 2023/09/25.

#ifndef DOUBLE_STACK_H
#define DOUBLE_STACK_H

#define MAX_ITEMS 200

// enumerator for POP direction
// TOP_BIG: pop from bigger-sided stack
// TOP_SMALL: pop from smaller-sided stack
#define TOP_BIG 1
#define TOP_SMALL 2

#include <iostream>


template <class ItemType>
class DoubleStack {

private:
    int top_small;
    // indicator of "top" of smaller sided stack
    int top_big;
    // indicator of "top" of bigger sided stack
    int items[MAX_ITEMS];

public:
    DoubleStack();
    bool IsFull();
    bool IsEmpty();
    void Push(ItemType item);
    ItemType Pop(int direction);
    void Print();

};


template<class ItemType>
DoubleStack<ItemType>::DoubleStack()
{
    top_small = -1;
    top_big = MAX_ITEMS;
}

template<class ItemType>
bool DoubleStack<ItemType>::IsEmpty()
{
    // return true when the stack is empty
    // otherwise, return false
    
    /* Implement the function here */
    return (top_small==-1) && (top_big == MAX_ITEMS);
}

template<class ItemType>
bool DoubleStack<ItemType>::IsFull()
{
    // return true when the stack is full
    // otherwise, return false
    
    /* Implement the function here */
    
    return top_small == top_big;
}

template<class ItemType>
void DoubleStack<ItemType>::Push(ItemType newItem)
{
    if (IsFull()){
        std::cout << "[ERROR] Stack is full. PUSH failed." << std::endl;
        return;
    }
    
    /* Implement the function here */
    if(newItem>=1000){
        top_big--;
        items[top_big]=newItem;
    }else{
        top_small++;
        items[top_small]=newItem;
    }
    
}

template<class ItemType>
ItemType DoubleStack<ItemType>::Pop(int direction)
{
    ItemType result;
    if (IsEmpty()){
        std::cout << "[ERROR] Stack is empty. POP failed." << std::endl;
        return -1;
    }
    
    /* Implement the function here */
    switch(direction){
        case TOP_BIG: if(top_big==MAX_ITEMS){
            return -1;
        }else{
            result=items[top_big];
            top_big++;
            break;
        }
        case TOP_SMALL: if(top_small==-1){
            return -1;
        }else{
            result=items[top_small];
            top_small--;
            break;
        }
    }

    return result;
}

template<class ItemType>
void DoubleStack<ItemType>::Print() {

    std::cout << "[ ";
    for (int i = 0; i <= top_small; i++) {
        std::cout << items[i] << "\t";
    }

    std::cout << " | ";
    for (int i = top_big; i < MAX_ITEMS; i++) {
        std::cout << items[i] << "\t";
    }
    std::cout << " ]";
    std::cout << std::endl;
}


#endif /* double_stack_hpp */
