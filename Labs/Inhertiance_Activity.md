# Mohammed Saiger
## Inheritance Activity


savingsAccount.h
```cpp
#pragma once
#include "bankAccount.h"

// savingsAccount class inherits from bankAccount
// Represents a savings account with interest rate
class savingsAccount : public bankAccount
{
private:
    double interestRate = 0.0; // Interest rate percentage for the savings account

public:
    // Setter for interest rate
    void setInterestRate(double interestRate);

    // Getter for interest rate
    double getInterestRate() const;

    // Calculate and display monthly interest
    void postInterest() const;

    // Override withdraw to prevent overdrafts
    void withdraw(double amount);

    // Override print to include interest rate information
    void print() const;

    // Default constructor
    savingsAccount();

    // Parameterized constructor
    savingsAccount(int accountNumber, double balance, double interestRate);
};
```

savingsAccount.cpp
```cpp
#include "savingsAccount.h"
#include <iostream>
#include <iomanip>

// Set the interest rate for the savings account
void savingsAccount::setInterestRate(double interestRate)
{
    this->interestRate = interestRate;
}

// Return the current interest rate
double savingsAccount::getInterestRate() const
{
    return interestRate;
}

// Calculate and display the monthly interest earned on current balance
// Interest is calculated as: balance * (rate / 100 / 12)
void savingsAccount::postInterest() const
{
    std::cout << "Your monthly interest is: " << std::fixed << std::setprecision(2)
              << "USD " << getAccountBalance() * (interestRate / 100.0 / 12.0) << std::endl;
}

// Withdraw money from savings account
// Prevents overdrafts by checking if sufficient balance exists
void savingsAccount::withdraw(double amount)
{
    if (amount > getAccountBalance())
    {
        // Insufficient funds,  display error message
        std::cout << "Not enough balance to withdraw: " << amount << std::endl;
        std::cout << "Your current balance is: " << getAccountBalance() << std::endl;
    }
    else
    {
        // Sufficient funds, process withdrawal
        bankAccount::withdraw(amount);
        std::cout << "Your new balance is " << getAccountBalance() << std::endl;
    }
}

// Display account information including balance and interest rate
void savingsAccount::print() const
{
    bankAccount::print(); // Call parent class print for account number and balance
    std::cout << "Interest Rate %: " << getInterestRate() << std::endl;
}

// Default constructor
savingsAccount::savingsAccount() = default;

// Parameterized constructor, initializes account with number, balance, and interest rate
savingsAccount::savingsAccount(int accountNumber, double balance, double interestRate)
    : bankAccount(accountNumber, balance), interestRate(interestRate) {}
```
