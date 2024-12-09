#include <iostream>

#include "account.h"

Account::Account(NCurrency::Currency currency, ld amount) 
	: account_info(currency, amount) {}

Account::~Account() = default;

// adds money to the account
// returns updated amount of money
ld Account::add_money(ld amount) {
	account_info.amount += amount;
	return account_info.amount;
}

// removes money from bank account
// returns -1 if there is an error || remaining amount of money 
ld Account::take_money(ld amount) {
	if (account_info.amount < amount) {
		std::cout << "OPERATION ERROR: lack of money in the account." << std::endl;
		return -1;
	}

	return account_info.amount;
}

// returns amount of money
ld Account::get_money() {
	return account_info.amount;
}

// kinda obvious :)
AccountInfo* Account::get_info() {
	return &account_info;
}

void Account::set_info(NCurrency::Currency currency, ld amount) {
	account_info.currency = currency;
	account_info.amount = amount;
}

