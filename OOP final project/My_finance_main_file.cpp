#include "Main functions.h"
#include "Menu.h"

int main() {

	vector<string> categories_string{ "Health", "Education", "Groceries", "Sport", "Transport", "Other" };

	vector<Categories> categories_vec{};

	for (string item : categories_string)
	{
		categories_vec.push_back(Categories(item));
	}
	
	//vector<Categories> categories_vec{ "Health", "Education", "Groceries", "Sport", "Transport", "Other" };
	vector<Wallet> my_accounts{};
	vector<Expenses> my_expensies{};

	vector<string> acc_names{};


	short menuItem = 0;

	vector<string> startMenu{
		"Show my accounts",
		"Add an account",
		"Add an income",
		"Add an expense",
		"Show the expense report",
		"Show the TOP-3",
		"Exit"
	};

	vector<string> walletsMenu{
		"Add a wallet",
		"Add a debit card",
		"Add a credit card"
	};

	while(true){
	 menuItem = menu(startMenu);
	 system("cls");

	 switch (menuItem)
	 {
	 case 1:
		 for (Wallet item : my_accounts) {
			 show_my_accounts(item);
		 }
		 system("pause");
		 break;
	 case 2:
		 menuItem = menu(walletsMenu);

		 my_accounts.push_back(add_an_account(menuItem));
		 acc_names.push_back(my_accounts.back().getName());

		 cin.ignore(1);
		 break;
	 case 3:

		 cout << "Choose a category: " << endl;
		 menuItem = menu(categories_string);



		 
		 break;
	 default:
		 break;
	 }

	 system("cls");
	}

}