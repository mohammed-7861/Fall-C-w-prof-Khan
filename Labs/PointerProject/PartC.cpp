#include <iostream>
#include <memory>
#include "PartC.h"

using namespace std;

void showMenu() // Display menu
{
    cout << "Menu:" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. Remove Task" << endl;
    cout << "3. List Tasks" << endl;
    cout << "4. Mark Task as Completed" << endl;
    cout << "5. Exit" << endl;
}
Task::Task() // default constructor
    : id(0), description(""), completed(false)
{
}
Task::Task(int id, const std::string &desc) // parameterized constructor
    : id(id), description(desc), completed(false)
{
}
void Task::markCompleted() // mark task as completed
{
    completed = true;
}

bool Task::isCompleted() const // check if task is completed
{
    return completed;
}

int Task::getId() const // get task ID
{
    return id;
}

std::string Task::getDescription() const // get task description
{
    return description;
}
void TaskManager ::addTask(const std::string &desc) // add a new task
{
    if (size >= capacity)
    {
        cout << "Task list is full. Cannot add more tasks." << endl;
        return;
    }
    tasks[size] = Task(size + 1, desc);
    size++;
    cout << "Task added with ID " << size << "." << endl;
}

void TaskManager ::markCompleted(int id) // mark a task as completed by ID
{
    for (int i = 0; i < size; ++i)
    {
        if (tasks[i].getId() == id)
        {
            tasks[i].markCompleted();
            cout << "Task " << id << " marked as completed." << endl;
            return;
        }
    }
    cout << "Task with ID " << id << " not found." << endl;
}

void TaskManager ::removeTask(int id) // remove a task by ID
{
    for (int i = 0; i < size; ++i)
    {
        if (tasks[i].getId() == id)
        {
            for (int j = i; j < size - 1; ++j)
            {
                tasks[j] = tasks[j + 1];
            }
            size--;
            cout << "Task " << id << " removed." << endl;
            return;
        }
    }
    cout << "Task with ID " << id << " not found." << endl;
}
void TaskManager ::listTasks() const // list all tasks
{
    if (size == 0)
    {
        cout << "No tasks available." << endl;
        return;
    }
    for (int i = 0; i < size; ++i)
    {
        cout << "ID: " << tasks[i].getId()
             << ", Description: " << tasks[i].getDescription()
             << ", Completed: " << (tasks[i].isCompleted() ? "Yes" : "No") << endl;
    }
}
TaskManager::TaskManager(int initialCapacity) // constructor
    : size(0), capacity(initialCapacity)      // initialize size and capacity
{
    tasks = std::make_unique<Task[]>(capacity); // allocate dynamic array of tasks
}
