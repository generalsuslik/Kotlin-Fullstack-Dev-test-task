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
using ld = long double;

class Account {
	private:
		AccountInfo account_info;

	public:
		Account(NCurrency::Currency currency, ld amount);
		~Account();
		ld add_money(ld amount);
		ld take_money(ld amount);
		ld get_money();
		AccountInfo* get_info();
		void set_info(NCurrency::Currency currency, ld amount);
};

#endif // ACCOUNT_H

