#include "Main functions.h"
#include<fstream>

int main() {

	time_t mytime = time(NULL);
	struct tm today_date;
	localtime_s(&today_date, &mytime);


	vector<string> categories_string{ "Health", "Education", "Groceries", "Sport", "Transport", "Other" };

	vector<Categories> categories_vec{};

	for (string item : categories_string)
	{
		categories_vec.push_back(Categories(item));
	}

	vector<Wallet> my_accounts{};
	vector<Expenses> my_expensies{};
	vector<Expenses> time_interval_expenses{};
	vector<int> exp_by_categories{};
	vector<Categories> sort_categories{};

	vector<string> acc_names{};


	short menuItem{ 0 };
	short acc_menu_item{ 0 };
	short date_menu_item{ 0 };
	short  categ_menu_item{ 0 };


	float money{};
	int week{}, month{}, overall_exp{};
	

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

	vector<string> datesMenu{
		"Today",
		"Enter a date"
	};

	vector<string> time_interval{
		"Day",
		"Week",
		"Month"
	};

	vector<string> time_interval_woDay{
		"Week",
		"Month"
	};

	vector<string> top3{
		"By expenses",
		"Ny Categories"
	};

	ofstream outf("reports and raitings.txt", ios::app);

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

		 cout << "Choose an account: " << endl;
		 acc_menu_item = menu(acc_names) - 1; // -1 чтобы совпадало с элементами в массиве

		 cout << "Enter an amount of money: ";
		 cin >> money;

		 my_accounts[acc_menu_item].income(money);
		 break;

	 case 4:
		 cout << "Choose a category: " << endl;
		 categ_menu_item = menu(categories_string) - 1; // -1 чтобы совпадало с элементами в массиве

		 cout << "Choose an account: " << endl;

		 acc_menu_item = menu(acc_names) - 1;	// -1 чтобы совпадало с элементами в массиве

		 cout << "Enter a money amount: ";
		 cin >> money;

		 cout << "Choose a date: " << endl;

		 date_menu_item = menu(datesMenu);

		 struct tm expense_date = time_enter(date_menu_item);

		 my_expensies.push_back(Expenses(money, my_accounts[acc_menu_item], categ_menu_item, expense_date));
		 categories_vec[categ_menu_item].setMaxMoney(money);
		 
		 break;
	 case 5:

		 cout << "Choose a time interval: " << endl;

		 menuItem = menu(time_interval);

		 switch (menuItem)
		 {
		 case 1:

			 date_menu_item = menu(datesMenu);


			 struct tm expense_date = time_enter(date_menu_item);
			 time_interval_expenses = day_expenses(my_expensies, expense_date);
			 break;
		 case 2:

			 cout << "Enter a report week: "; // 31.07 - 06.08 это 32 неделя например
			 cin >> week;

			 time_interval_expenses = week_expenses(my_expensies, week);
			 break;
		 
		 case 3:

			 cout << "Enter a report month: ";
			 cin >> month;

			 time_interval_expenses = month_expenses(my_expensies, month - 1);

			 break;
						
		 default:
			 break;
		 }

		 for (Expenses item : time_interval_expenses)
		 {
			 cout << item.get_exp_money() << " azn is spent on " << categories_string[item.get_category()] << " category" << endl;
		 }
		 system("pause");

		

		 for (Expenses item : time_interval_expenses)
		 {
			 outf << item.get_exp_money() << " azn is spent on " << categories_string[item.get_category()] << " category" << endl;
		 } 
		 outf << endl;

		 break;

	 case 6:
		
		 menuItem = menu(top3);

		 switch (menuItem)
		 {
		 case 1:

			 menuItem = menu(time_interval_woDay);

			 switch (menuItem)
			 {
			 case 1:

				 cout << "Enter a report week: "; // 31.07 - 06.08 это 32 неделя например
				 cin >> week;

				 time_interval_expenses = week_expenses(my_expensies, week);
				 break;

			 case 2:

				 cout << "Enter a report month: ";
				 cin >> month;

				 time_interval_expenses = month_expenses(my_expensies, month - 1);
			 }

			 sort(time_interval_expenses.begin(), time_interval_expenses.end(), money_compare);

	
			for (int i = 0; i < 3 && i < time_interval_expenses.size(); i++)
			{
			 cout << time_interval_expenses[i].get_exp_money() << " azn is spent on " 
				 << categories_string[time_interval_expenses[i].get_category()] << " category" << endl;
			}
			system("pause");


			for (int i = 0; i < 3 && i < time_interval_expenses.size(); i++)
			{
			 outf << time_interval_expenses[i].get_exp_money() << " azn is spent on "
				 << categories_string[time_interval_expenses[i].get_category()] << " category" << endl;
			}
			outf << endl;

			break;

		 case 2:

			 menuItem = menu(time_interval_woDay);

			 switch (menuItem)
			 {
			 case 1:

				 cout << "Enter a report week: "; // 31.07 - 06.08 это 32 неделя например
				 cin >> week;

				 time_interval_expenses = week_expenses(my_expensies, week);
				 break;

			 case 2:

				 cout << "Enter a report month: ";
				 cin >> month;

				 time_interval_expenses = month_expenses(my_expensies, month - 1);
			 }
			 

			 sort_categories = categories_vec;

			 sort(sort_categories.begin(), sort_categories.end(), cat_money_compare);

			 for (int i = 0; i < 3 && i < time_interval_expenses.size(); i++)
			 {
				 cout << sort_categories[i].getMaxMoney() << " azn is spent on "
					 << sort_categories[i].getCat_name() << " category" << endl;
			 }
			 system("pause");


			 for (int i = 0; i < 3 && i < time_interval_expenses.size(); i++)
			 {
				 outf << sort_categories[i].getMaxMoney() << " azn is spent on "
					 << sort_categories[i].getCat_name() << " category" << endl;
			 }
			 outf << endl;
			 break;

		 }
	 case 7:
		 return 0;

	 }

	 system("cls");
	}

}