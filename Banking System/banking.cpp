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

void Transaction::displayTransaction() {
    std::cout << "Transaction ID: " << transactionId << std::endl;
    std::cout << "Amount: " << amount << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Date: " << date << std::endl;
}
