#include <iostream>
#include "PartB.h"
#include <limits>
#include <string>
using namespace std;
void showMenu();

int main()
{
    int taskCount = 0;
    int capacity = 5;
    Task *tasks = new Task[capacity]; // Initialize the array with a fixed capacity

    int choice;
    do
    {
        showMenu(); // Display the menu
        cin >> choice;

        if (cin.fail()) // Check for invalid input
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from the menu." << endl;
            continue;
        }

        switch (choice) // Handle user input
        {
        case 1: // Add a new task
        {
            cout << "You selected Option 1." << endl;
            string desc;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, desc);
            addTask(tasks, taskCount, capacity, desc);
            break;
        }

        case 2: // Remove a task
        {
            cout << "You selected Option 2." << endl;
            int id;
            cout << "Enter task ID to remove: ";
            cin >> id;
            removeTask(tasks, taskCount, id);
            break;
        }

        case 3: // List all tasks
        {
            cout << "You selected Option 3." << endl;
            listTasks(tasks, taskCount);
            break;
        }

        case 4: // Mark a task as completed
        {
            cout << "You selected Option 4." << endl;
            int id;
            cout << "Enter task ID to mark as completed: ";
            cin >> id;
            bool found = false; // Flag to check if the task is found
            for (int i = 0; i < taskCount; ++i)
            {
                if (tasks[i].getId() == id) // Check if the task ID matches the user input
                {
                    tasks[i].markCompleted(); // Mark the task as completed
                    cout << "Task " << id << " marked as completed." << endl;
                    found = true;
                    break;
                }
            }
            if (!found) // If the task is not found, display an error message
            {
                cout << "Task with ID " << id << " not found." << endl;
            }
            break;
        }

        case 5:
            cout << "Exiting the program. Goodbye!" << endl; // Exit the program
            break;

        default:
            cout << "Invalid choice. Please select a number from 1 to 5." << endl;
            break;
        }

        cout << endl;

    } while (choice != 5); // Continue the loop until the user chooses to exit

    delete[] tasks;
    return 0;
}