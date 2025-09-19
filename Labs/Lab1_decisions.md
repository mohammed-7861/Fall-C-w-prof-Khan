# Calculator Lab

## Challenges
The biggest challenge that I faced during this lab was using the enum class and just figuring out how to take the operations input from 
the user and actually getting the right calcultion to proceed. This for me was a somewhat of a roadblock because I had to start thinking
about the way I strucutre my code so that it makes sence as a calculator. Getting input from the user was realitively easy, but the 
difficulty arose when converting that user input into something that would actually cause an operation to occur, which is where the
enum class and switch came into play. Other than that everything else was more or less pretty intuitive. 

## Code
```C++
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a {};
    cout << "Enter an integer (positive or negative): ";
    if (!(cin >> a)) {
        cerr << "Invalid input. Please enter a valid integer." << endl;
        return 1;
    }

    int b {};
    cout << "Enter another integer (positive or negative): ";
    if (!(cin >> b)) {
        cerr << "Invalid input. Please enter a valid integer." << endl;
        return 1;
    }

    cout << "Choose a number between 1 and 4 that corresponds to the following operations:\n";
    cout << " 1 = Addition\n";
    cout << " 2 = Subtraction\n";
    cout << " 3 = Multiplication\n";
    cout << " 4 = Division\n";
    cout << "Your choice: ";

         
    int choice {};
    if (!(cin >> choice) || choice < 1 || choice > 4) {
        cerr << "Invalid choice of operation." << endl;
        return 1;
    }

    enum class Operations { Add = 1, Subtract = 2, Multiply = 3, Divide = 4 };

    switch (static_cast<Operations>(choice)) {
        case Operations::Add:
            cout << (a + b) << endl;
            break;
        case Operations::Subtract:
            cout << (a - b) << endl;
            break;
        case Operations::Multiply:
            cout << (a * b) << endl;
            break;
        case Operations::Divide:
            if (b == 0) {
                cerr << "Error: Division by zero is not allowed." << endl;
                return 1;
            }
            cout << fixed << setprecision(2) << (static_cast<double>(a) / b) << endl;
            break;
    }
    return 0;
}
```
# Video Link
