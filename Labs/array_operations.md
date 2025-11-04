# Array Operation Assignment

```c++
//Name: Mohammed Saiger
//Course: CISC 192 - C++ Programming
//Date: 10/28/2025
//Assignment: Non-Duplicated Integer Array Operations


#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int, 5> arr; // array to hold 5 numbers
    bool validInput = false;

    // Keep asking for input until we get 5 unique numbers
    while (!validInput) {
        cout << "Enter 5 numbers:\n";
        for (int i = 0; i < 5; ++i) {
            cout << "Number " << (i + 1) << ": "; 
            cin >> arr[i];
        }
        
        // Assume valid input initially
        validInput = true;
        
        // Check for duplicates by using nested loops
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (arr[i] == arr[j]) {  // if a number is equal to another number than a duplicate is found

                    cout << "Please enter 5 new numbers.\n";
                    validInput = false;
                    break;  // exit inner loop
                }
            }

            if (!validInput) break;  // exit outer loop
        }
    }

    // Menu (runs once)
    cout << "\nMenu:\n";
    cout << "1. Sort Ascending\n";
    cout << "2. Sort Descending\n";
    cout << "3. Find Max Number\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            // Sort Ascending using bubble sort
            for (int i = 0; i < 4; ++i) {  // 4 passes
                for (int j = 0; j < 4 - i; ++j) {   // compare adjacent
                    if (arr[j] > arr[j + 1]) {   // swap if out of order
                        int temp = arr[j];   // swap using a temporary variable
                        arr[j] = arr[j + 1];   // swap
                        arr[j + 1] = temp;   // swap
                    }
                }

            }
            cout << "Sorted in Ascending order: ";
            for (int n : arr) cout << n << " ";
            cout << endl;
            break;
        }

        case 2: {
            // Sort Descending using bubble sort
            for (int i = 0; i < 4; ++i) {  // 4 passes
                for (int j = 0; j < 4 - i; ++j) { // compare adjacent
                    if (arr[j] < arr[j + 1]) { // swap if out of order
                        int temp = arr[j]; // swap using a temporary variable
                        arr[j] = arr[j + 1]; // swap
                        arr[j + 1] = temp; // swap
                    }
                }
            }

            cout << "Sorted in Descending order: "; // display sorted array
            for (int n : arr) cout << n << " ";  // display numbers
            cout << endl;
            break;
        }

        case 3: {
            // Find Max Number
            int maxNum = arr[0]; // assume first is max
            for (int i = 1; i < 5; ++i) {  // check remaining elements
                if (arr[i] > maxNum)  // found new max
                    maxNum = arr[i];  // update max
            }
            cout << "Max Number: " << maxNum << endl; 
            break;
        }

        case 5:
            cout << "Exiting program.";
            return 0;

        default:
            cout << "Invalid choice.";
            break;
    }
    cout << "Program complete";
    return 0;
}
```
