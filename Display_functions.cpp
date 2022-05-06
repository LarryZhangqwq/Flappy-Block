#include <iostream>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
using namespace std;

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