#include <iostream>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <stdio.h>
using namespace std;

void getsize( int &x, int &y )
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		x = w.ws_row;
		y = w.ws_col;
    return ;  // make sure your main returns int
}


void move_char( char map[][200], int row, int col )
{
	for( int i = 7; i < row; i++ )
		for( int j = 1; j < col - 2; j++ )
			if( map[i][ j + 1 ] != '@' )
				map[i][j] = map[i][ j + 1 ];
			else
				map[i][j] = ' ';

}

void init( char map[][200], int row ,int col )
{
	for( int i = 0; i < row; i++ )
		for( int j = 0; j < col; j++ )
			map[i][j] = ' ';
}
void print_function( char map[][200], int col, int row )
{
	for( int i = 0; i < row; i++ )
	{
		for( int j = 0; j < col; j++ )	
			if( map[i][j] == '#' )
				printf("\033[0;30;42m \033[0m");
			else if( map[i][j] == '@')
				printf("\033[0;30;103m \033[0m");
			else
				cout << map[i][j];
		cout << endl;
	}
}

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