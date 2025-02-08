/*
You are tasked with designing a simple banking system.
Implement the following components using C++ classes and user-defined exceptions:

Create a BankAccount class to represent a bank account.
Each account should have the following attributes:
Account Number (an integer)
Account Holder Name (a string)
Balance (a floating-point value)
Additionally, include a method withdraw that allows an account holder to withdraw money.
If the withdrawal amount exceeds the account balance, throw a InsufficientFundsException with an appropriate error message.
Create a InsufficientFundsException class that is derived from std::exception.
This class should include a constructor that takes an error message as a parameter.
In the main function:
Create several BankAccount objects.
Deposit and withdraw money from these accounts.
Catch and handle the InsufficientFundsException when a withdrawal exceeds the account balance.

*/
#include <iostream>
#include <stdexcept>
using namespace std;

class InsufficientFundsException : public exception {
     string message;

 public:
    InsufficientFundsException(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class BankAccount {
public:
    int accountNumber;
    string accountHolder;
    double balance;

    BankAccount(int accountNumber, const string& accountHolder, double balance)
        : accountNumber(accountNumber), accountHolder(accountHolder), balance(balance) {}

    double getBalance() const {
        return balance;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFundsException("Insufficient funds. Withdrawal not allowed.");
        }
        balance -= amount;
    }
};

int main() {
    try {
        BankAccount account1(1001, "Alice", 1000.0);

        account1.withdraw(2000.0); // Successful withdrawal

        // Print updated balances
        cout << "Account 1 Balance: " << account1.balance << endl;
    }
    catch (const InsufficientFundsException& ex) {
        cout << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
