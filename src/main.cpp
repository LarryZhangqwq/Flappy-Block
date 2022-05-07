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
	int listnum, count = 0, ranking; //count is used as a timer
	int count3 = 0;//count3 is also a timer that is independent from count
	int now_score = 0, best_score = ranklist_process(0, 0);
	int wall_height = 10, box_pos = 15; //wall_height is the position of the center of the gap of a wall.
	int skill = 2, timer1 = 0, during_skill = 0, count2 = 0, during_transition = 0;
	char map[200][200];// the array of whole picture 
	bool u = 0;
	int hit_converter = 0, timer2 = 0, during_converter = 0;
	string name, temp;
	string magictime = "MagicTime!";
	getsize(row, col);
	init(map, row, col);
	name = start_and_end(row, col, 0, 0, 1, ""); //print the start picture of the game
	map[box_pos][10] = '@'; //initialize the block's position
	while (u != 1)
	{
		if (during_converter == 0){
			map[box_pos][10] = '@';
		}
		// change the color of block when in inversed gravity field
		if (during_converter == 1){
			map[box_pos][10] = '^';
		}
		//timer for wall cleaning skill
		if (timer1 == 35)
		{
			timer1 = 0;
			during_skill = 0;
			Wall_clean(map, row, col);
			skill_end(row, col);
		}
		// timer for gravity convertor
		if (timer2 == 25)
		{
			timer2 = 0;
			during_converter = 0;
		}
		//initialize the scoreboard
		if (during_skill == 0)
			refresh_scoreboard(map, now_score, name, best_score, row, col, skill);
		//create the random walls
		if (count % 30 == 0 && during_skill == 0)
			wall_height = Wall_create_function(map, wall_height, col, row);
		//create random convertors
		if (during_converter == 0 && count3 % 50 == 0 && during_skill == 0)
			converter_create(map, row, col, wall_height);
		if (during_converter == 0)// not in inversed gravity field
		{
			if (!kbhit())
			{
				//hit the wall and end the game
				if (box_pos + 1 == row || map[box_pos + 1][10] == '#')
				{
					ranking = ranklist_process(now_score, 1);
					temp = start_and_end(row, col, now_score, ranking, 0, name);
					u = 1;
					break;
				}
				//hit the convertor
				else if (map[box_pos + 1][10] == '$'||map[box_pos][11]=='$'||map[box_pos+1][11]=='$'||map[box_pos+1][9]=='$')
				{
					during_converter = 1;
					continue;
				}
				//move the block
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
					// hit the walls
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
					//make the block jump
					else
					{
						map[box_pos][10] = ' ';
						box_pos -= 2;
						map[box_pos][10] = '@';
					}
				}
				//start the wall cleaning skill
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
		// in the inversed gravity field(gravity drop and jump are inversed)
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
		usleep(200000);// set the refresh rate
		printf("\033[2J\033[1;1H"); //clean the terminal
		move_char(map, row, col); //make the picture move
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