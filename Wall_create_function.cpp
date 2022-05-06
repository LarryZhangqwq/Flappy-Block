#include<iostream>
#include<algorithm>
#include<ctime>
#include "Wall_create_function.h"
using namespace std;
void Wall_clean(char map[][200], int row, int col){
	for (int i = 7; i < row; i++)
	{
		for(int j = 1; j < col-1; j++){
			if(map[i][j] != '@'){
				map[i][j] = ' ';
			}
		}
	}
}

int Wall_create_function( char map[][200], int pre_high, int col, int row ) 
{
// --------Create Now_high-------------
//	int pre_high, row, col; // previous highi
//	cout << "Pre_high, row, col" << endl;
//	cin >> pre_high >> row >> col;
	srand(time(0));
	int now_high = rand();
	int now_type = ( rand() % 2 == 0 )? -1: 1;
	now_high *= now_type;
	now_high = now_high % 6 + pre_high;
	if( now_high <= 10 )
		now_high += 10;
	if( now_high + 4 >= row )
		now_high -= 5;
//	cout << now_high << endl;
//	cout << now_high << endl;
// ------------ End ---------------------

// ---------Put new wall in map----------
	int width = 6; // set the width of wall as 12
//	char map[200][200];
//	for( int i = 0; i < row; i++ )
//		for( int j = 0; j < col; j++ )	
//			map[i][j] = ' ';
	int now_col = 70;
	for( int i = 7; i < row; i++ )
	{
		if( i >= now_high - 2 && i <= now_high + 2 )
			continue;
		for( int j = now_col - width / 2; j <= now_col + width / 2; j++ )
			map[i][j] = '#';
		if( i == now_high - 3 || i == now_high + 3 )
			map[i][ now_col - width / 2 - 1 ] = '#', map[i][ now_col + width / 2 + 1 ] = '#';
	}
// ---------- End -----------------------
		
	return now_high;
}
