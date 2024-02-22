#include <iostream>

/**
 * A simple bank system, mostly written in order to pracitce classes in C++.
 * User can:
 *          1. Deposit Cash
 *          2. Withdraw cash
 *          3. Check Current amount
*/
class BankAccount
{
private:
    std::string name;
    double balance;
public:
    BankAccount(std::string name, double balance){
        this->name = name;
        this->balance = balance;
    };
    void deposit(double amount){
        this->balance += amount;
    }
    void withdraw(double amount){
        if (amount <= balance)
        {
            this->balance -= amount;
        }else{
            std::cout << "Insufficient funds." << std::endl;
        }
    }
    void UserBalance(){
        std::cout << "Account of " << this->name << "\nCurrent Balance : " << this->balance << std::endl;
    }
};

int main(){
    std::string name;
    double initialDeposit;

    std::cout << "Enter your name:\n> ";
    getline(std::cin, name);
    std::cout << "Enter Initial deposit\n> ";
    std::cin >> initialDeposit;

    BankAccount account = BankAccount(name,initialDeposit);
    std::cout << "Welcome " << name << std::endl;

    int choice;
    double amount;

    do
    {
        std::cout << "\n1. Deposit" << std::endl;
        std::cout << "2. Withdraw" << std::endl;
        std::cout << "3. Current Balance" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Enter choice: \n> ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Amount to deposit:\n> ";
            std::cin >> amount;
            account.deposit(amount);
            break;
        case 2:
            std::cout << "Amount to withdraw:\n> ";
            std::cin >> amount;
            account.withdraw(amount);
            break;
        case 3:
            account.UserBalance();
            break;
        case 4:
            std::cout << "Bye Bye " << name << "!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
        }

    } while (choice != 4);

    return 0;   
}