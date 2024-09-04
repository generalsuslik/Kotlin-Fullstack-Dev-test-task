#include <cstdio>
#include "account.h"

using ll = long long;
using ull = unsigned long long;
using ld = long double;

constexpr ld start_sum = 1'000'000;

int main() {

	Account* account = new Account(NCurrency::RUB, start_sum);
	
	printf("Yo\n");
	AccountInfo* info = account->get_info();

	//std::cout << std::fixed << info->amount << " " << info->currency << std::endl;
	printf("%.2Lf %d\n", info->amount, info->currency);

	delete account;

	return 0;
}

