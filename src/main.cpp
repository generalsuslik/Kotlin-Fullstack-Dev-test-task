#include <iostream>
#include "account.h"

using ll = long long;
using ull = unsigned long long;

constexpr ull start_sum = 1'000'000;

int main() {

	Account* account = new Account(NCurrency::RUB, start_sum);
	
	std::cout << "Yo\n";
	std::cout << account->get_money() << std::endl;

	delete account;

	return 0;
}

