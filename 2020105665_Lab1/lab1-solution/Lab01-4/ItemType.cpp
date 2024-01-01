//
//  ItemType.cpp
//  Lab01
//
//  Modified by Jeman Park on 2023/09/18.
//

/* DO NOT CHANGE file/function/variable/class names and parameters */
/* But, you can add functions if necessary */

#include <iostream>
#include "ItemType.h"

// Constructor of ItemType (no input parameter) -> value: 0
ItemType::ItemType()
{
    value = 0;
}

// Constructor of ItemType (with input parameter) -> value: input (number)
ItemType::ItemType(int number)
{ 
    value = number;
}

// Compare the current object's 'value' with input(otherItem)'s value
RelationType ItemType::ComparedTo(ItemType otherItem) const 
{
    if (value < otherItem.value)
        return LESS;
    
    else if (value > otherItem.value)
        return GREATER;
    
    else return EQUAL;
}

// Initialization; never used;
void ItemType::Initialize(int number) 
{
    value = number;
}

// Print the current object's value
void ItemType::Print() const
{
    std::cout << value;
}
