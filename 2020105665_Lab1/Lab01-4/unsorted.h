//
//  unsorted.h
//  Lab01
//
//  Modified by Jeman Park on 2023/09/18.
//

#include "ItemType.h"

/* DO NOT CHANGE file/function/variable/class names and parameters */
/* But, you can add functions if necessary */

class UnsortedType 
{
public:
    UnsortedType();
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
