#include <cstdio>
#include <cmath>
#include <random>

#include "terminal.h"

using ll = long long;
using ull = unsigned long long;
using ld = long double;

constexpr ld EPS = 0.001;

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
		this->accounts[pair.first] = account;
	}
}

Terminal::~Terminal() {
	for (const auto& pair : this->accounts) {
		delete pair.second; // delete Account*
	} 
}

/*
 * changes amount of <currency_from> to X <currency_to>
 */
int Terminal::change(User* user, NCurrency::ChangeCurrency change_currency, ld amount) {
	NCurrency::Currency currency_from = NCurrency::change_currs.at(change_currency).first;
	NCurrency::Currency currency_to   = NCurrency::change_currs.at(change_currency).second;

	Account* user_account_to_remove = user->get_accounts()[currency_from];
	ld user_amount                  = user_account_to_remove->get_info()->amount;

	// CHECKING USER
	if (user_amount < amount) {
		printf("\nOPERATION ERROR: lack of money on your account.\n\n");
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

	// CHECKING TERMINAL
	Account* terminal_account_to_remove = this->accounts[currency_to];
	if (terminal_account_to_remove->get_info()->amount - converted_amount <= EPS) {
		printf("\nOPERATION ERROR: lack of money on the %s terminal account\n", NCurrency::titles.at(currency_to).c_str());
		printf("U want to take %.2Lf %s, but there is only %.2Lf %s left\n\n", 
						converted_amount, NCurrency::titles.at(currency_to).c_str(), 
						terminal_account_to_remove->get_info()->amount, NCurrency::titles.at(currency_to).c_str());
		return -1;
	}
	
	// user account to add money
	Account* user_account_to_add = user->get_accounts()[currency_to];

	// updating user money
	user_account_to_add->get_info()->amount += converted_amount;
	user_account_to_remove->get_info()->amount -= amount;

	// terminal account to add money
	Account* terminal_account_to_add = this->accounts[currency_from];

	// updating terminal money
	terminal_account_to_remove->get_info()->amount -= converted_amount;
	terminal_account_to_add->get_info()->amount += amount;

	change_course(change_currency);

	return 1;
}

ld Terminal::get_course(NCurrency::ChangeCurrency change_currency) {
	if (this->courses.find(change_currency) != this->courses.end()) {
		return this->courses.at(change_currency);
	} else {
		return 1 / this->courses.at(NCurrency::rev_currency.at(change_currency));
	}
}

/*
 * changes course randomly for +-5%
 */
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

/*
 * prints terminal money info
 */
void Terminal::print_data() {
	Account* account;
	AccountInfo* account_info;
	for (auto& account_pair : this->accounts) {
		account = account_pair.second;
		account_info = account->get_info();
		
		printf("%.2Lf %s\n", account_info->amount, NCurrency::titles.at(account_info->currency).c_str());
	}
}

/*
 * prints interactive info for user
 * to choose what currency to change
 */
void Terminal::print_promt() {
	printf("Change pairs and course:\n");
	
	size_t change_arr_size = NCurrency::rev_currency.size() * 2;
	for (size_t option = 0; option < change_arr_size; ++option) {
		NCurrency::ChangeCurrency change_currency = NCurrency::all_change_currencies[option];
		std::string change_currency_str = NCurrency::change_str.at(change_currency);
		if (this->courses.find(change_currency) != this->courses.end()) {
			printf("%ld) %s %Lf\n", option + 1, change_currency_str.c_str(), this->courses.at(change_currency));
		} else {
			printf("%ld) %s %.2Lf\n", option + 1, change_currency_str.c_str(), 1 / this->courses.at(NCurrency::rev_currency.at(change_currency)));
		}
	}

	printf("Select an option:\n");
}





