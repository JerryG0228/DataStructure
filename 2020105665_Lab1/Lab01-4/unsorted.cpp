//
//  unsorted.cpp
//  Lab01
//
//  Modified by Jeman Park on 2023/09/18.
//



/* DO NOT CHANGE file/function/variable/class names and parameters */
/* But, you can add functions if necessary */

#include<iostream>
#include "unsorted.h"

// Constructor of Unsorted List (initially, no element (length = 0))
UnsortedType::UnsortedType()
{
    length = 0;
}

// Check if the list is full
bool UnsortedType::IsFull() const
{
    return (length == MAX_ITEMS);
}

// Check the current length of the list
int UnsortedType::LengthIs() const
{
    return length;
}

// Check if the list contains 'item'
// return true if 'item' exist
// return false if 'item' not exist
void UnsortedType::RetrieveItem(ItemType& item, bool& found)
{
    bool moreToSearch;
    int location = 0;
    found = false;
    
    moreToSearch = (location < length);
    
    while (moreToSearch && !found)
    {
        switch (item.ComparedTo(info[location]))
        {
            case LESS    :
            case GREATER : location++;
                moreToSearch = (location < length);
                break;
            case EQUAL   : found = true;
                item = info[location];
                break;
        }
    }
}

// Add a new element into the list (Unsorted)
void UnsortedType::InsertItem(ItemType item)
{
    info[length] = item;
    length++;
}

// Delete an element from the list (Unsorted)
void UnsortedType::DeleteItem(ItemType item)
{
    /* Implement the function here */
    /* Return nothing (void) */
    /* Hint: Yo can refer to page 24 in lecture slides (ch.03) */
    /*       But you need to revise it following the instruction */
    /*       (a) If there is no element to be deleted, keep the list as it is. */
    /*       (b) If there are multiple elements to be deleted, remove all. */

    int location = 0;
    while(location!=length){
        if(item.ComparedTo(info[location])==EQUAL){
            info[location] = info[length-1];
            length--;
        }
        else{
            location++;
        }
    }
}

// Reset the iterator
void UnsortedType::ResetList()
{
    currentPos = -1;
}

// Move the iterator to the next element
void UnsortedType::GetNextItem(ItemType& item)
{
    currentPos++;
    item = info[currentPos];
}

// Print the entire list
void UnsortedType::PrintList()
{
    for(int i=0; i < length; i++){
        info[i].Print();
        std::cout << " ";
    }
    std::cout << std::endl;
}
