#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "../lib/conio.h"
#include "Count_marks.h"
#include "Wall_create_function.h"
#include "Ranklist_process_function.h"
#include "Refresh_scoreboard.h"
#include "Skill.h"
#include "Start_and_end_function.h"
#include "Display_functions.h"
#include "Getsize.h"
using namespace std;

int main()
{
	int row = 0, col = 0; // width and height of terminal
	int listnum, count = 0, ranking;
	int count3 = 0;
	int now_score = 0, best_score = ranklist_process(0, 0);
	int wall_height = 10, box_pos = 15;
	int skill = 2, timer1 = 0, during_skill = 0, count2 = 0, during_transition = 0;
	char map[200][200];
	bool u = 0;
	int hit_converter = 0, timer2 = 0, during_converter = 0;
	string name, temp;
	string magictime = "MagicTime!";
	getsize(row, col);
	init(map, row, col);
	name = start_and_end(row, col, 0, 0, 1, "");
	map[box_pos][10] = '@';

	while (u != 1)
	{
		if (during_converter == 0){
			map[box_pos][10] = '@';
		}
		if (during_converter == 1){
			map[box_pos][10] = '^';
		}
		if (timer1 == 35)
		{
			timer1 = 0;
			during_skill = 0;
			Wall_clean(map, row, col);
			skill_end(row, col);
		}
		if (timer2 == 25)
		{
			timer2 = 0;
			during_converter = 0;
		}
		if (during_skill == 0)
			refresh_scoreboard(map, now_score, name, best_score, row, col, skill);
		if (count % 30 == 0 && during_skill == 0)
			wall_height = Wall_create_function(map, wall_height, col, row);
		if (during_converter == 0 && count3 % 50 == 0 && during_skill == 0)
			converter_create(map, row, col, wall_height);
		if (during_converter == 0)// not in inversed gravity field
		{
			if (!kbhit())
			{
				if (box_pos + 1 == row || map[box_pos + 1][10] == '#')
				{
					ranking = ranklist_process(now_score, 1);
					temp = start_and_end(row, col, now_score, ranking, 0, name);
					u = 1;
					break;
				}
				else if (map[box_pos + 1][10] == '$'||map[box_pos][11]=='$'||map[box_pos+1][11]=='$'||map[box_pos+1][9]=='$')
				{
					during_converter = 1;
					continue;
				}
				else
				{
					map[box_pos][10] = ' ';
					box_pos += 1;
					map[box_pos][10] = '@';
				}
			}
			else// in inversed gravity field
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
					else if (map[box_pos - 2][10] == '$'||map[box_pos-1][10] == '$'||map[box_pos-1][9]=='$'||map[box_pos][9]=='$'||map[box_pos-1][11]=='$')
					{
						during_converter = 1;
						continue;
					}
					else
					{
						map[box_pos][10] = ' ';
						box_pos -= 2;
						map[box_pos][10] = '@';
					}
				}
				else if (t == 's' && during_skill == 0 && skill > 0)
				{
					Wall_clean(map, row, col);
					for (int i = col / 2 - 5; i < col / 2 + 5; i++)
					{
						map[7][i] = magictime[i - col / 2 + 5];
					}
					during_skill = 1;
					skill--;
					skill_start(row, col);
				}
			}
		}
		else
		{
			if (!kbhit())
			{
				if (box_pos == 7 || map[box_pos - 1][10] == '#')
				{
					ranking = ranklist_process(now_score, 1);
					temp = start_and_end(row, col, now_score, ranking, 0, name);
					u = 1;
					break;
				}
				else
				{
					map[box_pos][10] = ' ';
					box_pos -= 1;
					map[box_pos][10] = '^';
				}
			}
			else
			{
				char t;
				t = get_keyboard();
				if (t == ' ')
				{
					if (box_pos >= row - 1 || map[box_pos + 2][10] == '#')
					{
						ranking = ranklist_process(now_score, 1);
						temp = start_and_end(row, col, now_score, ranking, 0, name);
						u = 1;
						break;
					}
					else
					{
						map[box_pos][10] = ' ';
						box_pos += 2;
						map[box_pos][10] = '^';
					}
				}
				else if (t == 's' && during_skill == 0 && skill > 0)
				{
					Wall_clean(map, row, col);
					for (int i = col / 2 - 5; i < col / 2 + 5; i++)
					{
						map[row - 1][i] = magictime[i - col / 2 + 5];
					}
					during_skill = 1;
					skill--;
					skill_start(row, col);
				}
			}
		}

		countmarks(map, row, col, now_score, count2, count);
		print_function(map, col, row);
		usleep(200000);
		printf("\033[2J\033[1;1H");
		move_char(map, row, col);
		count += 1;
		count3 += 1;
		if (during_skill == 1)
		{
			timer1 += 1;
		}
		if (during_converter == 1)
		{
			timer2 += 1;
		}
		if (count2 > 10)
		{
			skill += 1;
			count2 -= 10;
		}
	}
	return 0;
}