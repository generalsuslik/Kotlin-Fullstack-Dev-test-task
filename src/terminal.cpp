#include <cstdio>
#include "terminal.h"

using ll = long long;
using ull = unsigned long long;
using ld = long double;

Terminal::Terminal() {
	const std::pair<NCurrency::Currency, ld> start_amount[] = {
		{ NCurrency::RUB, 10'000  },
		{ NCurrency::USD, 1'000  },
		{ NCurrency::EUR, 1'000  },
		{ NCurrency::USDT, 1'000  },
		{ NCurrency::BTC, 1.5 }
	};

	for (const auto& pair : start_amount) {
		Account* account = new Account(pair.first, pair.second);
		this->accounts.push_back(account);
	}
}

Terminal::~Terminal() {
	for (const Account* account : this->accounts) {
		delete account;
	} 
}

/*
 * changes amount of <currency_from> to X <currency_to>
 */
int Terminal::change(User& user, NCurrency::Currency currency_from, NCurrency::Currency currency_to, ld amount) {
	Account* user_account = user.user_accounts[currency_from];
	ld user_amount        = user_account->account_info.amount;
	if (user_amount < amount) {
		printf("OPERATION ERROR: lack of money on the account.\n");
	}

	ld converted_amount = 
}

void Terminal::change_course(NCurrency::Currency currency_from, NCurrency::Currency currency_to) {
	
}



