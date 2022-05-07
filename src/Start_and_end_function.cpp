#include<iostream>
#include<algorithm>
#include<cstdio>
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

string start_and_end(int row, int col, int now_score, int ranking, int type, string Name ) // 等待输入名字，输入后返回string类型的名字
{
// ------- init ---------
	char map[200][200];
	for( int i = 0; i < row; i++ )
		for( int j = 0; j < col; j++ )
			map[i][j] = ' ';
// --------- End ------------

// -------- Start display ------
	if( type == 1 )
	{
		
		for( int i = 0; i < row / 6; i++ )
			cout << endl;
		for( int i = 0; i < col / 2 - 27; i++ )
			cout << " ";
		printf("\033[42m _____ _                         ____  _             _   _ \033[0m\n" );
//		cout << " _____ _                         ____  _             _   _" << endl;
		for( int i = 0; i < col / 2 - 27; i++ )
			cout << " "; 
		printf("\033[42m|  ___| | __ _ _ __  _ __  _   _| __ )| |  ___   ___| | / /\033[0m\n");
		//cout << "|  ___| | __ _ _ __  _ __  _   _| __ )| |  ___   ___| | / /" << endl;
		for( int i = 0; i < col / 2 - 27; i++ )
			cout << " "; 
		printf("\033[42m| |_  | |/ _` | '_ \\| '_ \\| | | |  _ \\| | / _ \\ / __| |/ / \033[0m\n");
		//cout << "| |_  | |/ _` | '_ \\| '_ \\| | | |  _ \\| | / _ \\ / __| |/ /" << endl;
		for( int i = 0; i < col / 2 - 27; i++ )
			cout << " ";
		printf("\033[42m|  _| | | (_| | |_) | |_) | |_| | |_) | || (_) | |__| |\\ \\ \033[0m\n"); 
		//cout << "|  _| | | (_| | |_) | |_) | |_| | |_) | || (_) | |__| |\\ \\" << endl;
		for( int i = 0; i < col / 2 - 27; i++ )
			cout << " "; 
		printf("\033[42m|_|   |_|\\__,_| .__/| .__/ \\__, |____/|_| \\___/ \\___|_| \\_\\\033[0m\n");
		//cout << "|_|   |_|\\__,_| .__/| .__/ \\__, |____/|_| \\___/ \\___|_| \\_\\" << endl;
		for( int i = 0; i < col / 2 - 27; i++ )
			cout << " "; 
		printf("\033[42m              |_|   |_|    |___/                           \033[0m\n");
		//cout << "              |_|   |_|    |___/                       " << endl;
		for( int i = row / 6 + 6; i < row - 1; i++ )
			cout << endl;
		for( int i = 0; i < col / 2 - 20; i++ )
			cout << " ";
		cout << "Please type your name to start: ";
		string s;
		cin >> s;
		return s;
	}
// -------- End ----------------

// ------- End display --------
	else if(type == 0)
	{
		for( int i = 0; i < row / 6; i++ )
			cout << endl;
		for( int i = 0; i < col / 2 - 27; i++ )
			cout << " ";
		cout << "  ____                         ___" << endl;
		for( int i = 0; i < col / 2 - 27; i++ )
			cout << " ";
		cout << " / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __" << endl;
		for( int i = 0; i < col / 2 - 27; i++ )
			cout << " ";
		cout << "| |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|" << endl;
		for( int i = 0; i < col / 2 - 27; i++ )
			cout << " ";
		cout << "| |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |" << endl;
		for( int i = 0; i < col / 2 - 27; i++ )
			cout << " ";
		cout << " \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|" << endl;
		for( int i = 0; i < 4 ; i++ )
			cout << endl;
		for( int i = 0; i < col / 2 - 10; i++ )
			cout << " ";
		cout << "Your name: " << Name << endl;
		for( int i = 0; i < col / 2 - 10; i++ )
			cout << " ";
		cout << "Your score: " << now_score << endl;
		for( int i = 0; i < col / 2 - 10; i++ )
			cout << " ";
		cout << "Your ranking: " << ranking << endl;
		for( int i = row / 6 + 5 + 4 + 3; i < row; i++ )
			cout << endl;
		return "s";
	}
// -------- End ----------------
}
void skill_transition(int row, int col){
	int start_pos = col /2 - 36;
	for (int i = 0; i < row/2-2; i++){
		cout << endl;
	}
	for (int i = 0; i < start_pos; i++){
		cout << ' ';
	}
	string line1 = "###    ###  #####   ######  ####  ######    ###### #### ###    ### ######";
	for (int i = 0; i < 73; i ++){
		if (line1[i] == '#'){
			printf("\033[0;30;41m \033[0m");
		}
		else{
			cout << ' ';
		}
	}
	cout << endl;
	for (int i = 0; i < start_pos; i++){
		cout << ' ';
	}
	string line2 = "####  #### ##   ## ##        ##  ##           ##    ##  ####  #### ##    ";
	for (int i = 0; i < 73; i ++){
		if (line2[i] == '#'){
			printf("\033[0;30;41m \033[0m");
		}
		else{
			cout << ' ';
		}
	}
	cout << endl;
	for (int i = 0; i < start_pos; i++){
		cout << ' ';
	}
	string line3 = "## #### ## ####### ##   ###  ##  ##           ##    ##  ## #### ## ####  ";
	for (int i = 0; i < 73; i ++){
		if (line3[i] == '#'){
			printf("\033[0;30;41m \033[0m");
		}
		else{
			cout << ' ';
		}
	}
	cout << endl;	
	for (int i = 0; i < start_pos; i++){
		cout << ' ';
	}
	string line4 = "##  ##  ## ##   ## ##    ##  ##  ##           ##    ##  ##  ##  ## ##    ";
	for (int i = 0; i < 73; i ++){
		if (line4[i] == '#'){
			printf("\033[0;30;41m \033[0m");
		}
		else{
			cout << ' ';
		}
	}
	cout << endl;		
	for (int i = 0; i < start_pos; i++){
		cout << ' ';
	}
  //string line5 = "##  ##  ## ##   ## ##    ##  ##  ##           ##    ##  ##  ##  ## ##    ";
    string line5 = "##      ## ##   ##  ######   ##   ######      ##   #### ##      ## ######";
	for (int i = 0; i < 73; i ++){
		if (line5[i] == '#'){
			printf("\033[0;30;41m \033[0m");
		}
		else{
			cout << ' ';
		}
	}
	cout << endl;
        usleep(3000000);
		printf("\033[2J\033[1;1H");
}