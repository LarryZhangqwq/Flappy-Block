#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "conio.h"
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "Count_marks.cpp"
#include "Getsize.cpp"
#include "Wall_create_function.cpp"
#include "Ranklist_process_function.cpp"
#include "Refresh_scoreboard.cpp"
#include "Skill.h"
#include "Start_and_end_function.cpp"
using namespace std;

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

int main()
{
	int row = 0;
	int col = 0; //width and height of terminal 
	int count = 0;
	int now_score = 0;
	int best_score = ranklist_process(0);
	int wall_height = 10;
	string name;
	char map[row][200];
	getsize(row, col);
	name = start_and_end(row, col, 1);
	int box_pos = 5;
	map[box_pos][10] = '#';
	bool u = 0;
	while (u != 1)
	{
		refresh_scoreboard(map, now_score, name, best_score, row, col);
		if (count % 15 == 0){
			wall_height = Wall_create_function(map, wall_height, col, row);
		}
		if (!kbhit())
		{
			if (map[box_pos + 1][10] == '#')
			{
				start_and_end(row, col, now_score, 0);
				ranklist_process(now_score,1);
				break;
			}
			else
			{
				map[box_pos][10] = ' ';
				box_pos += 1;
				if (box_pos == row - 1)
				{
					start_and_end(row, col, now_score, 0);
					ranklist_process(now_score,1);
					break;
					u = 1;
				}
				map[box_pos][10] = '#';
			}
		}
		else
		{
			char t;
			t = get_keyboard();
			if (map[box_pos - 2][10] == '#')
			{
				start_and_end(row, col, now_score, 0);
				ranklist_process(now_score,1);
				break;
			}
			else
			{
				map[box_pos][10] = ' ';
				box_pos -= 2;
				if (box_pos < 1)
				{
					start_and_end(row, col, now_score, 0);
					ranklist_process(now_score,1);
					break;
					u = 1;
				}
				map[box_pos][10] = '#';
			}
		}
		countmarks(map, row, col, now_score);
		print_function(map, col, row);
		printf("\033[2J\033[1;1H");
		count += 1;
		usleep(200000);
	}

	return 0;
}
