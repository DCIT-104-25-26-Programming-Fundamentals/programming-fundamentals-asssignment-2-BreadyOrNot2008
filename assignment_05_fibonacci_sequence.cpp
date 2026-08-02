// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// =============================================================================
// PART A — Print the First N Terms
// =============================================================================
void printFibonacci(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }

    cout << "Fibonacci sequence: ";
    
    int a = 0;
    int b = 1;
    
    // Print the first term
    if (n >= 1) {
        cout << a;
    }
    // Print the second term
    if (n >= 2) {
        cout << " " << b;
    }
    
    // Calculate and print the remaining terms using a loop
    for (int i = 3; i <= n; i++) {
        int nextTerm = a + b;
        cout << " " << nextTerm;
        
        // Shift values for the next iteration
        a = b;
        b = nextTerm;
    }
    cout << endl;
}

// =============================================================================
// PART B — Check if a Number Belongs to the Sequence
// =============================================================================
bool isFibonacci(int target) {
    // Fibonacci numbers in this standard sequence are never negative
    if (target < 0) {
        return false;
    }
    
    int a = 0;
    int b = 1;
    
    // Check if the target is one of the starting numbers
    if (target == a || target == b) {
        return true;
    }
    
    int nextTerm = a + b;
    
    // Loop until we either find the target or exceed it
    while (nextTerm <= target) {
        if (nextTerm == target) {
            return true;
        }
        
        // Shift values forward
        a = b;
        b = nextTerm;
        nextTerm = a + b;
    }
    
    // If the loop finishes and we exceeded the target without matching it
    return false;
}

// =============================================================================
// MAIN FUNCTION
// =============================================================================
int main() {
    int n, numToCheck;
    
    cout << "--- PART A ---" << endl;
    cout << "How many terms? ";
    cin >> n;
    
    // Call function for Part A
    printFibonacci(n);
    
    cout << "\n--- PART B ---" << endl;
    cout << "Enter a number to check: ";
    cin >> numToCheck;
    
    // Call function for Part B
    if (isFibonacci(numToCheck)) {
        cout << numToCheck << " is a Fibonacci number." << endl;
    } else {
        cout << numToCheck << " is NOT a Fibonacci number." << endl;
    }
    
    return 0;
}