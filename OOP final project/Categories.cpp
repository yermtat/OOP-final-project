#include "Categories.h"

int Categories::quantity{ 0 };

Categories::Categories(string cat_name) : cat_name(cat_name) {
	id = ++quantity;
}
Categories::Categories(const char* cat_name) : cat_name(cat_name) {
	id = ++quantity;
}

 int Categories::getQuantity() {
	return quantity;
}
 
 string Categories::getCat_name() {
	 return cat_name;
 }
