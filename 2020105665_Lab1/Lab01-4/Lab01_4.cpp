//
//  Lab01_4.cpp
//  Lab01
//
//  Created by parkjeman on 2023/09/18.
//

#include <iostream>
#include "unsorted.h"
using namespace std;


int main() {
    // Definition of Unsorted List 'uList'
    UnsortedType uList;
    
    /* Feel free to edit codes below (test with more cases) */
    
    
    
    // Add four elements (4 ItemType) to uList
    uList.InsertItem(ItemType(4));
    uList.InsertItem(ItemType(3));
    uList.InsertItem(ItemType(2));
    uList.InsertItem(ItemType(3));
    
    // Print the current list
    // [4, 3, 2, 3]
    uList.PrintList();
    
    // Delete '7' from uList
    // The program should properly handle the case (not exist)
    uList.DeleteItem(ItemType(7));
    uList.PrintList();
    // [4, 3, 2, 3]
    
    // Delete '7' from uList
    // The program should properly handle the case (duplicated value)
    uList.DeleteItem(ItemType(3));
    uList.PrintList();
    // [4, 2]
    
    return 0;
}
