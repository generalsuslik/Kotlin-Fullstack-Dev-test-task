#include <cstdio>

#include "terminal.h"
#include "user.h"

using ll = long long;
using ull = unsigned long long;
using ld = long double;

constexpr ld start_sum = 1'000'000;

int main() {

	//Account* account = new Account(NCurrency::RUB, start_sum);
	
	//printf("Yo\n");
	//AccountInfo* info = account->get_info();

	//std::cout << std::fixed << info->amount << " " << info->currency << std::endl;
	//printf("%.2Lf %d\n", info->amount, info->currency);

	//delete account;
	Terminal* terminal = new Terminal();
	printf("Terminal created\n");
	User* user = new User();
	printf("User created\n");
	
	printf("\n");
	printf("Start user money info:\n");
	for (auto& currency : NCurrency::all_currencies) {
		printf("%.2Lf %s\n", user->get_money(currency), NCurrency::titles.at(currency).c_str());
	}

	printf("\n");
	printf("Start terminal course:\n");
	terminal->print_course();

	printf("\n");
	printf("Start terminal money:\n");
	terminal->print_data();
	
	printf("\n");
	terminal->change(user, NCurrency::RUB, NCurrency::USD, NCurrency::RUB_USD, 10'000);

	for (auto& currency : NCurrency::all_currencies) {
		printf("%.2Lf %s\n", user->get_money(currency), NCurrency::titles.at(currency).c_str());
	}

	printf("\n");
	printf("New course:\n");
	terminal->print_course();

	printf("\n");
	printf("Current terminal data:\n");
	terminal->print_data();

	delete user;
	printf("user deleted\n");
	delete terminal;
	printf("terminal deleted\n");

	return 0;
}

