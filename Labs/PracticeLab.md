# Lab  Part A1
``` c++
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int a = 1;
    int b = 2;
    int c = 3;

    cout << "Input: " << a << b << c << endl;
    cout << "a+b*c = " << a + b * c << endl;
    cout << "(a+b)*c = " << (a+b) * c << endl;
    cout << "a/b*c = " << a/b * c << endl;
    cout << "a/(b*c) = " << a/(b * c) << endl;

    return 0;
}

```
# Lab Part A2
``` c++
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int main() {
    std::cout << std::fixed << std::setprecision(2);
    double balance = 100.00;
    int deposits = 3;
    int withdrawls = 2; 
    double finalBalance = balance + deposits * 25.50 - withdrawls * 12.75;

    cout << "Input: " << "balance = " << balance <<" deposits = "<< deposits << " withdrawls = " << withdrawls  << endl;

    cout << "Final Balance = " << finalBalance << endl;
    return 0;
}
```
# Lab Part B1
```c++
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int main() {
    
    int a = 94;
    int b = 93;
    int c = 98;
    int sum = a + b + c;
    cout << "Input: " << a << " " << b << " " << c << " " << endl;
    cout << "Raw Avg (implicit):  " << sum / 3 << endl;
    std::cout << std::fixed << std::setprecision(1);
    cout << "Correct avg (explicit cast): " << static_cast<double>(sum) / 3;



    return 0;
}
```
# Lab Part B2

