//
//  SquareMatrix.cpp
//  Lab01
//
//  Modified by Jeman Park on 2023/09/18.
//

#include <iostream>
#include "SquareMatrix.h"

/* DO NOT CHANGE file/function/variable/class names and parameters */
/* But, you can add functions if necessary */


// Reset all values of SqaureMatrix with '0'
void SquareMatrix::MakeEmpty()
{
    /* Implement the function here */
    /* Return nothing (void) */
    /* Hint: it needs double 'for' loops to set all values (matrix[i][j]) in 2d-array */
    int i, j = 0;
    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

// Print all values of SquareMatrix in a matrix format (for debug purpose)
void SquareMatrix::printMatrix()
{
    /* You don't have to do anything with this */
    /* Just use it when you want to print the values of 2-d matrix */
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// Set SqaureMatrix[i][j] with 'value'
void SquareMatrix::StoreValue(int i , int j , int value)
{
    /* Implement the function here */
    /* Return nothing (void) */
    /* Hint: set matrix[i][j] to 'value' */
    matrix[i][j] = value;
}

// Add two matrices 'this' and input 'm'.
// Store the added result into 'result' and return it.
SquareMatrix SquareMatrix::Add(SquareMatrix m)
{
    /* Implement the function here */
    /* Return SquareMatrix (result of sum) */
    /* Hint: result[i][j] = matrix[i][j] + m.matrix[i][j] */
    SquareMatrix result;
    
    for (int i = 0; i < MATRIX_SIZE ; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            result.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
        }
    }
    
    return result;
}

// Subtract input 'm' from matrix 'this'.
// Store the added result into 'result' and return it.
SquareMatrix SquareMatrix::Subtract(SquareMatrix m)
{
    /* Implement the function here */
    /* Return SquareMatrix (result of subtract) */
    /* Hint: result[i][j] = matrix[i][j] - m.matrix[i][j] */
    SquareMatrix result;
    
    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            result.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
        }
    }
    
    return result;
}

// Copy 'm' into 'this'.
void SquareMatrix::Copy(SquareMatrix m) 
{
    /* Implement the function here */
    /* Return nothing (void) */
    /* Hint: Copy all values of m.matrix to matrix */
    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            matrix[i][j] =  m.matrix[i][j];
        }
    }
    
}
