//
//  binary_search.cpp
//  Lab02-1
//
//  Modifieid by Jeman Park on 2023/09/25.
//

#include "binary_search.h"


int binary_search(int arr[], int sizeOfArray, int value) {
    // Perform binary search on arr[] to find "value"
    // Return the index of "value" if exists.
    // otherwise, return -1
    int index = -1;
    
    
    /* Implement the function here */
    int midPoint;
    int first = 0;
    int last = (sizeOfArray - 1);
    bool moreToSearch = (first <= last);
    bool found = false;
    
    while (moreToSearch && !found) {
        
        midPoint = (first + last) / 2;
        
        if (arr[midPoint] > value) {
            last = midPoint - 1;
            moreToSearch = (first <= last);
        }
        else if (arr[midPoint] < value) {
            first = midPoint + 1;
            moreToSearch = (first <= last);
        }
        else {
            found = true;
            index = midPoint;
            break;
        }
    }
    
    return index;
}

int binary_search_min(int arr[], int sizeOfArray, int value) {
    // Perform binary search MIN on arr[] to find "value"
    // 1. Return the index of "value" if "value" exists.
    // EX) arr = [ 1, 3, 5]
    // binary_search_min(arr, 3, 3) -> 1
    // 2. Return the index of minimum value which is bigger than "value"
    // binary_search_min(arr, 3, 2) -> 1
    // binary_search_min(arr, 3, 4) -> 2
    // 3. Return (max_index + 1) if "value" is bigger than any arr[] values.
    // binary_search_min(arr, 3, 7) -> 3
    
    int index = -1;
    
    /* Implement the function here */
    
    int midPoint;
    int first = 0;
    int last = (sizeOfArray - 1);
    bool moreToSearch = (first <= last);
    bool found = false;
    
    
    while (moreToSearch && !found) {
        
        midPoint = (first + last) / 2;
        
        if (arr[midPoint] > value) {
            last = midPoint - 1;
            moreToSearch = (first <= last);
        }
        else if (arr[midPoint] < value) {
            first = midPoint + 1;
            moreToSearch = (first <= last);
        }
        else {
            found = true;
            index = midPoint;
            break;
        }
    }
    
    if (!found){
        index = first;
    }
    
    return index;
}

int binary_search_max(int arr[], int sizeOfArray, int value) {
    // Perform binary search MAX on arr[] to find "value"
    // 1. Return the index of "value" if "value" exists.
    // EX) arr = [ 1, 3, 5]
    // binary_search_max(arr, 3, 5) -> 2
    // 2. Return the index of maximum value which is smaller than "value"
    // binary_search_max(arr, 3, 4) -> 1
    // binary_search_max(arr, 3, 6) -> 2
    // 3. Return -1 if "value" is smaller than any arr[] values.
    // binary_search_max(arr, 3, 0) -> -1
    
    int index = -1;
    
    /* Implement the function here */
    
    int midPoint;
    int first = 0;
    int last = (sizeOfArray - 1);
    bool moreToSearch = (first <= last);
    bool found = false;
    
    
    while (moreToSearch && !found) {
        
        midPoint = (first + last) / 2;
        
        if (arr[midPoint] > value) {
            last = midPoint - 1;
            moreToSearch = (first <= last);
        }
        else if (arr[midPoint] < value) {
            first = midPoint + 1;
            moreToSearch = (first <= last);
        }
        else {
            found = true;
            index = midPoint;
            break;
        }
    }
    
    if (!found){
        index = last;
    }
    
    return index;
}
