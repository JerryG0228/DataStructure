//
//  InsertionSort.h
//  Lab10
//
//  Modified by Jeman Park on 2023/12/5.
//

#ifndef _INSERTIONSORT_H
#define _INSERTIONSORT_H

#include "Student.h"

void InsertItem(Student values[], int startIndex, int endIndex) {
    /* Implement the function here (Exercise #10-3) */
    // Perform "InsertItem" to move the key item (at "endIndex") to the proper position
    // This should move up a student who has a lower ID
    // You can access the ID of each student using values[i].getID()
    // Refer to ch.10 (pp. 36-54)
    int idx = endIndex;

    while (idx > startIndex && values[idx].getID() < values[idx - 1].getID()) {
        Swap(values[idx], values[idx - 1]);
        idx--;
    }
}

void InsertionSort(Student ary[], int numElems) {
    for (int count = 0; count < numElems; count++)
        InsertItem(ary, 0, count);
}


#endif
