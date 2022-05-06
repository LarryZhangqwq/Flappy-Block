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
#include "Skill.cpp"
#include "Start_and_end_function.cpp"
#include "Display_functions.cpp"
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
	int row = 0, col = 0; // width and height of terminal
	int listnum, count = 0, ranking;
	int now_score = 0, best_score = ranklist_process(0, 0);
	int wall_height = 10;
	string name = "abc", temp;
	char map[200][200];
	getsize(row, col);
	name = start_and_end(row, col, 0, 0, 1, "");
	int box_pos = 15;
	bool u = 0;
	int skill = 0;
	init(map, row, col);
	map[box_pos][10] = '@';
	int timer = 0;
	int during_skill = 0;
	int count2 = 0;
	while (u != 1)
	{
		if (timer == 25){
			timer = 0;
			during_skill = 0;
		}
		refresh_scoreboard(map, now_score, name, best_score, row, col, skill);
		if (count % 15 == 0 && during_skill == 0)
			wall_height = Wall_create_function(map, wall_height, col, row);
		if (!kbhit())
		{
			if (box_pos + 1 == row || map[box_pos + 1][10] == '#')
			{
				ranking = ranklist_process(now_score, 1);
				temp = start_and_end(row, col, now_score, ranking, 0, name);
				u = 1;
				break;
			}
			else
			{
				map[box_pos][10] = ' ';
				box_pos += 1;
				map[box_pos][10] = '@';
			}
		}
		else
		{
			char t;
			t = get_keyboard();
			if (t == ' ')
			{
				if (box_pos <= 7 || map[box_pos - 2][10] == '#')
				{
					ranking = ranklist_process(now_score, 1);
					temp = start_and_end(row, col, now_score, ranking, 0, name);
					u = 1;
					break;
				}
				else
				{
					map[box_pos][10] = ' ';
					box_pos -= 2;
					map[box_pos][10] = '@';
				}
			}
			else if (t == 's' && during_skill == 0 && skill > 0){
				Wall_clean(map, row, col);
				during_skill = 1;
				skill -= 1;
			}
		}
		countmarks(map, row, col, now_score, count2);
		print_function(map, col, row);
		usleep(200000);
		printf("\033[2J\033[1;1H");
		move_char(map, row, col);
		count += 1;
		if (during_skill == 1){
			timer += 1;
		}
		if (count2 > 10){
			skill += 1;
			count2 -= 10;
		}
	}

	return 0;
}
