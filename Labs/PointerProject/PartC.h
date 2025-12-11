#include <string>
#include <iostream>
#include <memory>

#ifndef PARTC_H // prevent multiple inclusions
#define PARTC_H // header guard
class Task
{
private:
    int id;
    std::string description;
    bool completed;

public:
    Task();                                // default constructor
    Task(int id, const std::string &desc); // parameterized constructor

    void markCompleted();               // mark task as completed
    bool isCompleted() const;           // check if task is completed
    int getId() const;                  // get task ID
    std::string getDescription() const; // get task description
};

class TaskManager
{
private:
    std::unique_ptr<Task[]> tasks; // dynamic array of tasks
    int size;
    int capacity;

public:
    TaskManager(int initialCapacity);      // constructor
    void addTask(const std::string &desc); // add a new task
    void removeTask(int id);               // remove a task by ID
    void listTasks() const;                // list all tasks
    void markCompleted(int id);            // mark a task as completed by ID
};
#endif // PARTC_H
