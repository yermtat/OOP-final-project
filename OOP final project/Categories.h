#pragma once
#include "Data.h"
class Categories
{
	int id;
	string cat_name;
	static int quantity;

public:
	Categories();
	Categories(string cat_name);

	Categories(const char* cat_name);
	
	static int getQuantity();

	string getCat_name();
};


