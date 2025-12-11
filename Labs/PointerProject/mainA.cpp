#include "PartA.h"
#include <iostream>

int main()
{

    Task t1(1, "Finish project");
    Task t2(2, "Study for exam");
    Task t3(3, "Eat");

    // create raw pointers to stack allocated objects
    Task *ptr1 = &t1;
    Task *ptr2 = &t2;
    Task *ptr3 = &t3;

    // complete tasks using raw pointers
    completeTask(ptr1);
    completeTask(ptr2);
    completeTask(ptr3);

    // display task statuses
    Task *tasks[] = {ptr1, ptr2, ptr3};
    for (Task *taskPtr : tasks)
    {
        std::cout << "Task ID: " << taskPtr->getId() << ", Description: " << taskPtr->getDescription()
                  << ", Completed: " << (taskPtr->isCompleted() ? "Yes" : "No") << std::endl; // ternary operator
    }

    // demonstrate pointer addresses and dereferencing
    std::cout << "Address of t1: " << &t1 << std::endl;
    std::cout << "Value of ptr1: " << ptr1 << std::endl;

    std::cout << "Dereferencing ptr1->getId(): " << ptr1->getId() << std::endl;
    std::cout << "Or using (*ptr1).getId(): " << (*ptr1).getId() << std::endl;
    return 0;
}