#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"conio.h"
#include<unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
using namespace std;

char get_keyboard(void) {
  char input;
  struct termios new_settings;
  struct termios stored_settings;
  tcgetattr(0,&stored_settings);
  new_settings = stored_settings;
  new_settings.c_lflag &= (~ICANON);
  new_settings.c_cc[VTIME] = 0;
  tcgetattr(0,&stored_settings);
  new_settings.c_cc[VMIN] = 1;
  tcsetattr(0,TCSANOW,&new_settings);

  input = getchar();

  tcsetattr(0,TCSANOW,&stored_settings);
  return input;
}

int main()
{
	char map[100][100];
	cout << "col, row, " << endl;
	int col, row;
	cin >> col >> row;
	for( int i = 0; i < row; i++ )
		for( int j = 0; j < col; j++ )
			map[i][j] = ' ';
	int box_pos = 5;
	map[box_pos][10] = '#';
	bool u = 0;
	while( u != 1 )
	{
		if(!kbhit())
		{
			map[box_pos][10] = ' ';
			box_pos += 1;
			if( box_pos == row - 1 )
			{
				break;
			       	u = 1;
			}
			map[box_pos][10] = '#';
			for( int i = 0; i < row; i++ )
			{
				for( int j = 0; j < col; j++ )
	      			cout << map[i][j];
				cout << endl;
			}
			usleep(200000);
			printf("\033[2J\033[1;1H");	
		}
		else
		{
			char t; 
			t = get_keyboard();
			map[box_pos][10] = ' ';
			box_pos -= 2;
			if( box_pos < 1 )
			{
				break;
		       	u = 1;
			}
			map[box_pos][10] = '#';
			for( int i = 0; i < row; i++ )
			{
				for( int j = 0; j < col; j++ )
					cout << map[i][j];
				cout << endl;
			}
			usleep(200000);
			printf("\033[2J\033[1;1H");
		}
		printf("\033[2J\033[1;1H");
	}
	cout << 2 << endl;

	return 0;

}
