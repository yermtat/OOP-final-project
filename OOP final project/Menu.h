#pragma once
#include"Data.h"
#include<conio.h>
#include<Windows.h>
#include<iomanip>

HANDLE h;


enum controllers { UP = 72, DOWN = 80 };

short menu(vector<string> Menu) {
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned char key{};
	short menuPos = 0;

	while (true)
	{

		menuPos %= Menu.size();
		if (menuPos < 0) menuPos = Menu.size() - 1;

		for (size_t i = 0; i < Menu.size(); i++)
		{
			if (i == menuPos) {
				SetConsoleTextAttribute(h, 79);
				cout << "> " << Menu[i] << setw(10) << right << ' ' << endl;
			}
			else {
				SetConsoleTextAttribute(h, 15);
				cout << " " << Menu[i] << setw(10) << right << ' ' << endl;
			}
		}



		key = _getch();
		if (key == 224) {

			key = _getch();
			switch (key)
			{
			case UP:
				menuPos--;
				break;
			case DOWN:
				menuPos++;
				break;
			}
		}
		else {
			if (key == 13) {

				SetConsoleTextAttribute(h, 15);
				return menuPos + 1;
			}
		}
		SetConsoleTextAttribute(h, 15);
		system("cls");
	}
}