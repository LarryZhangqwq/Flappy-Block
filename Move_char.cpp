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

void move_char(char map[][200], int row, int col)
{
	for( int i = 0; i < row; i++ )
		for( int j = 0; j < col; j++ )
			map[i][j] = map[i][ j + 1 ];
}
