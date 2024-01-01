//
//  ItemType.cpp
//  Lab01
//
//  Modified by Jeman Park on 2023/09/18.
//

#include <fstream>
#include <iostream>
#include "ItemType.h"

ItemType::ItemType()
{
    value = 0;
}

ItemType::ItemType(int number)
{
    value = number;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const
{
    if (value < otherItem.value)
        return LESS;
    else if (value > otherItem.value)
        return GREATER;
    else return EQUAL;
}

void ItemType::Initialize(int number)
{
    value = number;
}

void ItemType::Print() const
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
    std::cout << value;
}
