#include <iostream>
#include "TreeType.h"
using namespace std;

//#define PREDECESSOR 1
//#define SUCCESSOR 2

int main() {
	TreeType BST;

    // Exercise #1
    BST.InsertItem(5);
    BST.InsertItem(3);
    BST.InsertItem(4);
    BST.InsertItem(9);
    BST.InsertItem(7);
    BST.InsertItem(6);
    BST.InsertItem(12);
    BST.InsertItem(8);
    BST.InsertItem(20);
    BST.InsertItem(11);

    
    cout << "BST: " << endl;
    BST.Print();
    //                      5
    //
    //           3                        9
    //
    //                4              7                12
    //
    //                           6        8        11      20
    

    // Exercise #2
    cout << "Length: " << BST.LengthIs() << endl << endl;
    // Length: 10


    TreeType BST2 = BST;

    // Exercise #3
    BST.DeleteItem(9, PREDECESSOR);
    cout << "BST1: " << endl;
    BST.Print();
    //                      5
    //
    //           3                        9
    //
    //                4              7                12
    //
    //                           6                 11      20


    BST2.DeleteItem(7, SUCCESSOR);
    cout << "BST2: " << endl;
    BST2.Print();
    //                      5
    //
    //           3                          11
    //
    //                4              7                12
    //
    //                           6        8                20




    // Exercise #4
    TreeType BST3;
    BST3.InsertItem(6);
    BST3.InsertItem(4);
    BST3.InsertItem(5);
    BST3.InsertItem(9);
    BST3.InsertItem(7);

    cout << "BST3: " << endl;
    BST3.Print();
    //                      6
    //
    //           4                          9
    //
    //                5              7


    TreeType NonBST;

    NonBST.InsertItemNonBST(6);
    NonBST.InsertItemNonBST(4);
    NonBST.InsertItemNonBST(5);
    NonBST.InsertItemNonBST(9);
    NonBST.InsertItemNonBST(7);

    cout << "NON BST: " << endl;
    NonBST.Print();
    //                      6
    //
    //           4                          5
    //
    //       9        7

	return 0;
}
