#include<iostream>
#include<algorithm>
#include<fstream>
#include"Ranklist_process_function.h"
using namespace std;

int ranklist_process( int score = 0, int type )
{
	int ans = -1;
	if( type == 0 ) //get best score only
	{
		ifstream fin;
		fin.open("ranklist.txt");
		int num;
		fin >> num;
	 	fin >> ans;		
		fin.close();
	}
		
	if( type == 1 )
	{
		ifstream fin;
		fin.open("ranklist.txt");
		int num;
		fin >> num;
		int *ranklist = new int[ num + 2 ];
		for( int i = 0; i < num; i++ )
			fin >> ranklist[i];
		fin.close();
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
			fout << ranklist[i] << " ";
		fout << endl;
		fout.close();
	}
	return ans;
} 
