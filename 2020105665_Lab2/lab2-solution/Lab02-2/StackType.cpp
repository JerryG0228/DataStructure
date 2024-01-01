//
//  StackType.cpp
//  Lab02-2
//
//  Modified by Jeman Park on 2023/09/25.
//

#include "StackType.h"
#include <iostream>
StackType::StackType()
{
    top = -1;
}

bool StackType::IsEmpty() const
{
    return (top == -1);
}

bool StackType::IsFull() const
{
    return (top ==  MAX_ITEMS-1);
}

void StackType::Push(ItemType newItem)
{
    if( IsFull() ){
        std::cout << "[ERROR] Stack is full. PUSH failed." << std::endl;
        return;
    }
    
    /* Implement the function here */
    
    top++;
    items[top] = newItem;
}

ItemType StackType::Pop()
{
    if( IsEmpty() ){
        std::cout << "[ERROR] Stack is empty. POP failed." << std::endl;
        return -1;
    }
    
    /* Implement the function here */
    
    ItemType result = items[top];
    top--;
    return result;
}


void StackType::printStack(){
    std::cout << "[ ";
    for(int i = 0; i < top; i++){
        std::cout << items[i] << "\t";
    }
    std::cout << " (top) " << std::endl;
}

void StackType::ReplaceItem(ItemType oldItem, ItemType newItem) {
    
    StackType temp_stack;
    
    /* Implement the function here */
    // Elements in stack only can be accessed by pop();
    // You cannot access through items[i]
    
    while (!IsEmpty()){
        ItemType item = Pop();
        if (item == oldItem){
            temp_stack.Push(newItem);
        }
        else{
            temp_stack.Push(item);
        }
    }
    
    while(!temp_stack.IsEmpty()){
        Push(temp_stack.Pop());
    }
}

