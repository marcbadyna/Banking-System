//
//  banking.cpp
//  Banking System
//
//  Created by Marc Badyna on 6/14/24.
//

#include "banking.hpp"
#include <iostream>

Transaction::Transaction(int id, double amt, std::string t, std::string d)
: transactionId(id), amount(amt), type(t), date(d) {}

void Transaction::displayTransaction() const {
    std::cout << "Transaction ID: " << transactionId << std::endl;
    std::cout << "Amount: " << amount << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Date: " << date << std::endl;
}

Account::Account(int num, std::string type) : accountNumber(num), accountType(type), balance(0.0) {}

void Account::deposit(double amount, std::string date) {
    balance += amount;
    transactions.push_back(Transaction(transactions.size() + 1, amount, "Deposit", date));
}

void Account::withdraw(double amount, std::string date) {
    if(amount <= balance) {
        balance -= amount;
        transactions.push_back(Transaction(transactions.size() + 1, amount, "Withdrawal", date));
    } else {
        std::cout << "Insufficient balance!" << std::endl;
    }
}

double Account::getBalance() const {
    return balance;
}

void Account::displayAccountDetails() const {
    std::cout << "Account Number: " << accountNumber << ", Account Type: " << accountType << ", Balance: " << balance << std::endl;
}

void Account::displayTransactions() const {
    for(const auto& transaction : transactions) {
        transaction.displayTransaction();
    }
}

int Account::getAccountNumber() const {
    return accountNumber;
}

Customer::Customer(int id, std::string n) : customerId(id), name(n) {}

void Customer::addAccount(Account account) {
    accounts.push_back(account);
}

void Customer::removeAccount(int accountNumber) {
    for(auto it = accounts.begin(); it != accounts.end(); ++it) {
        if(it->getAccountNumber() == accountNumber) {
            accounts.erase(it);
            break;
        }
    }
}

int Customer::getCustomerId() const {
    return customerId;
}

void Customer::displayCustomerDetails() const {
    std::cout << "Customer ID: " << customerId << ", Name: " << name << std::endl;
    for(const auto& account : accounts) {
        account.displayAccountDetails();
    }
}

void Customer::displayAllTransactions() const {
    for(const auto& account : accounts) {
        account.displayTransactions();
    }
}

void Bank::createAccount(int customerId, int accountNumber, std::string accountType) {
    Account newAccount(accountNumber, accountType);
    accounts.push_back(newAccount);
    
    for(auto& customer : customers) {
        if(customer.getCustomerId() == customerId) {
            customer.addAccount(newAccount);
            break;
        }
    }
}

void Bank::deleteAccount(int accountNumber) {
    for(auto it = accounts.begin(); it != accounts.end(); ++it) {
        if(it->getAccountNumber() == accountNumber) {
            accounts.erase(it);
            break;
        }
    }
    for(auto& customer : customers) {
        customer.removeAccount(accountNumber);
    }
}

void Bank::addCustomer(int customerId, std::string name) {
    customers.push_back(Customer(customerId, name));
}

void Bank::displayAllAccounts() const {
    for(const auto& account : accounts) {
        account.displayAccountDetails();
    }
}

void Bank::displayAllCustomers() const {
    for(const auto& customer : customers) {
        customer.displayCustomerDetails();
    }
}

void Bank::deposit(int accountNumber, double amount, std::string date) {
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            account.deposit(amount, date);
            return;
        }
    }
    std::cout << "Account with Number " << accountNumber << " not found." << std::endl;
}

void Bank::withdraw(int accountNumber, double amount, std::string date) {
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            account.withdraw(amount, date);
            return;
        }
    }
    std::cout << "Account with Number " << accountNumber << " not found." << std::endl;
}
