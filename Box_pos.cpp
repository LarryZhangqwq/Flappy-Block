#include<iostream>
#include<algorithm>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
using namespace std;

int main()
{
	char map[100][100];
	cout << "col, row, " << endl;
	int col, row;
	cin >> col >> row;
	for( int i = 0; i < row; i++ )
		for( int j = 0; j < col; j++ )
			map[i][j] = ' ';
	string c;
	c = getchar();
	cout << c << endl;
	return 0;
}
