#include <iostream>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Wall_create_function.cpp"
#include "Skill.cpp"
using namespace std;

int main()
{
// ---- init -------
	char map[200][200];
	int col, row, h;
	int time_gap = 200000;
	cout << "col, row, h" << endl;
	cin >> col >> row >> h;
	for( int i = 0; i <= row; i++ )	
		for( int j = 0; j <= col; j++ )
			map[i][j] = ' ';
// ----- End ------
	for( int z = 0; z < 1000; z++ )
	{
		if( z % 15 == 0 )
			h = Wall_create_function( map, h, col, row );
		for( int i = 0; i < row; i++ )
			for( int j = 0; j < col; j++ )
				map[i][j] = map[i][ j + 1 ];
		print_function( map, col, row );
		usleep(time_gap);
//		skill( map, col, row );
	}
	return 0;
}
