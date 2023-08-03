#include "Categories.h"

int Categories::quantity{ 0 };

Categories::Categories(string cat_name) : cat_name(cat_name), max_money(0) {
	id = ++quantity;
}
Categories::Categories(const char* cat_name) : cat_name(cat_name), max_money(0) {
	id = ++quantity;
}

 int Categories::getQuantity() {
	return quantity;
}
 
 string Categories::getCat_name() {
	 return cat_name;
 }


 bool cat_money_compare(Categories& left, Categories& right) {
	 return left.getMaxMoney() > right.getMaxMoney();
 }