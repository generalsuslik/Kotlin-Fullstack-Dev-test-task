#ifndef TERMINAL_H
#define TERMINAL_H

#include <map>
#include <vector>
#include "account.h"
#include "user.h"

using ll = long long;
using ull = unsigned long long;
using ld = long double;

class Terminal {
	private:
		std::vector<Account*> accounts; // accounts like USD, RUB, BTC etc;	
		
		std::map<NCurrency::ChangeCurrency, ld> courses = {
			{ NCurrency::RUB_USD, 0.011  },
			{ NCurrency::RUB_EUR, 0.0099 },
			{ NCurrency::USD_EUR, 0.90 },
			{ NCurrency::USD_USDT, 1.00 },
			{ NCurrency::USD_BTC, 0.000018 }	
		};

	public:
		Terminal();
		~Terminal();
		int change(User* user, NCurrency::Currency currency_from, NCurrency::Currency currency_to, NCurrency::ChangeCurrency change_currency, ld amount);
		void change_course(NCurrency::ChangeCurrency change_currency);
		void print_course();
};

#endif // TERMINAL_H

