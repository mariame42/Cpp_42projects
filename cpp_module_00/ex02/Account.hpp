// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void ); // get the number of accounts
	static int	getTotalAmount( void ); // get the total amount of all accounts
	static int	getNbDeposits( void ); // get the total number of deposits
	static int	getNbWithdrawals( void ); // get the total number of withdrawals
	static void	displayAccountsInfos( void ); // display the total number of accounts, the total amount of all accounts, the total number of deposits, the total number of withdrawals

	// constructor and destructor Always return void
	Account( int initial_deposit ); // constructor
	~Account( void ); // destructor

	void	makeDeposit( int deposit ); // make a deposit
	bool	makeWithdrawal( int withdrawal ); // make a withdrawal
	int		checkAmount( void ) const; // check the amount
	void	displayStatus( void ) const; // display the status of the account


private:

	static int	_nbAccounts; // number of accounts
	static int	_totalAmount; // total amount of all accounts
	static int	_totalNbDeposits; // total number of deposits
	static int	_totalNbWithdrawals; // total number of withdrawals

	static void	_displayTimestamp( void );

	int				_accountIndex; // index of the account
	int				_amount; // amount of the account
	int				_nbDeposits; // number of deposits
	int				_nbWithdrawals; // number of withdrawals

	Account( void );

};

// Key Concepts:
// Static members = Shared across ALL accounts (global bank statistics)
// Instance members = Unique to EACH account (individual account data)
// Deposits = Adding money to account (always successful)
// Withdrawals = Removing money from account (can fail if insufficient funds)
// Account Index = Sequential numbering (0, 1, 2, 3...) for identification
// The static members track the entire bank's activity, while instance members track individual account activity.



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
