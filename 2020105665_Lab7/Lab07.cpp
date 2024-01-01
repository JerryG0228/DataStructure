//
//  Lab07-1.cpp
//  Lab07
//
//  Modified by Jeman Park on 2023/11/14.
//

#include <iostream>
#include "TreeType.h"
using namespace std;


int main() {
    
    TreeType tree;
    
    tree.InsertItem(5);
    tree.InsertItem(3);
    tree.InsertItem(4);
    tree.InsertItem(9);
    tree.InsertItem(7);
    tree.InsertItem(6);
    tree.InsertItem(12);
    tree.InsertItem(8);
    tree.InsertItem(20);
    tree.InsertItem(11);
    tree.InsertItem(2);
    tree.InsertItem(1);
    
    tree.Print();
    //                            5
    //
    //              3                             9
    //
    //       2             4             7                12
    //
    //  1                             6        8        11      20
    
    
    
    /* Exercise 7-1 (Tree Traversal) */
    bool finished = false;
    ItemType temp;
    
    tree.ResetTree(IN_ORDER);
    cout << "[IN_ORDER]: ";
    while(!finished){
        tree.GetNextItem(temp, IN_ORDER, finished);
        if(finished) break;
        cout << temp << "\t";
    }
    cout << endl;
    // [IN_ORDER]: 1    2    3    4    5    6    7    8    9    11    12    20
    
    finished = false;
    
    tree.ResetTree(PRE_ORDER);
    cout << "[PRE_ORDER]: ";
    while(!finished){
        tree.GetNextItem(temp, PRE_ORDER, finished);
        if(finished) break;
        cout << temp << "\t";
    }
    cout << endl;
    // [PRE_ORDER]: 5    3    2    1    4    9    7    6    8    12    11    20
    
    
    finished = false;
    
    tree.ResetTree(POST_ORDER);
    cout << "[POST_ORDER]: ";
    while(!finished){
        tree.GetNextItem(temp, POST_ORDER, finished);
        if(finished) break;
        cout << temp << "\t";
    }
    cout << endl;
    // [POST_ORDER]: 1    2    4    3    6    8    7    11    20    12    9    5
    
    
    
    
    /* Exercise 7-2 (Iterative ancester searching) */
    cout << endl << endl;
    QueType ret = tree.Anscestors_iterative(11);
    
    if(!ret.IsEmpty()){
        ret.printQueue();
    }
    else{
        cout << "[EMPTY QUEUE]: Item NOT found" << endl;
    }
    // QUEUE: 5    9    12
    
    
    
    ret = tree.Anscestors_iterative(14);
    
    if(!ret.IsEmpty()){
        ret.printQueue();
    }
    else{
        cout << "[EMPTY QUEUE]: Item NOT found" << endl;
    }
    // [EMPTY QUEUE]: Item NOT found
    
    
    
    /* Exercise 7-3 (Recursive ancester searching) */
    cout << endl << endl;
    StackType ret_recursive = tree.Ancestors_re(6);
    if(!ret_recursive.IsEmpty()){
        ret_recursive.printStack();
    }
    else{
        cout << "[EMPTY STACK]: Item NOT found" << endl;
    }
    // STACK: 5    9    12
    
    
    ret_recursive = tree.Ancestors_re(14);
    if(!ret_recursive.IsEmpty()){
        ret_recursive.printStack();
    }
    else{
        cout << "[EMPTY STACK]: Item NOT found" << endl;
    }
    // [EMPTY STACK]: Item NOT found

    return 0;
}
