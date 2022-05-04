#include <iostream>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Wall_create_function.cpp"
using namespace std;

int main()
{
// ---- init -------
	char map[200][200];
	int col, row, h;
	cout << "col, row, h" << endl;
	cin >> col >> row >> h;
	for( int i = 0; i <= row; i++ )	
		for( int j = 0; j <= col; j++ )
			map[i][j] = ' ';
// ----- End ------
	for( int z = 0; z < 10; z++ )
	{
		h = Wall_create_function( map[200][200], h, col, row );
		for( int i = 0; i < row; i++ )
			for( int j = 0; j < col; j++ )
				map[i][j] = map[i][ j + 1 ];
		usleep(200000);
	}
	return 0;
}
