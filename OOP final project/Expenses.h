#pragma once
#include "Wallet.h"


class Expenses
{
private:
	float exp_money;
	string account;
	int category;
	tm date;
	int week_number;
public:
	Expenses() {}
	Expenses(float exp_money, Wallet& account, int category, tm date);
	
	int get_category() {
		return category;
	}

	friend vector<Expenses> day_expenses(const vector<Expenses>& exp, const tm& date, int& overall_exp);
	friend vector<Expenses> week_expenses(const vector<Expenses>& exp, int week, int& overall_exp);

};

