#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include "PartC.h"

using namespace std;

void showMenu();

int main()
{
    int taskslimit = 5;
    TaskManager taskManager(taskslimit); // Create TaskManager with capacity
    int choice;
    string description;
    int id;

    do
    {
        showMenu(); // Display menu
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) // Check for invalid input
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) // Handle user choice
        {
        case 1:
            cout << "Enter task description: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            getline(cin, description);                           // Get full line input
            taskManager.addTask(description);                    // Add task
            break;
        case 2:
            cout << "Enter task ID to remove: ";
            cin >> id;
            taskManager.removeTask(id); // Remove task
            break;
        case 3:
            taskManager.listTasks(); // List tasks
            break;
        case 4:
            cout << "Enter task ID to mark as completed: ";
            cin >> id;
            taskManager.markCompleted(id); // Mark task as completed
            break;
        case 5:
            cout << "Exiting Program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5); // Continue until user chooses to exit

    return 0;
}