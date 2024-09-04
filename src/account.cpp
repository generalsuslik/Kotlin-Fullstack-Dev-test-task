#include <iostream>

#include "account.h"

Account::Account(NCurrency::Currency currency, ld amount) {
	this->account_info.currency = currency;
	this->account_info.amount   = amount;
}

Account::~Account() {}

// adds money to the account
// returns updated amount of money
ld Account::add_money(ld amount) {
	this->account_info.amount += amount;
	return this->account_info.amount;
}

// removes money from bank account
// returns -1 if there is an error || remaining amount of money 
ld Account::take_money(ld amount) {
	if (this->account_info.amount < amount) {
		std::cout << "OPERATION ERROR: lack of money in the account." << std::endl;
		return -1;
	}

	return this->account_info.amount;
}

// returns amount of money
ld Account::get_money() {
	return this->account_info.amount;
}

// kinda obvious :)
AccountInfo* Account::get_info() {
	return &this->account_info;
}

void Account::set_info(NCurrency::Currency currency, ld amount) {
	this->account_info.currency = currency;
	this->account_info.amount = amount;
}

