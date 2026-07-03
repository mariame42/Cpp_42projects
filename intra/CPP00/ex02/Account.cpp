/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:01:58 by meid              #+#    #+#             */
/*   Updated: 2025/07/12 16:05:56 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

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
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout<< "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {
    _nbAccounts--;
    _totalAmount -= _amount;
    _displayTimestamp();
    std::cout<< "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << 
                ";total:" << _totalAmount << 
                ";deposits:" << _totalNbDeposits << 
                ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

int Account::getNbAccounts() {
    return (_nbAccounts);
}

int Account::getTotalAmount() {
    return (_totalAmount);
}

int Account::checkAmount() const {
    return _amount;
}

int Account::getNbDeposits() {
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals() {
    return (_totalNbWithdrawals);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout<< "index:" << _accountIndex << 
                ";amount:" << _amount << ";deposits:" << 
                _nbDeposits << ";withdrawals:" << 
                _nbWithdrawals << std::endl;
}


void Account::makeDeposit(int deposit) {
    int p_amount = _amount;
    _amount += deposit;
    _nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
    _displayTimestamp();
    std::cout<< "index:" << _accountIndex << 
            ";p_amount:" << p_amount << ";deposit:" << 
            deposit << ";amount:" << _amount << 
            ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ){
    _displayTimestamp();
    std::cout<< "index:" << _accountIndex << ";p_amount:" << _amount;
    if (withdrawal > _amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;      
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals += 1;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals += 1;
    std::cout << ";withdrawal:" << withdrawal << ";amount:" << 
                _amount << ";nb_withdrawals:" << 
                _nbWithdrawals << std::endl;
    return true;
}
