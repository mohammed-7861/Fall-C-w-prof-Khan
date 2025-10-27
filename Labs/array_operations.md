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
    int numbers[5];
    array<int, 5> arr;

    while (true) {  // repeat input until valid (no duplicates)
        bool duplicateFound = false;

        cout << "Enter 5 unique numbers (separated by commas): ";
        char comma;

        for (int i = 0; i < 5; ++i) {
            cin >> numbers[i];
            arr[i] = numbers[i];

            if (i < 4) cin >> comma;  // read comma for first 4 numbers

            // Check for duplicates among entered numbers
            for (int j = 0; j < i; ++j) {
                if (numbers[i] == numbers[j]) {
                    cout << "Duplicate number found. Please re-enter all 5 numbers.\n\n";
                    duplicateFound = true;
                    break;
                }
            }

            if (duplicateFound) break;
        }

        if (!duplicateFound) break;  // valid input → exit loop

        // If duplicate found, clear cin manually (simple way without <limits>)
        cin.ignore(10000, '\n');  // dump leftover input
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
            // Sort ascending using bubble sort
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
            // Sort descending using bubble sort
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
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice.\n";
            break;
    }

    cout << "Program finished.\n";
    return 0;
}
```


