#ifndef USER_H
#define USER_H

#include <unordered_map>
#include "account.h"

using ll = long long;
using ull = unsigned long long;

class User {
	private:
		std::unordered_map<NCurrency::Currency, Account*> user_accounts; // RUB - Account, USD - Account etc
	
	public:
		User();
		~User();
		int add_money(NCurrency::Currency currency, ull amount);
		int take_money(NCurrency::Currency currency, ull amount);
		ull get_money(NCurrency::Currency currency);
};

#endif // USER_H

