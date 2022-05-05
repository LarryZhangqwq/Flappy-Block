#include <iostream>
#include "Count_marks.h"

void countmarks(char board[][200], int row, int col, int& marks){
    bool judge1 = 0;
    bool judge2 = 1;
    for (int i = 0; i < row; i++){
        if (board[i][9] == '#'){
            judge1 = 1;
        }
        if (board[i][10] == '#'){
            judge2 = 0;
        }
    }
    if (judge1 && judge2){
        marks += 1;
    }
}