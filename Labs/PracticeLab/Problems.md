# Part A1
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
# Part A2
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
# Part B1
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
# Part B2
```c++
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int main() {
    
    int Wins = 10;
    int games =20; 

    if (games == 0) {
        cout << "No games played." << endl;
    } else {
        cout << fixed << setprecision(1);
        double winRate = static_cast<double>(Wins) / games * 100;
        cout << "Win Rate: " << winRate << "%" << endl;
    }

    return 0;
}
```
# Part C
``` c++
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int main() {
    
    double hours = 45;
    double rate = 20.0;

    double regHours = min(hours, 40.0); 
    double otHours = max(hours - 40.0, 0.0);
    double gross = regHours*rate + otHours*rate*1.5;
    double net = gross - (0.18 * gross) - 35.0;

    
    cout << "Input hours: " << "hours=" << hours << " rate="  << rate << endl;
    cout << fixed << setprecision(2);
    cout << "Regular hours: " << regHours << endl;
    cout << "Overtime hours: " << otHours << endl;
    cout << "Gross pay: $ " << gross << endl;
    cout << "Net pay: $" << net << endl;




    return 0;
}
```
# Part D
``` c++
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int items = 5; 
    double price = 25;
    cout << "Enter items and price: " << items << " and " << price << endl;

    // BUG 1: uninitialized total
    double total = 0.0;  
    total = items * price; 

    // BUG 2: integer division
    int discountPercent = 15;
    double discount = total * static_cast<double>(discountPercent) / 100.0;

    // BUG 3: precedence & shipping
    double shipping = 5 + 2 * items;
    double afterDiscount = total - discount;
    if (afterDiscount >= 100.0) shipping = 0;

    std::cout << std::fixed << std::setprecision(2);

    cout << "Total: $" << total << endl;
    cout << "Discount: $" << discount << endl;
    cout << "Shipping: $" << shipping << endl;
    cout << "Grand Total: $" << (afterDiscount + shipping) << endl;
}
``` 
