#include "Wallet.h"

float Wallet::getMoney(){
	return money;
}

string Wallet::getName() {
	return name;
}

float Wallet::expenses(float exp) {
	return money -= exp;
}

float Wallet::income(float inc) {
	return money += inc;
}

void Wallet::transfer(Wallet& to_account, int amount) {
	to_account.money += amount;
	money -= amount;

}