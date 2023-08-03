#pragma once
#include "Data.h"

class Wallet
{
protected:
	string name;
	float money;

public: 
	Wallet() : name(), money(0) {}
	Wallet(string name, float money = 0) : name(name), money(money) {}

	string getName();
	float getMoney();

	void setName(string name);
	void setMoney(float money);

	float expenses(float exp);
	float income(float inc);
	void transfer(Wallet& to_account, int amount);

	virtual void showAccount();



};

class Debit : public Wallet
{
private:
	long long number;
public:
	Debit() : Wallet(), number(0) {};
	Debit(long long number, string name, float money = 0) : number(number), Wallet(name, money) {}

	void showAccount() override;

};


class Credit : public Wallet
{
private:
	long long number;
	float limit;
	float debt;
public:
	Credit() : Wallet(), number(0), limit(0), debt(0) {}
	Credit(long long number, string name, float money, float limit, float debt = 0 ) : number(number), Wallet(name, money), limit(limit), debt(debt) {}

	void showAccount() override;

};

