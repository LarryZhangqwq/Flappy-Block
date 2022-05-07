#include <iostream>
#include "Count_marks.h"
using namespace std;
//used to count the scores at present
void countmarks(char board[][200], int row, int col, int& marks, int& count2, int & count){
    if (count >= 30){
        marks += 1;
        count2 += 1;
        count -= 30;
    }
}