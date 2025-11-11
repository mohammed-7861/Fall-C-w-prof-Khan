# Array Operation Assignment

```c++
// Name: Mohammed Saiger
// Course: CISC 192 - C++ Programming
// Date: 11/10/2025
// Assignment: Non-Duplicated Integer Array Operations

#include <iostream>
#include <array>
using namespace std;

// Get a valid integer from user, rejecting decimals and non-numeric input
int getValidInteger(const string& prompt) {
    int number;
    
    while (true) {
        cout << prompt;
        cin >> number;

        // This asks if the input failed. Likely due to a decimal or char input
        // If it did, we clear the error state and ignore the bad input
        if (cin.fail()) {
            cin.clear();                    // Reset the error state
            cin.ignore(1000, '\n');         // Get rid of the bad input
            cout << "Invalid input. Please enter a whole number.\n";
        } else {
            return number;  // numbers are all valid 
        }
    }
}

// Collect 5 unique integers from the user (no duplicates allowed)
// This function uses a loop to ensure each number is unique
void getUniqueNumbers(array<int, 5>& numbers) {
    for (int position = 0; position < 5; position++) {
        bool foundDuplicate;
        
        do {
            foundDuplicate = false;
            
            // Prompt user for the next number
            cout << "Number " << (position + 1) << ": ";
            numbers[position] = getValidInteger("");
            
            // Check if this number was already entered
            for (int previous = 0; previous < position; previous++) {
                if (numbers[position] == numbers[previous]) {
                    cout << " You already entered " << numbers[position] << ". Please choose a different number.\n";
                    foundDuplicate = true;
                    break;
                }
            }
        } while (foundDuplicate);  // Keep asking until we get a unique number
    }
}

// Sorts the array from smallest to largest using bubble sort
void sortAscending(array<int, 5>& numbers) {
    // Bubble sort: repeatedly swap adjacent elements if they're in wrong order
    for (int pass = 0; pass < 4; pass++) {
        for (int current = 0; current < 4 - pass; current++) {
            if (numbers[current] > numbers[current + 1]) { // If current is greater than next
                // Swap them
                int temp = numbers[current]; // Temporary variable to hold the current number
                numbers[current] = numbers[current + 1]; // Move the next number to current position
                numbers[current + 1] = temp; // Place the current number in the next position
            }
        }
    }

    cout << "Array sorted in ascending order: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << "\n";
}

// Sort the array from largest to smallest using bubble sort
void sortDescending(array<int, 5>& numbers) {
    // Same as ascending, but swap when current is less than next
    for (int pass = 0; pass < 4; pass++) {
        for (int current = 0; current < 4 - pass; current++) { // If current is less than next
            if (numbers[current] < numbers[current + 1]) { 
                // Swap them
                int temp = numbers[current]; // Temporary variable to hold the current number
                numbers[current] = numbers[current + 1]; // Move the next number to current position
                numbers[current + 1] = temp; // Place the current number in the next position
            }
        }
    }

    cout << "Array sorted in descending order: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << "\n";
}

// Find and return the largest number in the array
int findLargest(const array<int, 5>& numbers) {
    int largest = numbers[0];  // Start by assuming the first number is largest
    
    // Check the rest of the numbers
    for (int i = 1; i < 5; i++) {
        if (numbers[i] > largest) {
            largest = numbers[i];  // Found a bigger one
        }
    }
    
    return largest;
}

// Show the menu options to the user
void displayMenu() {
    cout << "\n---MENU-----\n";
    cout << "1. Sort from smallest to largest\n";
    cout << "2. Sort from largest to smallest\n";
    cout << "3. Find the largest number\n";
    cout << "4. Exit\n";
}

int main() {
    array<int, 5> userNumbers; // these are the first numbers entered by the user
    array<int, 5> originalNumbers; //originalNumbers is a copy of userNumbers to preserve original order

    // Get the 5 unique numbers from the user
    cout << "Please enter 5 unique integers:\n";
    getUniqueNumbers(userNumbers);
    originalNumbers = userNumbers;  // Keep a copy of the original

    // Show menu and get user's choice
    displayMenu();
    int choice = getValidInteger("\nWhat would you like to do? (1-4): ");

    // Handle the user's choice
    switch (choice) {
        case 1: {
            // Make a copy so we don't change the original
            array<int, 5> temporaryCopy = originalNumbers; //uses a temporary array to preserve original array
            sortAscending(temporaryCopy); // Sort and displays
            break;
        }
        case 2: {
            array<int, 5> temporaryCopy = originalNumbers; 
            sortDescending(temporaryCopy); 
            break;
        }
        case 3: {
            cout << "The largest number is: " << findLargest(originalNumbers) << "\n";
            break;
        }
        case 4:
            cout << "Exiting Program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
    }

    cout << "\nProgram finished.\n";
    return 0;
}
```
