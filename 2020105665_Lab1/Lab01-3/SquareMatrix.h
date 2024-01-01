//
//  SquareMatrix.h
//  Lab01
//
//  Modified by Jeman Park on 2023/09/18.
//

#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#define MATRIX_SIZE 10

/* DO NOT CHANGE file/function/variable/class names and parameters */
/* But, you can add functions if necessary */

class SquareMatrix
{
    
public:
    void MakeEmpty();
    void printMatrix();
    void StoreValue(int, int, int);
    SquareMatrix Add(SquareMatrix m);
    SquareMatrix Subtract(SquareMatrix m);
    void Copy(SquareMatrix m);
    
    
private:
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
};

#endif
