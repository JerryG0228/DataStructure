//
//  Lab01_5.cpp
//  Lab01
//
//  Modified by Jeman Park on 2023/09/18.
//

#include <iostream>
#include "sorted.h"
#include "mergeList.h"
using namespace std;


int main() {
    
    SortedType s_list1, s_list2, s_list3;

    /* Feel free to edit codes below (test with more cases) */
    
    // add 3 items into s_list1
    s_list1.InsertItem(ItemType(1));
    s_list1.InsertItem(ItemType(3));
    s_list1.InsertItem(ItemType(3));
    s_list1.InsertItem(ItemType(4));
    s_list1.InsertItem(ItemType(4));
    s_list1.InsertItem(ItemType(6));
    
    // add 2 items into s_list2
    s_list2.InsertItem(ItemType(2));
    s_list2.InsertItem(ItemType(4));
    s_list2.InsertItem(ItemType(5));
    
    // print each list
    // it prints in an ordered manner
    // Ex) s_list1 = [1, 3, 5]
    //     s_list2 = [4, 6]
    s_list1.PrintList();
    s_list2.PrintList();
    
    // merge two lists
    s_list3 = MergeList(s_list1, s_list2);
    
    // print the result list
    // Ex) [1, 3, 4, 5, 6]
    s_list3.PrintList();

    return 0;

}
