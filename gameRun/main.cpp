#include <iostream>
#include <Windows.h>
#include "consoleControl.h"
#include "run.h"

char map[40][70];

void initBoard()
{
	resizeConsole(600, 700);
	DisableResizeWindow();
	ShowCur(0);
	showScrollbar(0);
	//intro();
}

int main()
{
	initBoard();
	run();

	//system("pause");
	return 0;
}

//