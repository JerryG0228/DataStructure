//
//  BubbleSort.h
//  Lab10
//
//  Modified by Jeman Park on 2023/12/5.
//

#ifndef _BUBBLESORT_H
#define _BUBBLESORT_H

#include "Student.h"

void BubbleUp(Student values[], int startIndex, int endIndex) {
    /* Implement the function here (Exercise #10-2) */
    // Bublle up the item at the last place (endIndex) to the proper position
    // This should bubble up a student who has a higher GPA
    // You can access the GPA of each student using values[i].getGPA()
    // Refer to ch.10 (pp. 18-34)
    for(int i =endIndex;i>startIndex;i--){
        if(values[i].getGPA()>values[i-1].getGPA())
            Swap(values[i],values[i-1]);
    }
}

void BubbleSort(Student ary[], int numElems) {
	int current = 0;

	while (current < numElems - 1)
	{
		BubbleUp(ary, current, numElems - 1);
		current++;
	}
}

#endif
