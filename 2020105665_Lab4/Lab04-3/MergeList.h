//
//  MergeList.h
//  Lab04
//
//  Created by parkjeman on 2023/10/17.
//

#ifndef MERGELIST_H
#define MERGELIST_H

#include <iostream>
#include "SortedType.h"

template <class ItemType>
void MergeLists(SortedType<ItemType>& list1, SortedType<ItemType>& list2, SortedType<ItemType>& result) {
    
    /* Implement the function here */
    // Merge two lists into "result" list in an ordered manner
    // list1 = [1, 5, 7]
    // list2 = [2, 4, 6]
    // Merge -> result [1, 2, 4, 5, 6, 7]


    ItemType it;
    list1.ResetList();
    list2.ResetList();
    for(int i =0; i<list1.LengthIs();i++){
        list1.GetNextItem(it);
        result.InsertItem(it);
    }
    for(int i =0; i<list2.LengthIs();i++){
        list2.GetNextItem(it);
        result.InsertItem(it);
    }
}

#endif
