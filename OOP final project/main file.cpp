//#include "Expenses.h"
//#include "Wallet.h"



//int main(){
//
//	/*enum Categories
//	{
//		HEALTH = 0,
//		EDUCATION,
//		GROCERIES,
//		SPORT,
//		TRANSPORT,
//		OTHER
//	};*/
//
//	vector<Categories> categories_vec{ "Health", "Education", "Groceries", "Sport", "Transport", "Other" };
//
//	const int cat_array_length = categories_vec.size();
//
//
//	
//
//
//	/*Wallet wallet("Visa", 45);
//	cout << wallet.getMoney() << endl;
//	cout << wallet.expenses(34) << endl;
//	cout << wallet.income(3) << endl;
//
//	Debit card(4545, "card", 4536);
//	card.transfer(wallet, 3);
//	cout << wallet.getMoney() << endl;
//	cout << card.getMoney() << endl;
//
//	wallet.transfer(card, 3);
//	cout << wallet.getMoney() << endl;
//	cout << card.getMoney() << endl;*/
//
//
//
//	Wallet wallet("Test", 1000);
//
//	Debit card(34746767, "Test card", 1500);
//	cout << wallet.getMoney() << endl;
//	cout << card.getMoney() << endl;
//
//
//	time_t mytime = time(NULL);
//	struct tm today_date;
//	localtime_s(&today_date, &mytime);
//
//
//	cout << today_date.tm_year << endl;
//	today_date.tm_year = 1998;
//	cout << today_date.tm_year << endl;
//
//	tm yesterday_date = today_date;
//	yesterday_date.tm_mday--;
//	yesterday_date.tm_wday--;
//
//	tm test_date;
//	test_date.tm_year = 2022 - 1900;
//	test_date.tm_mon = 12 - 1;
//	test_date.tm_mday = 23;
//
//	Expenses exp(30, card, 1, today_date);
//	Expenses exp1(50, card, 2, today_date);
//	Expenses exp2(70, wallet, 1, yesterday_date);
//	Expenses exp3(50, wallet, 3, test_date);
//	cout << card.getMoney() << endl;
//
//	int overall_exp{};
//	vector <Expenses> expenses{ exp, exp1, exp2, exp3 };
//
//	/*vector<Expenses> day_exp = day_expenses(expenses, today_date, overall_exp);
//
//	for (Expenses item : day_exp)
//	{
//		cout << item.get_category() << endl;
//	}
//
//	*/
//
//	vector<Expenses> week_exp = week_expenses(expenses, 32);
//
//	vector<Expenses> month_exp = month_expenses(expenses, 8);
//
//	vector<int> month_cat_exp = count_exp(month_exp, overall_exp);
//
//
//	/*for (Expenses item : expenses)
//	{
//		cout << item.get_category() << endl;
//	}
//	cout << endl;*/
//
//	for (Expenses item : week_exp)
//	{
//		cout << item.get_category() << endl;
//	}
//
//	vector<int> cat_exp = count_exp(week_exp, overall_exp);
//
//	cout << overall_exp << endl;
//
//	cout << endl;
//
//	for (size_t i = 0; i < 6; i++)
//	{
//		if (cat_exp[i] != 0) {
//
//			cout << "on " << i << " category spent " << cat_exp[i] << " azn" << endl;;
//		}
//		
//	}
//	
//	sort(week_exp.begin(), week_exp.end(), money_compare);
//
//	for (size_t i = 0; i < 3; i++)
//	{
//		week_exp[i].showExp();
//	}
//
//
//	
//}