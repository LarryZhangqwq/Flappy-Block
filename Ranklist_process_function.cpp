#include<iostream>
#include<algorithm>
#include<fstream>
#include"Ranklist_store_function.h"
using namespace std;

// define ranklist store function

int ranklist_store( int score )
{
	ofstream fin;
	fin.open("ranklist.txt");
	int num, ranklist[202];
	fin >> num;
	for( int i = 0; i < num; i++ )
		fin >> ranklist[i];
	fin.close();
	if( num + 1 > 200 )
		ranklist[ num - 1 ] = 0, num--;
	int ans = -1;
	for( int i = 0; i < num; i++ )
	{
		if( ranklist[i] <= score )
		{
			ans = i + 1;
			for( int j = num; j > i; j-- )
				ranklist[j] = ranklist[ j - 1 ];
			num++;
			ranklist[i] = score;
			break;
		}
	}
	if( ans == -1 )
	{
		ans = num + 1;
		ranklist[num] = score;
		num++;
	}
	ofstream fout;
	fout.open("ranklist.txt");
	fout << num << endl;
	for( int i = 0; i < num; i++ )
		fout << rank_list[i] << " ";
	fout << endl;
	fout.close();
	return ans;
} 
