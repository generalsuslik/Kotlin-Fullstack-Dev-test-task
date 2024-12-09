#include <iostream>
#include "user.h"

using ll = long long;
using ull = unsigned long long;
using ld = long double;

NCurrency::Currency default_currency = NCurrency::RUB;
ld start_money                       = 1'000'000;

User::User() {
	for (const NCurrency::Currency& currency : NCurrency::all_currencies) {
		user_accounts[currency] = new Account(currency, 0);
	}

	user_accounts[default_currency]->set_info(default_currency, start_money);
}

User::~User() {
	for (const std::pair<const NCurrency::Currency, Account*>& pair : user_accounts) {
		delete pair.second;
	}
}

// returns 1 if transaction successfull
// else -1
int User::add_money(NCurrency::Currency currency, ld amount) {
	ld res = user_accounts[currency]->add_money(amount);

	if (res > 0) {
		return 1;
	}

	return -1;
}

// returns 1 if transaction successfull
// else -1
int User::take_money(NCurrency::Currency currency, ld amount) {
	ld res = user_accounts[currency]->take_money(amount);

	if (res > 0) {
		return 1;
	}

	return -1;
}

// returs amount of money
ld User::get_money(NCurrency::Currency currency) {
	return user_accounts[currency]->get_money();
}

std::unordered_map<NCurrency::Currency, Account*> User::get_accounts() {
	return user_accounts;
}

void User::print_info() {
	for (const NCurrency::Currency currency : NCurrency::all_currencies) {
		printf("%.2Lf %s\n", get_money(currency), NCurrency::titles.at(currency).c_str());
	}
}




