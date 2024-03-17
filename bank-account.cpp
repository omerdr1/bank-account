#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string holder, string number, double initialBalance) {
        accountHolder = holder;
        accountNumber = number;
        balance = initialBalance;
    }

    // Function to deposit money
    void deposit(double amount) {
        balance += amount;
        cout << accountHolder << " deposited $" << amount << " successfully." << endl;
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << accountHolder << " withdrawn $" << amount << " successfully." << endl;
        } else {
            cout << "Insufficient funds for " << accountHolder << endl;
        }
    }

    // Function to display account details
    void display() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

    // Operator overloading for adding two account balances
    BankAccount operator+(const BankAccount &other) {
        BankAccount result("", "", 0);
        result.balance = this->balance + other.balance;
        return result;
    }
};

int main() {
    // Creating two bank accounts
    BankAccount account1("John Doe", "123456", 1000);
    BankAccount account2("Jane Smith", "654321", 500);

    // Performing operations on the accounts
    account1.deposit(500);
    account2.withdraw(200);
    account1.withdraw(1600);


    // Displaying account details
    cout << "Account 1 Details:" << endl;
    account1.display();

    cout << endl;

    cout << "Account 2 Details:" << endl;
    account2.display();

    // Adding balances of two accounts
    BankAccount combinedAccount = account1 + account2;
    cout << endl;
    cout << "Combined Account Details:" << endl;
    combinedAccount.display();

    return 0;
}
