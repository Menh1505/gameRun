#include "run.h"
#include "consoleControl.h"
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include "car.h"

void intro()
{
	SetConsoleOutputCP(65001);
	std::fstream fi;
	fi.open("intro.txt", std::ios_base::in);
	while (!fi.eof())
	{
		std::string s;
		std::getline(fi, s);
		std::cout << s << std::endl;
		Sleep(100);
	}

	int i = 1;
	while (true)
	{
		clearScreen();
		fi.seekg(SEEK_SET);
		while (!fi.eof())
		{
			SetColor(0, i);
			std::string s;
			std::getline(fi, s);
			std::cout << s << std::endl;
		}

		Sleep(1000);
		i++;
		clearScreen();
		fi.seekg(SEEK_SET);
		while (!fi.eof())
		{
			SetColor(0, i);
			std::string s;
			std::getline(fi, s);
			std::cout << s << std::endl;
		}

		Sleep(1000);

		if (GetAsyncKeyState(13))
			break;

		i++;
		if (i >= 15) i = 1;
	}
	fi.close();
}
void road1()
{
	clearScreen();
	for (int i = 0; i <= 39; ++i)
	{
		for (int j = 0; j <= 69; ++j)
		{
			if (j == 7 || j == 69) std::cout << "||";
			else if (j == 38 && (i % 2 == 0)) std::cout << "|";
			else std::cout << " ";
		}
		std::cout << std::endl;
	}
}
void road2()
{	
	clearScreen();
	for (int i = 0; i <= 39; ++i)
	{
		for (int j = 0; j <= 69; ++j)
		{
			if (j == 7 || j == 69) std::cout << "||";
			else if (j == 38 && (i % 2 == 1)) std::cout << "|";
			else std::cout << " ";
		}
		std::cout << std::endl;
	}
}
void pauseGame()
{
	system("cls");
	gotoxy(1, 15);
	std::cout << "\t\t _______  _______  __   __  _______  _______ \n";
	std::cout << "\t\t|       ||   _   ||  | |  ||       ||       |\n";
	std::cout << "\t\t|    _  ||  |_|  ||  | |  ||  _____||    ___|\n";
	std::cout << "\t\t|   |_| ||       ||  |_|  || |_____ |   |___ \n";
	std::cout << "\t\t|    ___||       ||       ||_____  ||    ___|\n";
	std::cout << "\t\t|   |    |   _   ||       | _____| ||   |___ \n";
	std::cout << "\t\t|___|    |__| |__||_______||_______||_______|\n";
	std::cout << "\t\t           PRESS ENTER TO CONTINUES          \n";
	while (true)
	{
		
		Sleep(1000);
		if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");
			gotoxy(1, 15);
			std::cout << "\t\t\t\t ____\n";
			std::cout << "\t\t\t\t|__ /\n";
			std::cout << "\t\t\t\t |_ \\\n";
			std::cout << "\t\t\t\t|___/\n";
			Sleep(1000);
			system("cls");
			gotoxy(1, 15);
			std::cout << "\t\t\t\t ___\n";
			std::cout << "\t\t\t\t|_  )\n";
			std::cout << "\t\t\t\t / /\n";
			std::cout << "\t\t\t\t/___|\n";
			Sleep(1000);
			system("cls");
			gotoxy(1, 15);
			std::cout << "\t\t\t\t  _ \n";
			std::cout << "\t\t\t\t / |\n";
			std::cout << "\t\t\t\t | |\n";
			std::cout << "\t\t\t\t |_|\n";
			Sleep(1000);
			break;
		}
	}
}
void run()
{
	int count = 0;
	while (true)
	{
		printPlayerCar();
		road1();

		if(count == 0)	spawnEnemyCar();
		downEnemyCar();

		if (GetAsyncKeyState(65) || GetAsyncKeyState(VK_LEFT)) movePlayerCar('l');
		if (GetAsyncKeyState(68) || GetAsyncKeyState(VK_RIGHT)) movePlayerCar('r');
		if (GetAsyncKeyState(VK_RETURN)) pauseGame();


		printPlayerCar();

		Sleep(200);
		road2();

		count++;
		if (count > 300) count = 0;	
	}
}