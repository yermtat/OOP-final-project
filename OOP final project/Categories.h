#pragma once
#include "Data.h"
class Categories
{
	int id;
	string cat_name;
	static int quantity;
	float max_money;

public:
	Categories();
	Categories(string cat_name);

	Categories(const char* cat_name);
	
	static int getQuantity();

	string getCat_name();

	void setMaxMoney(float money) {
		max_money += money;
	}

	float getMaxMoney() {
		return max_money;
	}
	
};


bool cat_money_compare(Categories& left, Categories& right);

