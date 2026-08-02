// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// Function to calculate the sum of the array
int calcSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to calculate the average
// (Returns a double to handle decimal values like 4.6)
double calcAverage(int arr[], int size) {
    int sum = calcSum(arr, size);
    return (double)sum / size;
}

// Function to find the maximum value
int findMax(int arr[], int size) {
    int maxVal = arr[0]; // Assume the first element is the largest initially
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Function to find the minimum value
int findMin(int arr[], int size) {
    int minVal = arr[0]; // Assume the first element is the smallest initially
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int main() {
    int n;
    
    cout << "How many numbers? ";
    cin >> n;
    
    // Check for invalid input
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 0; // Stop the program
    }
    
    // Dynamically allocate memory for the array based on user input size
    int* arr = new int[n];
    
    // Populate the array
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> arr[i];
    }
    
    // Output the results using the functions
    cout << "\nResults:" << endl;
    cout << "Sum:     " << calcSum(arr, n) << endl;
    cout << "Average: " << calcAverage(arr, n) << endl;
    cout << "Maximum: " << findMax(arr, n) << endl;
    cout << "Minimum: " << findMin(arr, n) << endl;
    
    // Free the dynamically allocated memory
    delete[] arr;
    
    return 0;
}