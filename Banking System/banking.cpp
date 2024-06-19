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
