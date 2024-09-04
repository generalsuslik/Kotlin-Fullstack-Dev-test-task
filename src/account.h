/*
 * MAIN CLASS: Account
 * REPRESENTS BANK ACCOUNT WITH FIXATED CURRENCY
 * Exmp: RUB 100'000
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "account_info.h"

using ll = long long;
using ull = unsigned long long;

class Account {
	private:
		AccountInfo account_info;

	public:
		Account(NCurrency::Currency currency, ull amount);
		~Account();
		ull add_money(ull amount);
		ull remove_money(ull amount);
		ull get_money();
		AccountInfo* get_info();
};

#endif // ACCOUNT_H

