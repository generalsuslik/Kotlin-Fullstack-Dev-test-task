#ifndef ACCOUNT_H
#define ACCOUNT_H
/*
 * MAIN CLASS: Account
 * REPRESENTS BANK ACCOUNT WITH FIXATED CURRENCY
 * Exmp: RUB 100'000
 */

#include <iostream>
#include "currency.h"

using ll = long long;
using ull = unsigned long long;

typedef struct {
	Currency currency;
	ull      amount;
} AccountInfo;

class Account {
	private:
		AccountInfo account_info;

	public:
		Account(Currency currency, ull amount) {
			this->account_info.currency = currency;
			this->account_info.amount = amount;
		}

		//~Account() {
		//	delete account_info;
		//}
		
		// adds money to the account
		// returns updated amount of money
		ull add_money(ull amount) {
			this->account_info.amount += amount;
			return this->account_info.amount;
		}
		
		// removes money from bank account
		// returns -1 if there is an error || remaining amount of money 
		ull remove_money(ull amount) {
			if (account_info.amount < amount) {
				std::cout << "OPERATION ERROR: lack of fund in the account." << std::endl;
				return -1;
			}
		}

		ull get_money() {
			return this->account_info.amount;
		}

		AccountInfo* get_info() {
			return &this->account_info;
		}
};




#endif // ACCOUNT_H

