#ifndef TERMINAL_H
#define TERMINAL_H

#include <vector>
#include "account.h";

using ll = long long;
using ull = unsigned long long;

class Terminal {
	private:
		std::vector<Account> accounts; // accounts like USD, RUB, BTC etc;
		
	public:
		Terminal();
		~Terminal();
		int change();
};

#endif // TERMINAL_H

