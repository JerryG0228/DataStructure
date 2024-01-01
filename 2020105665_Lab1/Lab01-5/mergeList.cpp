//
//  mergeList.cpp
//  Lab01
//
//  Created by parkjeman on 2023/09/18.
//


/* DO NOT CHANGE file/function/variable/class names and parameters */
/* But, you can add functions if necessary */

#include "mergeList.h"

SortedType MergeList(SortedType list1, SortedType list2){
    /* Implement the function here */
    /* Return Sorted List (result) */
    SortedType result = list1;
    ItemType n;
    
    list2.ResetList();
    for(int j=0 ; j<list2.LengthIs() ; j++)
    {
        list2.GetNextItem(n);
        result.InsertItem(n);
    }

    return result;
}
