#include "Expenses.h"
#include "Wallet.h"


int main(){
	/*Wallet wallet("Visa", 45);
	cout << wallet.getMoney() << endl;
	cout << wallet.expenses(34) << endl;
	cout << wallet.income(3) << endl;

	Debit card(4545, "card", 4536);
	card.transfer(wallet, 3);
	cout << wallet.getMoney() << endl;
	cout << card.getMoney() << endl;

	wallet.transfer(card, 3);
	cout << wallet.getMoney() << endl;
	cout << card.getMoney() << endl;*/



	Wallet wallet("Test", 1000);

	Debit card(34746767, "Test card", 1500);
	cout << wallet.getMoney() << endl;
	cout << card.getMoney() << endl;


	time_t mytime = time(NULL);
	struct tm today_date;
	localtime_s(&today_date, &mytime);


	cout << today_date.tm_year << endl;
	today_date.tm_year = 1998;
	cout << today_date.tm_year << endl;

	tm yesterday_date = today_date;
	yesterday_date.tm_mday--;
	yesterday_date.tm_wday--;

	tm test_date;
	test_date.tm_year = 2022 - 1900;
	test_date.tm_mon = 12 - 1;
	test_date.tm_mday = 23;

	Expenses exp(30, card, 1, today_date);
	Expenses exp1(50, card, 2, today_date);
	Expenses exp2(70, wallet, 1, yesterday_date);
	Expenses exp3(50, wallet, 3, test_date);
	cout << card.getMoney() << endl;

	int overall_exp{};
	vector <Expenses> expenses{ exp, exp1, exp2, exp3 };

	/*vector<Expenses> day_exp = day_expenses(expenses, today_date, overall_exp);

	for (Expenses item : day_exp)
	{
		cout << item.get_category() << endl;
	}

	*/

	vector<Expenses> week_exp = week_expenses(expenses, 31, overall_exp);


	for (Expenses item : expenses)
	{
		cout << item.get_category() << endl;
	}
	cout << endl;

	for (Expenses item : week_exp)
	{
		cout << item.get_category() << endl;
	}

	cout << overall_exp << endl;
	


	
}