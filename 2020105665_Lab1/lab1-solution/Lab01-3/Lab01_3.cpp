//
//  Lab01-3.cpp
//  Lab01
//
//  Modified by Jeman Park on 2023/09/18.
//

#include <iostream>
#include "SquareMatrix.h"
using namespace std;

int main() {
    // Declaration of 4 SquareMatrix objects.
    SquareMatrix A;
    SquareMatrix B;
    SquareMatrix C;
    SquareMatrix D;
    
    
    // MATRIX_SIZE is defined in SquareMatrix.h (=10)
    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            // Initialize (MATRIX_SIZE) x (MATRIX_SIZE)-sized matrix with '2'
            A.StoreValue(i, j, 2);
        }
    }
    
    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            // Initialize (MATRIX_SIZE) x (MATRIX_SIZE)-sized matrix with '1'
            B.StoreValue(i, j, 1);
        }
    }
    
    /* Feel free to edit codes below (test with more cases) */
    
    cout << "A: " << endl;
    A.printMatrix();
    // This should print     ---- n ----
    //                     | 2 2 .... 2 2
    //                     | 2 2 .... 2 2
    //                     n ... .... ...
    //                     | 2 2 .... 2 2
    //                     | 2 2 .... 2 2
    
    cout << "B: " << endl;
    B.printMatrix();
    // This should print     ---- n ----
    //                     | 1 1 .... 1 1
    //                     | 1 1 .... 1 1
    //                     n ... .... ...
    //                     | 1 1 .... 1 1
    //                     | 1 1 .... 1 1
    
    cout << "A add B: " << endl;
    C = A.Add(B);
    C.printMatrix();
    // This should print     ---- n ----
    //                     | 3 3 .... 3 3
    //                     | 3 3 .... 3 3
    //                     n ... .... ...
    //                     | 3 3 .... 3 3
    //                     | 3 3 .... 3 3
    
    cout << "A subtract B: " << endl;
    C = A.Subtract(B);
    C.printMatrix();
    // This should print     ---- n ----
    //                     | 1 1 .... 1 1
    //                     | 1 1 .... 1 1
    //                     n ... .... ...
    //                     | 1 1 .... 1 1
    //                     | 1 1 .... 1 1
    
    cout << "copy B into D: " << endl;
    D.Copy(B);
    D.printMatrix();
    // This should print     ---- n ----
    //                     | 2 2 .... 2 2
    //                     | 2 2 .... 2 2
    //                     n ... .... ...
    //                     | 2 2 .... 2 2
    //                     | 2 2 .... 2 2
    
    cout << "empty A: " << endl;
    A.MakeEmpty();
    A.printMatrix();
    // This should print     ---- n ----
    //                     | 0 0 .... 0 0
    //                     | 0 0 .... 0 0
    //                     n ... .... ...
    //                     | 0 0 .... 0 0
    //                     | 0 0 .... 0 0
    
    return 0;
}
