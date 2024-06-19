//
//  banking.hpp
//  Banking System
//
//  Created by Marc Badyna on 6/14/24.
//

#ifndef banking_hpp
#define banking_hpp

#include <stdio.h>
#include <string>
#include <vector>

class Transaction {
private:
    int transactionId;
    double amount;
    std::string type;
    std::string date;
public:
    Transaction(int, double, std::string, std::string);
    void displayTransaction() const;
};

class Account {
private:
    int accountNumber;
    double balance;
    std::string accountType;
    std::vector<Transaction> transactions;
public:
    Account(int, std::string);
    void deposit(double, std::string);
    void withdraw(double, std::string);
    double getBalance() const;
    void displayAccountDetails() const;
    void displayTransactions() const;
    int getAccountNumber() const;
};

class Customer {
private:
    int customerId;
    std::string name;
    std::vector<Account> accounts;
public:
    Customer(int, std::string);
    void addAccount(Account);
    void removeAccount(int);
    void displayCustomerDetails() const;
    void displayAllTransactions() const;
};

class Bank {
private:
    std::vector<Customer> customers;
    std::vector<Account> accounts;
public:
    void createAccount(int, int, std::string);
    void deleteAccount(int);
    void addCustomer(int, std::string);
    void displayAllAccounts() const;
    void displayAllCustomers() const;
};

#endif /* banking_hpp */
