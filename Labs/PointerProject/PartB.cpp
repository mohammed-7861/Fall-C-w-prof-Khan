#include "PartB.h"
#include <iostream>

// Constructor definitions
Task::Task() : id(0), description(""), completed(false) {}                                   // Default constructor
Task::Task(int id, const std::string &desc) : id(id), description(desc), completed(false) {} // Parameterized constructor

void Task::markCompleted() // Mark task as completed
{
    completed = true;
}
bool Task::isCompleted() const // Check if task is completed
{
    return completed;
}
int Task::getId() const // Get task ID
{
    return id;
}
std::string Task::getDescription() const // Get task description
{
    return description;
}
void addTask(Task *tasks, int &size, int capacity, const std::string &desc) // Add a new task
{
    if (size >= capacity) // Check for capacity
    {
        std::cout << "Task list is full. Cannot add more tasks." << std::endl;
        return;
    }
    tasks[size] = Task(size + 1, desc); // Create new task with ID size + 1
    size++;
}
void removeTask(Task *tasks, int &size, int id) // Remove task by ID
{
    for (int i = 0; i < size; ++i)
    {
        if (tasks[i].getId() == id) // Found the task to remove
        {
            for (int j = i; j < size - 1; ++j) // Shift tasks left
            {
                tasks[j] = tasks[j + 1]; // Copy next task to current position
            }
            size--;
            std::cout << "Task " << id << " removed." << std::endl;
            return;
        }
    }
    std::cout << "Task with ID " << id << " not found." << std::endl;
}
void listTasks(Task *tasks, int size) // List all tasks
{
    if (size == 0)
    {
        std::cout << "No tasks available." << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i) // Iterate through tasks
    {
        Task *currentTask = tasks + i; // Pointer arithmetic
        std::cout << "ID: " << currentTask->getId()
                  << ", Description: " << currentTask->getDescription()
                  << ", Completed: " << (currentTask->isCompleted() ? "Yes" : "No")
                  << std::endl;
    }
}

void showMenu() // Function to display the menu
{
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. Remove Task" << std::endl;
    std::cout << "3. List Tasks" << std::endl;
    std::cout << "4. Mark Task as Completed" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Choose an option: ";
}
