#include<iostream>
#include<algorithm>
#include<fstream>
#include"Ranklist_store_function.h"
using namespace std;

// define ranklist store function

void ranklist_store( int rank_list[], int num )
{
	ofstream fout;
	fout.open("ranklist.txt");
	fout << num << endl;
	for( int i = 0; i < num; i++ )
		fout << rank_list[] << " ";
	cout << endl;
	fout.close();
} 
