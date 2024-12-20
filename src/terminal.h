#ifndef TERMINAL_H
#define TERMINAL_H

#include <map>
#include "account.h"
#include "user.h"

using ll = long long;
using ull = unsigned long long;
using ld = long double;

class Terminal {
	private:
		std::map<NCurrency::Currency, Account*> accounts; // accounts like USD, RUB, BTC etc;	
														  
		std::map<NCurrency::ChangeCurrency, ld> courses = {
			{ NCurrency::RUB_USD, 0.011  },
			{ NCurrency::RUB_EUR, 0.0099 },
			{ NCurrency::USD_EUR, 0.90 },
			{ NCurrency::USD_USDT, 1.00 },
			{ NCurrency::USD_BTC, 0.000018 }	
		};

		void change_course(NCurrency::ChangeCurrency change_currency);

	public:
		Terminal();
		~Terminal();
		int change(User* user, NCurrency::ChangeCurrency change_currency, ld amount);
		ld get_course(NCurrency::ChangeCurrency change_currency);
		void print_data();
		void print_promt();
};

#endif // TERMINAL_H

