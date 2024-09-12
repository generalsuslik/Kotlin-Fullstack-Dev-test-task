#include <iostream>

#include "terminal.h"
#include "user.h"

using ll = long long;
using ull = unsigned long long;
using ld = long double;

constexpr ld start_sum = 1'000'000;

void run() {
	Terminal* terminal = new Terminal();
	printf("Terminal created\n");
	User* user = new User();
	printf("User created\n");
	
	printf("\n");
	printf("User info:\n");
	user->print_info();
	
	std::string ans;
	int option;
	while (true) {	
		printf("Do you want to change money? (Y/n) or type Q to quit\n");
		std::cin >> ans;
		if (ans == "Q" || ans == "q") {
			printf("Exiting...\n");
			return;
		}
		if (ans != "Y" && ans != "y") {
			printf("Exiting...\n");
			return;
		}
		
		printf("\n");
		printf("Terminal info:\n");
		terminal->print_data();

		printf("\n");
		terminal->print_promt();
		std::cin >> ans;
		option = std::stoi(ans);
		while (!(1 <= option && option <= 10)) {
			printf("Wrong option. Try again or type Q to quit.\n");
			std::cin >> ans;
			if (ans == "Q" || ans == "q") {
				printf("Exiting...\n");
				return;
			} 

			option = std::stoi(ans);
		}
		
		NCurrency::ChangeCurrency change_currency = NCurrency::all_change_currencies[option - 1];
		printf("%s\n", NCurrency::change_str.at(change_currency).c_str());
		
		if (option <= 5) {
			printf("%Lf\n", terminal->get_course(change_currency));
		} else {
			printf("%.2Lf\n", terminal->get_course(change_currency));
		}

		NCurrency::Currency currency_from = NCurrency::change_currs.at(change_currency).first;
		NCurrency::Currency currency_to   = NCurrency::change_currs.at(change_currency).second;

		printf("Enter amount of %s to change:\n", NCurrency::titles.at(currency_from).c_str());
		ld amount;
		std::cin >> amount;

		ld converted_amount = terminal->get_course(change_currency) * amount;
		printf("%Lf %s converts to %Lf %s. Proceed? (Y/n) ", 
						amount, NCurrency::titles.at(currency_from).c_str(), converted_amount, NCurrency::titles.at(currency_to).c_str());
		std::cin >> ans;
		
		printf("Do you want to get your info? (Y/n) or type Q to quit\n");
		std::cin >> ans;
		if (ans == "Q" || ans == "q") {
			printf("Exiting...\n");
			return;
		}
		if (ans == "Y" || ans == "y") {
			user->print_info();	
		}
	}


	printf("\n");
	delete user;
	printf("user deleted\n");
	delete terminal;
	printf("terminal deleted\n");

}

int main() {
	
	run();
	
	return 0;
}

