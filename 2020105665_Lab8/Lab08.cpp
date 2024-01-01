//
//  Lab08.cpp
//  Lab08
//
//  Modified by Jeman Park on 2023/11/21.
//


#include <iostream>
using namespace std;
#include "PQType.h"

int main() {
    // Exercise #1 (1) (MAX_HEAP)
    PQType<int> pq_max(16, -1, MAX_HEAP);

    pq_max.Enqueue(5);
    pq_max.Enqueue(6);
    pq_max.Enqueue(3);
    pq_max.Enqueue(2);
    pq_max.Enqueue(7);
    pq_max.Enqueue(8);
    pq_max.Enqueue(4);

    cout << "[MAX_HEAP]" << endl;
    pq_max.Print();
    //                     8
    //
    //          6                    7
    //
    //  2            5            3            4
        
    int ret;
    pq_max.Dequeue(ret);
    cout << "[Max Heap Dequeued]: "<< ret << endl << endl;
    // [Max Heap Dequeued]: 8
    pq_max.Print();
    //                     7
    //
    //          6                    4
    //
    //  2            5            3
    
    pq_max.Dequeue(ret);
    cout << "[Max Heap Dequeued]: "<< ret << endl << endl;
    // [Max Heap Dequeued]: 7
    pq_max.Print();
    //                     6
    //
    //          5                    4
    //
    //  2            3
    
    
    
    
    // Exercise #1 (2) (MIN_HEAP)
    PQType<int> pq_min(16, -1, MIN_HEAP);

    pq_min.Enqueue(5);
    pq_min.Enqueue(6);
    pq_min.Enqueue(3);
    pq_min.Enqueue(2);
    pq_min.Enqueue(7);
    pq_min.Enqueue(8);
    pq_min.Enqueue(4);

    cout << "[MIN_HEAP]" << endl;
    pq_min.Print();
    //                     2
    //
    //          3                    4
    //
    //  6            7            8            5
    
    
    
    pq_min.Dequeue(ret);
    cout << "[Min Heap Dequeued]: "<< ret << endl << endl;
    // [Min Heap Dequeued]: 2
    pq_min.Print();
    //                     3
    //
    //          5                    4
    //
    //  6            7            8
    
    pq_min.Dequeue(ret);
    cout << "[Min Heap Dequeued]: "<< ret << endl << endl;
    // [Min Heap Dequeued]: 3
    pq_min.Print();
    //                     4
    //
    //          5                    8
    //
    //  6            7
    
    
    
    // Exercise #2 (MAX_HEAP_NONRECURSIVE)
    PQType<int> pq_max_nonrecursive(16, -1, MAX_NONRECURSIVE);
    
    pq_max_nonrecursive.Enqueue(5);
    pq_max_nonrecursive.Enqueue(6);
    pq_max_nonrecursive.Enqueue(3);
    pq_max_nonrecursive.Enqueue(2);
    pq_max_nonrecursive.Enqueue(7);
    pq_max_nonrecursive.Enqueue(8);
    pq_max_nonrecursive.Enqueue(4);

    pq_max_nonrecursive.Print();
    //                     8
    //
    //          6                    7
    //
    //  2            5            3            4
    
    
    pq_max_nonrecursive.Dequeue(ret);
    cout << "[NON_Recur Max Heap Dequeued]: "<< ret << endl << endl;
    // [NON_Recur Max Heap Dequeued]: 8
    pq_max_nonrecursive.Print();
    //                     7
    //
    //          6                    4
    //
    //  2            5            3
    
    
    pq_max_nonrecursive.Dequeue(ret);
    cout << "[NON_Recur Max Heap Dequeued]: "<< ret << endl << endl;
    // [NON_Recur Max Heap Dequeued]: 7
    pq_max_nonrecursive.Print();
    //                     6
    //
    //          5                    4
    //
    //  2            3
    
    
    
    // Exercise #3 (SORTED_LIST)
    PQType<int> pq_sorted(16, -1, SORTED_LIST);
    
    pq_sorted.Enqueue(5);
    pq_sorted.Enqueue(6);
    pq_sorted.Enqueue(3);
    pq_sorted.Enqueue(2);
    pq_sorted.Enqueue(7);
    pq_sorted.Enqueue(8);
    pq_sorted.Enqueue(4);
    
    pq_sorted.Print();
    // [    8    7    6    5    4    3    2    ]
    cout << endl;

    pq_sorted.Dequeue(ret);
    cout << "[SortedList Dequeued]: "<< ret << endl;
    // [SortedList Dequeued]: 8
    pq_sorted.Print();
    // [    7    6    5    4    3    2    ]
    cout << endl;
    
    pq_sorted.Dequeue(ret);
    cout << "[SortedList Dequeued]: "<< ret << endl;
    // [SortedList Dequeued]: 7
    pq_sorted.Print();
    // [    6    5    4    3    2    ]
    cout << endl;

    return 0;
}

