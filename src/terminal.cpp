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
int Terminal::change(User* user, NCurrency::Currency currency_from, NCurrency::Currency currency_to, NCurrency::ChangeCurrency change_currency, ld amount) {
	Account* user_account_to_remove = user->get_accounts()[currency_from];
	ld user_amount                  = user_account_to_remove->get_info()->amount;

	// CHECKING USER
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

	// CHECKING TERMINAL
	Account* terminal_account_to_remove = this->accounts[currency_to];
	if (terminal_account_to_remove->get_info()->amount - converted_amount <= EPS) {
		printf("OPERATION ERROR: lack of money on the %s terminal account\n", NCurrency::titles.at(currency_to).c_str());
		printf("U wanna take %.2Lf, but there is only %.2Lf left\n", converted_amount, terminal_account_to_remove->get_info()->amount);
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
	int option = 1;
	for (const auto& [change_currency, str] : NCurrency::change_str) {
		if (this->courses.find(change_currency) != this->courses.end()) {
			printf("%d) %s %Lf\n", option++, str.c_str(), courses.at(change_currency));
		} else { 
			printf("%d) %s %.2Lf\n", option++, str.c_str(), 1 / this->courses.at(NCurrency::rev_currency.at(change_currency)));
		}
	 }

	printf("Select an option:\n");
}





