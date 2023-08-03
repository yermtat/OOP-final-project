#pragma once
#include "Wallet.h"
#include "Categories.h"


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
	int get_exp_money() {
		return exp_money;
	}

	void showExp();

	friend vector<Expenses> day_expenses(const vector<Expenses>& exp, const tm& date);
	friend vector<Expenses> week_expenses(const vector<Expenses>& exp, int week);
	friend vector<Expenses> month_expenses(const vector<Expenses>& exp, int month);
	

};

vector<int> count_exp(const vector<Expenses>& exp, int& overall_exp);

bool money_compare(Expenses& left, Expenses& right);
