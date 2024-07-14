//
//  main.cpp
//  Banking System
//
//  Created by Marc Badyna on 6/14/24.
//

#include <iostream>
#include "banking.hpp"

void displayMenu();

int main() {
    Bank bank;
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int customerID;
                std::string name;
                std::cout << "Enter Customer ID: ";
                std::cin >> customerID;
                std::cout << "Enter Customer Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                bank.addCustomer(customerID, name);
                break;
            }
            case 2: {
                int customerID, accountNumber;
                std::string accountType;
                std::cout << "Enter Customer ID: ";
                std::cin >> customerID;
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                std::cout << "Enter Account Type: ";
                std::cin.ignore();
                std::getline(std::cin, accountType);
                bank.createAccount(customerID, accountNumber, accountType);
                break;
            }
            case 3: {
                int accountNumber;
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                bank.deleteAccount(accountNumber);
                break;
            }
            case 4: {
                int accountNumber;
                double amount;
                std::string date;
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                std::cout << "Enter Amount: ";
                std::cin >> amount;
                std::cout << "Enter Date: ";
                std::cin.ignore();
                std::getline(std::cin, date);
                bank.deposit(accountNumber, amount, date);
                break;
            }
            case 5: {
                int accountNumber;
                double amount;
                std::string date;
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                std::cout << "Enter Amount: ";
                std::cin >> amount;
                std::cout << "Enter Date: ";
                std::cin.ignore();
                std::getline(std::cin, date);
                bank.withdraw(accountNumber, amount, date);
                break;
            }
            case 6:
                bank.displayAllCustomers();
                break;
            case 7:
                bank.displayAllAccounts();
                break;
            case 8:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 8);

    return 0;
}

void displayMenu() {
    std::cout << "1. Add Customer" << std::endl;
    std::cout << "2. Create Account" << std::endl;
    std::cout << "3. Delete Account" << std::endl;
    std::cout << "4. Deposit" << std::endl;
    std::cout << "5. Withdraw" << std::endl;
    std::cout << "6. Display All Customers" << std::endl;
    std::cout << "7. Display All Accounts" << std::endl;
    std::cout << "8. Exit" << std::endl;
}
