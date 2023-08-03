#include "Wallet.h"

float Wallet::getMoney(){
	return money;
}

string Wallet::getName() {
	return name;
}

void Wallet::setName(string name) {
	this->name = name;
}

void Wallet::setMoney(float money) {
	this->money = money;
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

void Wallet::showAccount() {
	cout << "Name: " << name << "\tAmount of money: " << money << '\n';
}

void Debit::showAccount() {
	cout << "Name: " << name << "\tCard number: " << number << "\tAmount of money : " << money << '\n';
}

void Credit::showAccount() {
	cout << "Name: " << name << "\tCard number: " << number
		<< "\tCard limit: " << limit << "Card debt:	" << debt << "\tAmount of money : " << money << '\n';
}
