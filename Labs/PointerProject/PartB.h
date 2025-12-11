#include <string>
#ifndef PARTB_H // prevent multiple inclusions
#define PARTB_H // header guard
class Task
{
private:
    int id;
    std::string description;
    bool completed;

public:
    Task();
    Task(int id, const std::string &desc);

    void markCompleted();
    bool isCompleted() const;
    int getId() const;
    std::string getDescription() const;
};
void addTask(Task *tasks, int &size, int capacity, const std::string &desc);
void removeTask(Task *tasks, int &size, int id);
void listTasks(Task *tasks, int size);

#endif // PARTB_H