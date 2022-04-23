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
//	cout << now_high << endl;
// ------------ End ---------------------

// ---------Put new wall in map----------
	int width = 12; // set the width of wall as 12
	char ** map = new char *[ row + 40 ];
	for( int i = 0; i < row + 40; i++ )
		map[i] = new char [ col + 1 ];
	for( int i = 0; i < row + 40 ;i++ )
	{
		delete map[i];
		map[i] = NULL;
	}

	delete [row+40]map;
	map = NULL;

// ---------- End -----------------------
		
	return 0;
}
