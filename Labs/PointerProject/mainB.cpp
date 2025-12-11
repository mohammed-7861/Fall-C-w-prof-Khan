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
    Task *tasks = new Task[capacity];

    int choice;
    do
    {
        showMenu();
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from the menu." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            cout << "You selected Option 1." << endl;
            string desc;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, desc);
            addTask(tasks, taskCount, capacity, desc);
            break;
        }

        case 2:
        {
            cout << "You selected Option 2." << endl;
            int id;
            cout << "Enter task ID to remove: ";
            cin >> id;
            removeTask(tasks, taskCount, id);
            break;
        }

        case 3:
        {
            cout << "You selected Option 3." << endl;
            listTasks(tasks, taskCount);
            break;
        }

        case 4:
        {
            cout << "You selected Option 4." << endl;
            int id;
            cout << "Enter task ID to mark as completed: ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < taskCount; ++i)
            {
                if (tasks[i].getId() == id)
                {
                    tasks[i].markCompleted();
                    cout << "Task " << id << " marked as completed." << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Task with ID " << id << " not found." << endl;
            }
            break;
        }

        case 5:
            cout << "Exiting the program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please select a number from 1 to 5." << endl;
            break;
        }

        cout << endl;

    } while (choice != 5);

    delete[] tasks;
    return 0;
}