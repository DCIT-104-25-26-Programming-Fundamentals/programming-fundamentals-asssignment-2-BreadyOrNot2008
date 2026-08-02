// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// =============================================================================
// HELPER FUNCTIONS
// =============================================================================

// Helper function to print a matrix in a neat grid
void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Helper function to read matrix elements from the user
void inputMatrix(int matrix[10][10], int rows, int cols, string name) {
    cout << "Enter elements for " << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// =============================================================================
// MATRIX OPERATIONS
// =============================================================================

// PART A — Transpose a Matrix
void transposeMatrix(int matrix[10][10], int rows, int cols) {
    int transposed[10][10];
    
    // Rows become columns, columns become rows
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed, cols, rows); // Note the swapped dimensions
}

// PART B — Add Two Matrices
void addMatrices(int matA[10][10], int matB[10][10], int rows, int cols) {
    int result[10][10];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
    
    cout << "\nSum Matrix:" << endl;
    printMatrix(result, rows, cols);
}

// PART C — Multiply Two Matrices
void multiplyMatrices(int matA[10][10], int matB[10][10], int rowsA, int colsA, int colsB) {
    int result[10][10] = {0}; // Initialize all elements to 0
    
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
    
    cout << "\nProduct Matrix:" << endl;
    printMatrix(result, rowsA, colsB);
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================

int main() {
    // Variables for matrix sizes
    int r1, c1, r2, c2;
    int matrixA[10][10], matrixB[10][10];

    // ---------------------------------------------------------
    // PART A TEST
    // ---------------------------------------------------------
    cout << "--- PART A: TRANSPOSE ---" << endl;
    cout << "Enter number of rows: ";
    cin >> r1;
    cout << "Enter number of columns: ";
    cin >> c1;
    
    inputMatrix(matrixA, r1, c1, "Matrix A");
    
    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrixA, r1, c1);
    
    transposeMatrix(matrixA, r1, c1);
    
    // ---------------------------------------------------------
    // PART B TEST
    // ---------------------------------------------------------
    cout << "\n--- PART B: ADDITION ---" << endl;
    cout << "Enter dimensions for the two matrices to add (they must be the same)." << endl;
    cout << "Enter number of rows: ";
    cin >> r2;
    cout << "Enter number of columns: ";
    cin >> c2;
    
    inputMatrix(matrixA, r2, c2, "Matrix 1");
    inputMatrix(matrixB, r2, c2, "Matrix 2");
    
    addMatrices(matrixA, matrixB, r2, c2);

    // ---------------------------------------------------------
    // PART C TEST
    // ---------------------------------------------------------
    cout << "\n--- PART C: MULTIPLICATION ---" << endl;
    cout << "Matrix A dimensions:" << endl;
    cout << "Enter number of rows: ";
    cin >> r1;
    cout << "Enter number of columns: ";
    cin >> c1;
    inputMatrix(matrixA, r1, c1, "Matrix A");

    cout << "\nMatrix B dimensions (Rows MUST match Matrix A's columns (" << c1 << ")): " << endl;
    cout << "Enter number of rows: ";
    cin >> r2;
    
    if (r2 != c1) {
        cout << "Error: Matrix B rows (" << r2 << ") must equal Matrix A columns (" << c1 << ") for multiplication." << endl;
    } else {
        cout << "Enter number of columns: ";
        cin >> c2;
        inputMatrix(matrixB, r2, c2, "Matrix B");
        
        multiplyMatrices(matrixA, matrixB, r1, c1, c2);
    }

    return 0;
}