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
		
		std::unordered_map<NCurrency::ChangeCurrency, double> courses;
		cources[NCurrency::RUB_USD] = 0.011;
		cources[NCurrency::RUB_EUR] = 0.0099;
		cources[NCurrency::USD_EUR] = 0.90;
		cources[NCurrency::USD_USDT] = 1.00;
		cources[NCurrency::USD_BTC] = 0.000018;

		std::unordered_map<NCurrency::ChangeCurrency, double> reversed_cources;
		reversed_cources[NCurrency::USD_RUB]

	public:
		Terminal();
		~Terminal();
		int change(User user, NCurrency::Currency currency_from, NCurrency::Currency currency_to, NCurrency::ChangeCurrency change_currency, ld amount);
		void change_course(NCurrency::Currency currency_from, NCurrency::Currency currency_to, NCurrency::ChangeCurrency change_currency);
};

#endif // TERMINAL_H

