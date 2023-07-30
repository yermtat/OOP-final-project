#pragma once
#include "Data.h"

class Wallet
{
protected:
	string name;
	float money;

public: 
	Wallet() {}
	Wallet(string name, float money = 0) : name(name), money(money) {}

	string getName();
	float getMoney();
	float expenses(float exp);
	float income(float inc);
	void transfer(Wallet& to_account, int amount);

};

class Debit : public Wallet
{
private:
	long long number;
public:
	Debit() {};
	Debit(long long number, string name, float money = 0) : number(number), Wallet(name, money) {}

};


class Credit : public Wallet
{
private:
	long long number;
	float limit;
	float debt;
public:
	Credit();
	Credit(long long number, string name, float money, float limit, float debt = 0 ) : number(number), Wallet(name, money), limit(limit), debt(debt) {}


};

