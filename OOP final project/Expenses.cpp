#include "Expenses.h"
#include "helper function.h"

Expenses::Expenses(float exp_money, Wallet& account, int category, tm date) : exp_money(exp_money), account(account.getName()), 
	category(category), date(date) 
{
	if (date.tm_wday < 0 || date.tm_wday > 6) date.tm_wday = (CalcWeekDay(date.tm_mday, date.tm_mon + 1, date.tm_year + 1900));
	week_number = CalcYearWeek(date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, (date.tm_wday == 0) ? 6 : date.tm_wday - 1);
	account.expenses(exp_money);
};

void Expenses::showExp() {
	cout << exp_money << " azn is spent on " << category << " category" << endl;
}


vector<Expenses> day_expenses(const vector<Expenses>& exp, const tm& date) {
	
	vector<Expenses> day_exp;


	for (Expenses item : exp)
	{
		if (item.date.tm_year == date.tm_year &&
			item.date.tm_mon == date.tm_mon && item.date.tm_mday == date.tm_mday) {
			day_exp.push_back(item);
		}
	}

	return day_exp;
}

vector<Expenses> week_expenses(const vector<Expenses>& exp, int week) {

	vector<Expenses> week_exp;

	for (Expenses item : exp)
	{
		if (item.week_number == week) {
			week_exp.push_back(item);
		}
	}

	return week_exp;
}

vector<Expenses> month_expenses(const vector<Expenses>& exp, int month)
{
	vector<Expenses> month_exp;

	for (Expenses item : exp)
	{
		if (item.date.tm_mon == month) {
			month_exp.push_back(item);
		}
	}
	return month_exp;
}

array<int, 6> count_exp(const vector<Expenses>& exp, int& overall_exp)
{
	array<int, 6> counted_exp{};

	for (Expenses item : exp)
	{
		for (size_t i = 0; i < 6; i++)
		{
			if (item.get_category() == i) {
				counted_exp[i] += item.get_exp_money();
				break;
			}
		}
		overall_exp += item.get_exp_money();
	}

	return counted_exp;

}


bool money_compare(Expenses& left, Expenses& right) {
	return left.get_exp_money() > right.get_exp_money();
}
