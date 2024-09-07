#include <unordered_map>

namespace NCurrency {
	enum Currency {
		RUB,
		USD,
		EUR,
		USDT,
		BTC
	};

	static const Currency all_currencies[] = { RUB, USD, EUR, USDT, BTC };

	enum ChangeCurrency {
		RUB_USD,
		RUB_EUR,
		USD_EUR,
		USD_USDT,
		USD_BTC,
		
		USD_RUB,
		EUR_RUB,
		EUR_USD,
		USDT_USD,
		BTC_USD
	};

	std::unordered_map<ChangeCurrency, ChangeCurrency> rev_currency;
	rev_currency[RUB_USD] = USD_RUB;
	rev_currency[RUB_EUR] = EUR_RUB;
	rev_currency[USD_EUR] = EUR_USD;
	rev_currency[USD_USDT] = USDT_USD;
	rev_currency[USD_BTC] = BTC_USD
};

