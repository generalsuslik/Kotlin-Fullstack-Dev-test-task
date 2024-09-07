#ifndef USER_H
#define USER_H

#include <unordered_map>
#include "account.h"

using ll = long long;
using ull = unsigned long long;
using ld = long double;

class User {
	private:
		std::unordered_map<NCurrency::Currency, Account*> user_accounts; // RUB - Account, USD - Account etc
	
	public:
		User();
		~User();
		int add_money(NCurrency::Currency currency, ld amount);
		int take_money(NCurrency::Currency currency, ld amount);
		ld get_money(NCurrency::Currency currency);
		std::unordered_map<NCurrency::Currency, Account*> get_accounts();
};

#endif // USER_H

