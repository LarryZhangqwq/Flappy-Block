#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;


int main()
{
// --------Create Now_high-------------
	int pre_high, row, col; // previous high
	cout << "Pre_high, row, col" << endl;
	cin >> pre_high >> row >> col;
	srand(time(0));
	int now_high = rand();
	int now_type = ( rand() % 2 == 0 )? -1: 1;
	now_high *= now_type;
	now_high = now_high % 6 + pre_high;
	if( now_high <= 3 )
		now_high += 4;
	if( now_high + 4 >= row )
		now_high -= 5;
	cout << now_high << endl;
//	cout << now_high << endl;
// ------------ End ---------------------

// ---------Put new wall in map----------
	int width = 6; // set the width of wall as 12
	char map[200][200];
	for( int i = 0; i < row; i++ )
		for( int j = 0; j < col; j++ )	
			map[i][j] = ' ';
	int now_col = 10;
	for( int i = 0; i < row; i++ )
	{
		if( i >= now_high - 2 && i <= now_high + 2 )
			continue;
		for( int j = now_col - width / 2; j <= now_col + width / 2; j++ )
			map[i][j] = '#';
		if( i == now_high - 3 || i == now_high + 3 )
			map[i][ now_col - width / 2 - 1 ] = '#', map[i][ now_col + width / 2 + 1 ] = '#';
	}
	for( int i = 0; i < row; i++ )
	{
		for( int j = 0; j < col; j++ )	
			if( map[i][j] == '#' )
				printf("\033[0;30;42m \033[0m");
			else
				cout << " ";
		cout << endl;
	}
// ---------- End -----------------------
		
	return 0;
}
