#include "Expenses.h"
#include "helper function.h"

Expenses::Expenses(float exp_money, Wallet& account, int category, tm date) : exp_money(exp_money), account(account.getName()), 
	category(category), date(date) 
{
	if (date.tm_wday < 0 || date.tm_wday > 6) date.tm_wday = (CalcWeekDay(date.tm_mday, date.tm_mon + 1, date.tm_year + 1900));
	week_number = CalcYearWeek(date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, (date.tm_wday == 0) ? 6 : date.tm_wday - 1);
	account.expenses(exp_money);
};

vector<Expenses> day_expenses(const vector<Expenses>& exp, const tm& date, int& overall_exp) {
	
	vector<Expenses> day_exp;


	for (Expenses item : exp)
	{
		if (item.date.tm_year == date.tm_year &&
			item.date.tm_mon == date.tm_mon && item.date.tm_mday == date.tm_mday) {
			day_exp.push_back(item);
			overall_exp += item.exp_money;
		}
	}

	return day_exp;
}

vector<Expenses> week_expenses(const vector<Expenses>& exp, int week, int& overall_exp) {

	vector<Expenses> week_exp;

	for (Expenses item : exp)
	{
		if (item.week_number == week) {
			week_exp.push_back(item);
			overall_exp += item.exp_money;
		}
	}

	return week_exp;
}

