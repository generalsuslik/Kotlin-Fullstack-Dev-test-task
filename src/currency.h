#include <map>
#include <string>

namespace NCurrency {
	enum Currency {
		RUB,
		USD,
		EUR,
		USDT,
		BTC
	};

	static const Currency all_currencies[] = { RUB, USD, EUR, USDT, BTC };
	static const std::map<Currency, std::string> titles = {
		{ RUB, "RUB" },
		{ USD, "USD" },
		{ EUR, "EUR" },
		{ USDT, "USDT" },
		{ BTC, "BTC" }
	};

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

	static const std::map<ChangeCurrency, ChangeCurrency> rev_currency = {
		{ USD_RUB, RUB_USD  },
		{ EUR_RUB, RUB_EUR  },
		{ EUR_USD, USD_EUR  },
		{ USDT_USD, USD_USDT },
		{ BTC_USD, USD_BTC  }
	};

	static const std::map<ChangeCurrency, std::string> change_str = {
		{ RUB_USD, "RUB - USD" },
		{ RUB_EUR, "RUB - EUR" },
		{ USD_EUR, "USD - EUR" },
		{ USD_USDT, "USD - USDT" },
		{ USD_BTC, "USD - BTC" },

		{ USD_RUB, "USD - RUB" },
		{ EUR_RUB, "EUR - RUB" },
		{ EUR_USD, "EUR - USD" },
		{ USDT_USD, "USDT - USD" },
		{ BTC_USD, "BTC - USD" }
	};
};





