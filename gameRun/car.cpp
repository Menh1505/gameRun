#include <iostream>
#include "car.h"
#include "consoleControl.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <stack>

struct playerCar
{
	int x; //toạ độ x
	int y; // toạ độ y
	int front_left; // bánh trái trên
	int front_right; // bánh phải trên
	int back_left; // bánh trái dưới
	int back_right; // bánh phải dưới

} player = { 38, 36 };
void printPlayerCar()
{
	gotoxy(player.x, player.y);
	std::cout << "@  @";
	gotoxy(player.x, player.y + 1);
	std::cout << " ## ";
	gotoxy(player.x, player.y + 2);
	std::cout << "@  @";
}
void movePlayerCar(char c)
{
	switch (c)
	{
	case 'l':
		if (player.x >= 7 + 4)
		{
			player.x -= 4;
		}
		break;
	case 'r':
		if (player.x <= 69 - 4)
		{
			player.x += 4;
		}
		break;
	}
}

struct enemyCar
{
	int x;
	int y;
	enemyCar* nextCar;
} enemyN1;

void enemyList()
{
	std::stack<enemyCar> enemy;
	if (enemy.size() <= 5)
	{
		enemyCar tmp{ 10 + rand() % (67 - 10 + 1) , 1};

		enemy.push(tmp);
	}

	for (int i = 1; i <= enemy.size(); ++i)
	{
		printEnemyCar(enemy.top().x, enemy.top().y);

	}
}
void printEnemyCar(int x, int y)
{
	gotoxy(x, y);
	std::cout << "0  0";
	gotoxy(x, y + 1);
	std::cout << " ## ";
	gotoxy(x, y + 2);
	std::cout << "0  0";
}
void downEnemyCar() 
{
	//clearScreen();
	enemyN1.y++;
	printEnemyCar(enemyN1.x, enemyN1.y);
	if (enemyN1.y > 37) spawnEnemyCar();
}
void spawnEnemyCar()
{
	enemyN1.x = 10 + rand() % (67 - 10 + 1); // chọn vị trí ngẫu nhiên để spawn
	enemyN1.y = 1;
}

// x: 10->65, y: 0->39