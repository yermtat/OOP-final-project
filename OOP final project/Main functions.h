#pragma once
#include "Expenses.h"
#include<string>

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

Expenses add_an_expensy(short menuItem, vector<string> acc_names) {
	
	cout << "choose an account: " << endl;

	this_menu_item

	
}
