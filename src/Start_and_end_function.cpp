#include <iostream>
#include <algorithm>
#include <cstdio>
#include <time.h>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <termios.h>
#include "Start_and_end_function.h"
using namespace std;
// required: row, col, now_score, type, rank_function

string start_and_end(int row, int col, int now_score, int ranking, int type, string Name) // 等待输入名字，输入后返回string类型的名字
{
	// ------- init ---------
	char map[200][200];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			map[i][j] = ' ';
	// --------- End ------------

	int score_length = 0;
	int temp = now_score;
	if (temp / 1000 > 0)
	{
		score_length += 1;
		temp %= 1000;
	}
	if (temp / 100 > 0)
	{
		score_length += 1;
		temp %= 100;
	}
	if (temp / 10 > 0)
	{
		score_length += 1;
		temp %= 10;
	}
	score_length += 1;
	int rank_length = 0;
	temp = ranking;
	if (temp / 1000 > 0)
	{
		rank_length += 1;
		temp %= 1000;
	}
	if (temp / 100 > 0)
	{
		rank_length += 1;
		temp %= 100;
	}
	if (temp / 10 > 0)
	{
		rank_length += 1;
		temp %= 10;
	}
	rank_length += 1;
	// -------- Start display ------
	if (type == 1)
	{

		for (int i = 0; i < row / 6; i++)
			cout << endl;
		for (int i = 0; i < col / 2 - 27; i++)
			cout << " ";
		printf("\033[42m _____ _                         ____  _             _   _ \033[0m\n");
		//		cout << " _____ _                         ____  _             _   _" << endl;
		for (int i = 0; i < col / 2 - 27; i++)
			cout << " ";
		printf("\033[42m|  ___| | __ _ _ __  _ __  _   _| __ )| |  ___   ___| | / /\033[0m\n");
		// cout << "|  ___| | __ _ _ __  _ __  _   _| __ )| |  ___   ___| | / /" << endl;
		for (int i = 0; i < col / 2 - 27; i++)
			cout << " ";
		printf("\033[42m| |_  | |/ _` | '_ \\| '_ \\| | | |  _ \\| | / _ \\ / __| |/ / \033[0m\n");
		// cout << "| |_  | |/ _` | '_ \\| '_ \\| | | |  _ \\| | / _ \\ / __| |/ /" << endl;
		for (int i = 0; i < col / 2 - 27; i++)
			cout << " ";
		printf("\033[42m|  _| | | (_| | |_) | |_) | |_| | |_) | || (_) | |__| |\\ \\ \033[0m\n");
		// cout << "|  _| | | (_| | |_) | |_) | |_| | |_) | || (_) | |__| |\\ \\" << endl;
		for (int i = 0; i < col / 2 - 27; i++)
			cout << " ";
		printf("\033[42m|_|   |_|\\__,_| .__/| .__/ \\__, |____/|_| \\___/ \\___|_| \\_\\\033[0m\n");
		// cout << "|_|   |_|\\__,_| .__/| .__/ \\__, |____/|_| \\___/ \\___|_| \\_\\" << endl;
		for (int i = 0; i < col / 2 - 27; i++)
			cout << " ";
		printf("\033[42m              |_|   |_|    |___/                           \033[0m\n");
		// cout << "              |_|   |_|    |___/                       " << endl;
		for (int i = row / 6 + 6; i < row - 1; i++)
			cout << endl;
		for (int i = 0; i < col / 2 - 20; i++)
			cout << " ";
		cout << "\033[106mPlease type your name to start: \033[0m";
		string s;
		cin >> s;
		return s;
	}
	// -------- End ----------------

	// ------- End display --------
	else if (type == 0)
	{
		for (int i = 0; i < row / 6; i++)
			cout << endl;
		for (int i = 0; i < col / 2 - 27; i++)
			cout << " ";
		printf("\033[1;37;40m  ____                         ___                 \033[0m\n");
		// cout << "  ____                         ___" << endl;
		for (int i = 0; i < col / 2 - 27; i++)
			cout << " ";
		printf("\033[1;37;40m / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __ \033[0m\n");
		// cout << " / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __" << endl;
		for (int i = 0; i < col / 2 - 27; i++)
			cout << " ";
		printf("\033[1;37;40m| |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|\033[0m\n");
		// cout << "| |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|" << endl;
		for (int i = 0; i < col / 2 - 27; i++)
			cout << " ";
		printf("\033[1;37;40m| |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |   \033[0m\n");
		// cout << "| |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |" << endl;
		for (int i = 0; i < col / 2 - 27; i++)
			cout << " ";
		printf("\033[1;37;40m \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|   \033[0m\n");
		// cout << " \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|" << endl;
		for (int i = 0; i < 4; i++)
		{
			for (int i = 0; i < col / 2 - 27; i++)
				cout << " ";
			for (int j = 0; j < 51; j++)
			{
				printf("\033[1;37;40m \033[0m");
			}
			cout << endl;
		}
		for (int i = 0; i < col / 2 - 27; i++)
			cout << " ";
		for (int i = 0; i < col / 2 - 23; i++)
			printf("\033[1;37;40m \033[0m");
		printf("\033[1;37;40mYour name: %s\033[0m", Name.c_str());
		for (int i = 0; i < 23 - Name.length(); i++)
			printf("\033[1;37;40m \033[0m");
		cout << endl;
		// cout << "Your name: " << Name << endl;
		for (int i = 0; i < col / 2 - 27; i++)
			cout << " ";
		for (int i = 0; i < col / 2 - 23; i++)
			printf("\033[1;37;40m \033[0m");
		printf("\033[1;37;40mYour score: %d\033[0m", now_score);
		for (int i = 0; i < 22 - score_length; i++)
			printf("\033[1;37;40m \033[0m");
		cout << endl;
		// cout << "Your score: " << now_score << endl;
		for (int i = 0; i < col / 2 - 27; i++)
			cout << " ";
		for (int i = 0; i < col / 2 - 23; i++)
			printf("\033[1;37;40m \033[0m");
		printf("\033[1;37;40mYour ranking: %d\033[0m", ranking);
		for (int i = 0; i < 20 - rank_length; i++)
			printf("\033[1;37;40m \033[0m");
		cout << endl;
		// cout << "Your ranking: " << ranking << endl;
		for (int i = row / 6 + 12; i < row - 5; i++)
		{
			for (int i = 0; i < col / 2 - 27; i++)
				cout << " ";
			for (int j = 0; j < 51; j++)
			{
				printf("\033[1;37;40m \033[0m");
			}
			cout << endl;
		}
		for (int i = 0; i < 5; i++)
			cout << endl;
		return "s";
	}
	// -------- End ----------------
}
void skill_start(int row, int col)
{
	int start_pos = col / 2 - 36;
	for (int i = 0; i < row / 2 - 2; i++)
	{
		cout << endl;
	}
	for (int i = 0; i < start_pos; i++)
	{
		cout << ' ';
	}
	string line1 = "###    ###  #####   ######  ####  ######    ###### #### ###    ### ######";
	for (int i = 0; i < 73; i++)
	{
		if (line1[i] == '#')
		{
			printf("\033[0;30;41m \033[0m");
		}
		else
		{
			cout << ' ';
		}
	}
	cout << endl;
	for (int i = 0; i < start_pos; i++)
	{
		cout << ' ';
	}
	string line2 = "####  #### ##   ## ##        ##  ##           ##    ##  ####  #### ##    ";
	for (int i = 0; i < 73; i++)
	{
		if (line2[i] == '#')
		{
			printf("\033[0;30;41m \033[0m");
		}
		else
		{
			cout << ' ';
		}
	}
	cout << endl;
	for (int i = 0; i < start_pos; i++)
	{
		cout << ' ';
	}
	string line3 = "## #### ## ####### ##   ###  ##  ##           ##    ##  ## #### ## ####  ";
	for (int i = 0; i < 73; i++)
	{
		if (line3[i] == '#')
		{
			printf("\033[0;30;41m \033[0m");
		}
		else
		{
			cout << ' ';
		}
	}
	cout << endl;
	for (int i = 0; i < start_pos; i++)
	{
		cout << ' ';
	}
	string line4 = "##  ##  ## ##   ## ##    ##  ##  ##           ##    ##  ##  ##  ## ##    ";
	for (int i = 0; i < 73; i++)
	{
		if (line4[i] == '#')
		{
			printf("\033[0;30;41m \033[0m");
		}
		else
		{
			cout << ' ';
		}
	}
	cout << endl;
	for (int i = 0; i < start_pos; i++)
	{
		cout << ' ';
	}
	string line5 = "##      ## ##   ##  ######  ####  ######      ##   #### ##      ## ######";
	for (int i = 0; i < 73; i++)
	{
		if (line5[i] == '#')
		{
			printf("\033[0;30;41m \033[0m");
		}
		else
		{
			cout << ' ';
		}
	}
	cout << endl;
	usleep(1000000);
	printf("\033[2J\033[1;1H");
}
void skill_end(int row, int col)
{
	string line1 = "###    ###  #####   ######  ####  ######      ###### ##    ## #######    ";
	string line2 = "####  #### ##   ## ##        ##  ##           ##     ###   ## ##     ##  ";
	string line3 = "## #### ## ####### ##   ###  ##  ##           ####   ## ## ## ##      ## ";
	string line4 = "##  ##  ## ##   ## ##    ##  ##  ##           ##     ##   ### ##     ##  ";
	string line5 = "##      ## ##   ##  ######  ####  ######      ###### ##    ## #######    ";
	int start_pos = col / 2 - 36;
	for (int i = 0; i < row / 2 - 2; i++)
	{
		cout << endl;
	}
	for (int i = 0; i < start_pos; i++)
	{
		cout << ' ';
	}

	for (int i = 0; i < 73; i++)
	{
		if (line1[i] == '#')
		{
			printf("\033[0;30;41m \033[0m");
		}
		else
		{
			cout << ' ';
		}
	}
	cout << endl;
	for (int i = 0; i < start_pos; i++)
	{
		cout << ' ';
	}
	for (int i = 0; i < 73; i++)
	{
		if (line2[i] == '#')
		{
			printf("\033[0;30;41m \033[0m");
		}
		else
		{
			cout << ' ';
		}
	}
	cout << endl;
	for (int i = 0; i < start_pos; i++)
	{
		cout << ' ';
	}
	for (int i = 0; i < 73; i++)
	{
		if (line3[i] == '#')
		{
			printf("\033[0;30;41m \033[0m");
		}
		else
		{
			cout << ' ';
		}
	}
	cout << endl;
	for (int i = 0; i < start_pos; i++)
	{
		cout << ' ';
	}
	for (int i = 0; i < 73; i++)
	{
		if (line4[i] == '#')
		{
			printf("\033[0;30;41m \033[0m");
		}
		else
		{
			cout << ' ';
		}
	}
	cout << endl;
	for (int i = 0; i < start_pos; i++)
	{
		cout << ' ';
	}
	for (int i = 0; i < 73; i++)
	{
		if (line5[i] == '#')
		{
			printf("\033[0;30;41m \033[0m");
		}
		else
		{
			cout << ' ';
		}
	}
	cout << endl;
	usleep(1000000);
	printf("\033[2J\033[1;1H");
}