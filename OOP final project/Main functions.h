#pragma once
#include "Expenses.h"
#include <string>
#include "Menu.h"

void show_my_accounts(Wallet& account) {
	account.showAccount();
}

Wallet add_an_account(short menuItem) {
	
	Wallet wallet;
	cout << "Enter accounts name: ";
	string name{};
	getline(cin, name);
	

	cout << "Enter moneys summ: ";
	float money{};
	cin >> money;

	long long number{};
	switch (menuItem)
	{
	case 1: 
		return Wallet(name, money);
	case 2:
		cout << "Enter card's number: ";
		
		cin >> number;

		return Debit(number, name, money);

	case 3:
		cout << "Enter card's number: ";
		cin >> number;

		cout << "Enter card's limit: ";
		float limit{};
		cin >> limit;
		
		cout << "Enter your card debt: ";
		float debt{};
		cin >> debt;

		return Credit(number, name, money, limit, debt);
	}
}

struct tm time_enter(short dateItem) {

	time_t mytime = time(NULL);
	struct tm today_date;
	localtime_s(&today_date, &mytime);

	tm expensy_date{};

	expensy_date = today_date;

	
	switch (dateItem)
	{
	case 1:
		return expensy_date;
	case 2:
		int day{}, month{}, year{};

		cout << "Enter a day, a month and a year: " << endl;
		cin >> day>>month>>year;

		expensy_date.tm_year = year - 1900;
		expensy_date.tm_mday = day;
		expensy_date.tm_mon = month - 1;
		expensy_date.tm_wday = -1;

		return expensy_date;
	}

	
}
