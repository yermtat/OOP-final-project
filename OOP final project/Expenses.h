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
	int get_exp_money() {
		return exp_money;
	}

	void showExp();

	friend vector<Expenses> day_expenses(const vector<Expenses>& exp, const tm& date);
	friend vector<Expenses> week_expenses(const vector<Expenses>& exp, int week);
	friend vector<Expenses> month_expenses(const vector<Expenses>& exp, int month);

	/*bool operator>(const Expenses& exp) {
		return exp_money > exp.exp_money;
	}
	bool operator<(const Expenses& exp) {
		return exp_money < exp.exp_money;
	}*/

	

};

array<int, 6> count_exp(const vector<Expenses>& exp, int& overall_exp);

bool money_compare(Expenses& left, Expenses& right);
