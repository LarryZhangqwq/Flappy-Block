#include <iostream>
#include <algorithm>
#include <cstdio>
#include "Skill.h"
using namespace std;
// used for the wall cleaning
void skill( char map[][200], int col, int row )
{
	for( int i = 0; i < row; i++ )
		for( int j = 0 ; j < col; j++ )
			if( map[i][j] == '#' )
				map[i][j] = ' ';

}
	
