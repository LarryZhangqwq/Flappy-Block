#include <iostream>
#include "Count_marks.h"
using namespace std;
void countmarks(char board[][200], int row, int col, int& marks, int& count2, int & count){
    if (count >= 30){
        marks += 1;
        count2 += 1;
        count -= 30;
    }
}