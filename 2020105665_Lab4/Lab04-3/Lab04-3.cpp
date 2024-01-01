//
//  Lab03-3.cpp
//  Lab03
//
//  Modified by Jeman Park on 2023/10/03.
//

#include <iostream>
#include "SortedType.h"
#include "MergeList.h"
using namespace std;

int main() {

    SortedType<int> s_list_1;
    SortedType<int> s_list_2;
    SortedType<int> result;

    s_list_1.InsertItem(3);
    s_list_1.InsertItem(5);
    s_list_1.InsertItem(7);
    s_list_1.InsertItem(9);
    s_list_1.printList();
    // [    3    5    7    9    ]

    s_list_1.InsertItem(4);
    s_list_1.printList();
    // [    3    4    5    7    9    ]

    s_list_1.InsertItem(2);
    s_list_1.printList();
    // [    2    3    4    5    7    9    ]

    cout << "[DELETE]: " << s_list_1.DeleteItem(2) << endl;
    // [DELETE]: 2

    cout << "[DELETE]: " << s_list_1.DeleteItem(9) << endl;
    // [DELETE]: 9

    cout << "[DELETE]: " << s_list_1.DeleteItem(6) << endl;
    // [DELETE]: -1
    // Not exist

    s_list_1.printList();
    // [    3    4    5    7    ]


    s_list_2.InsertItem(2);
    s_list_2.InsertItem(1);
    s_list_2.InsertItem(6);
    s_list_2.InsertItem(10);
    s_list_2.InsertItem(8);
    s_list_2.printList();
    // [    1    2    6    8    10    ]

    MergeLists(s_list_1, s_list_2, result);
    result.printList();
    // [    1    2    3    4    5    6    7    8    10    ]


    return 0;
}

