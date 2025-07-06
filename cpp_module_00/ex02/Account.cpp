#include "Account.hpp"
#include <iostream>
#include <ctime>

// Use function-local static variables to ensure consistent destructor order
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// YYYYMMDD_HHMMSS
void Account::_displayTimestamp(void){
    time_t currentTime = time(NULL);
    struct tm* timeInfo = localtime(&currentTime);
    char buffer[20];
    
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeInfo);
    std::cout << "[" << buffer << "] ";
}

Account::Account(int initial_deposit)
{

    this->_accountIndex = Account::_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout<< "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account() {
    Account::_nbAccounts--;
    Account::_totalAmount -= this->_amount;
    Account::_displayTimestamp();
    std::cout<< "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos() {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

int Account::getNbAccounts() {
    return (Account::_nbAccounts);
}

int Account::getTotalAmount() {
    return (Account::_totalAmount);
}

int Account::checkAmount() const {
    return this->_amount;
}

int Account::getNbDeposits() {
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals() {
    return (Account::_totalNbWithdrawals);
}

// This function promises NOT to modify the object's member variables
// It's a read-only function
// It can only call other const member functions

void	Account::displayStatus( void ) const // display the status of the account
{
    // [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
    Account::_displayTimestamp();
    std::cout<< "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}


void Account::makeDeposit(int deposit) {
// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
    int p_amount = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    Account::_displayTimestamp();
    std::cout<< "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ){
// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
    Account::_displayTimestamp();
    std::cout<< "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
    if (withdrawal > this->_amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;      
        return false;
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals += 1;
    std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}
