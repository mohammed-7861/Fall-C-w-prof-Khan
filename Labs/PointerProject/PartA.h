#include <string>
#ifndef PARTA_H // prevent multiple inclusions
#define PARTA_H // header guard

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
void completeTask(Task *t);
#endif // PARTA_H