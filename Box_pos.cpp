#include<iostream>
#include<algorithm>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "conio.h"
#include <unistd.h>
using namespace std;

int main()
{
	char map[100][100];
	cout << "col, row, " << endl;
	int col = 60, row = 20;
	for( int i = 0; i < row; i++ )
		for( int j = 0; j < col; j++ )
			map[i][j] = ' ';
	int box_pos = 5;
	map[box_pos][10] = '#';
	bool u = 0;
	while( u != 1 )
	{
		while(!getch())
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
	cout << 2 << endl;

	return 0;

}
