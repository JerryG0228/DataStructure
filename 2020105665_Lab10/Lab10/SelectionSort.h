//
//  SelectionSort.h
//  Lab10
//
//  Modified by Jeman Park on 2023/12/5.
//

#ifndef _SELECTIONSORT_H
#define _SELECTIONSORT_H

#include "Student.h"

int MinIndex(Student values[], int startIndex, int endIndex) {
    int indexOfMin = startIndex;
    /* Implement the function here (Exercise #10-1) */
    // Find the index of minimum element ("name of student")
    // You can access the name of each student using values[i].getName()
    // Refer to ch.10 (pp. 3-17)

    for (int i = startIndex + 1; i <= endIndex; i++) {
        int idx = 0;
        while (values[indexOfMin].getName()[idx] == values[i].getName()[idx]) {
            idx++;
        }
        if (values[indexOfMin].getName()[idx] > values[i].getName()[idx])
            indexOfMin = i;
    }


    return indexOfMin;
}

void SelectionSort(Student ary[], int numElems) {

    int endIndex = numElems - 1;
    for (int current = 0; current < endIndex; current++) {
        Swap(ary[current], ary[MinIndex(ary, current, endIndex)]);
    }
}

#endif
