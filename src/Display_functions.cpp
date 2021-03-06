#include <iostream>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include "Display_functions.h"
#include <termios.h>
using namespace std;
//let the picture move
void move_char(char map[][200], int row, int col)
{
	for (int i = 7; i < row; i++)
		for (int j = 1; j < col - 2; j++)
			if (map[i][j + 1] == '#')
			{
				map[i][j] = map[i][j + 1];
			}
			else if (map[i][j] != '#' && map[i][j] != ' ' && map[i][j] != '$')
			{
				map[i][j] = map[i][j];
			}
			else if (map[i][j + 1] == ' ')
				map[i][j] = ' ';
			else if(map[i][j+1] == '$')
				map[i][j] = map[i][j+1];
}
//initialize the array of the whole picture
void init(char map[][200], int row, int col)
{
	for (int i = 0; i < 200; i++)
		for (int j = 0; j < 200; j++)
			map[i][j] = ' ';
}
//print the array of the whole picture
void print_function(char map[][200], int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			if (map[i][j] == '#')
				printf("\033[0;30;42m \033[0m");
			else if (map[i][j] == '@')
				printf("\033[0;30;103m \033[0m");
			else if ((map[i][j] == '!' || (map[i][j] <= 90 && map[i][j] >= 65) || (map[i][j] >= 97 && map[i][j] <= 122)) && i >= 7)
			{
				printf("\033[1;37;41m%c\033[0m", map[i][j]);
			}
			else if (map[i][j] == '^'){
				printf("\033[0;30;105m \033[0m");
			}
			else if (map[i][j] == '$'){
				printf("\033[0;30;40m \033[0m");
			}
			else
				printf("\033[47m%c\033[0m", map[i][j]);
		std::cout << std::endl;
	}
}
//used to get the action from the keyboard
char get_keyboard(void)
{
	char input;
	struct termios new_settings;
	struct termios stored_settings;
	tcgetattr(0, &stored_settings);
	new_settings = stored_settings;
	new_settings.c_lflag &= (~ICANON);
	new_settings.c_cc[VTIME] = 0;
	tcgetattr(0, &stored_settings);
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &new_settings);

	input = getchar();

	tcsetattr(0, TCSANOW, &stored_settings);
	return input;
}