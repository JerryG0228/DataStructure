//
//  mergeList.cpp
//  Lab01
//
//  Created by parkjeman on 2023/09/18.
//


/* DO NOT CHANGE file/function/variable/class names and parameters */
/* But, you can add functions if necessary */

#include "mergeList.h"
#include <iostream>

SortedType MergeList(SortedType list1, SortedType list2){
    /* Implement the function here */
    /* Return Sorted List (result) */
    
    SortedType result;
    
//    list1.ResetList();
//    list2.ResetList();
//    result.ResetList();
    
    int sizeOfList1 = list1.LengthIs();
    int sizeOfList2 = list2.LengthIs();
    

    for (int i = 0; i < sizeOfList1; i++) {
        ItemType tempItem;
        list1.GetNextItem(tempItem);
        result.InsertItem(tempItem);
    }
    
    for (int i = 0; i < sizeOfList2; i++) {
        ItemType tempItem;
        list2.GetNextItem(tempItem);
        result.InsertItem(tempItem);
    }
    
    return result;
}
