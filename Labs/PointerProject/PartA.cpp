#include <iostream>
#include "PartA.h"

// class implementation from the PartA.h file
Task::Task() : id(0), description(""), completed(false) {}
Task::Task(int id, const std::string &desc) : id(id), description(desc), completed(false) {}
void Task::markCompleted() // marks the task as completed
{
    completed = true;
}
bool Task::isCompleted() const // checks if the task is completed
{
    return completed;
}
int Task::getId() const // returns the task ID
{
    return id;
}
std::string Task::getDescription() const // returns the task description
{
    return description;
}
void completeTask(Task *t) // function to complete a task given a pointer to it
{
    if (t != nullptr)
    {
        t->markCompleted();
    }
}
