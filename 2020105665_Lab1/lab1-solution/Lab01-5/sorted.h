//
//  sorted.h
//  Lab01
//
//  Modified by Jeman Park on 2023/09/18.
//

#ifndef SORTED_H
#define SORTED_H
#include "ItemType.h" 


class SortedType 
{
public:
    SortedType();
    bool IsFull() const;
    int LengthIs() const;
    void RetrieveItem(ItemType& item, bool& found);
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    void GetNextItem(ItemType& item);
    void PrintList();
    
private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
};

#endif
