#include <cstdio>
#include <random>

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
int Terminal::change(User* user, NCurrency::Currency currency_from, NCurrency::Currency currency_to, NCurrency::ChangeCurrency change_currency, ld amount) {
	Account* user_account_to_remove = user->get_accounts()[currency_from];
	ld user_amount                  = user_account_to_remove->get_info()->amount;
	if (user_amount < amount) {
		printf("OPERATION ERROR: lack of money on the account.\n");
		return -1;
	}

	ld converted_amount = -1;
	ld base = this->courses[change_currency];
	if (this->courses.find(change_currency) == this->courses.end()) {
		// reversed. for example: RUB_USD
		NCurrency::ChangeCurrency reversed_currency = NCurrency::rev_currency.at(change_currency);
		base = 1 / this->courses.at(reversed_currency);
		change_currency = reversed_currency;
	}

	converted_amount = base * amount;

	// user account to add money
	Account* user_account_to_add = user->get_accounts()[currency_to];

	// adding and removing money
	user_account_to_add->get_info()->amount += converted_amount;
	user_account_to_remove->get_info()->amount -= amount;

	change_course(change_currency);

	return 1;
}

void Terminal::change_course(NCurrency::ChangeCurrency change_currency) {
	ld course = this->courses[change_currency];
	
	ld min_border = -0.05 * course;
	ld max_border = 0.05 * course;

	std::random_device rd;
	std::mt19937 generator(rd());

	std::uniform_real_distribution<ld> distribution(min_border, max_border);

	ld res = distribution(generator);
	this->courses[change_currency] += res;
}

void Terminal::print_course() {
	for (auto& pair : NCurrency::change_str) {
		printf("%s: %Lf\n", pair.second.c_str(), this->courses.at(pair.first));
	}
}


