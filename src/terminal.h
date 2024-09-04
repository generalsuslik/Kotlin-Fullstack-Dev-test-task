#ifndef TERMINAL_H
#define TERMINAL_H

#include <vector>
#include "account.h"
#include "user.h"

using ll = long long;
using ull = unsigned long long;
using ld = long double;

class Terminal {
	private:
		std::vector<Account*> accounts; // accounts like USD, RUB, BTC etc;
		
	public:
		Terminal();
		~Terminal();
		int change(User user, NCurrency::Currency currency_from, NCurrency::Currency currency_to, ld amount);
		void change_course(NCurrency::Currency currency_from, NCurrency::Currency currency_to);
};

#endif // TERMINAL_H

