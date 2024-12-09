#include "currency.h"

using ll = long long;
using ull = unsigned long long;
using ld = long double;

struct AccountInfo {
	NCurrency::Currency currency;
	ld      			amount;

	AccountInfo(NCurrency::Currency currency_, ld amount_) 
		: currency(currency_)
		, amount(amount_) {}
};
