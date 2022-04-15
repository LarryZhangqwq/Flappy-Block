#include "Refresh_scoreboard.h"
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

void refresh_scoreborad( char map[][72], int Now_score, string Name, int Best_score, int row);
{
    //assume that the score is equal or less than 9999;
    //scores for printing
    string NowScore = "";
    string BestScore = "";
    //count the length of the scores
    int NowLength = 0;
    int BestLength = 0;
    // words to be printed out
    string BS = "Best Score"
    string CS =  "Current Score"
    // used to turn int into str
    int temp = 0; 
    char tempChar;
    for (int i = 3; i >= 0; --i){
        temp = Best_score / pow(10, i);
        if (temp == 0)
            continue;
        else{
            tempChar = temp + 48;
            BestScore += tempChar;
            BestLength += 1;
        }
    }
    temp = 0;
    tempChar = "";
    for (int i = 3; i >= 0; --i){
        temp = Now_score / pow(10, i);
        if (temp == 0)
            continue;
        else{
            tempChar = temp + 48;
            NowScore += tempChar;
            NowLength += 1;
        }
    }
    for (int i = 0; i < 13; ++i){
        map[0][i+(col/2 - 13)/2] = CS[i];
    }
    for (int i = 0; i < 10; ++i){
        map[0][i+(col/2 -10)/2+col/2] = BS[i];
    }
    for (int i = 0; i < NowLength; ++i){
        map[1][i+(col/2 - 13)/2] = NowScore[i];
    }
    for (int i = 0; i < BestLength; ++i){
        map[1][i+(col/2 -10)/2+col/2] = BestScore[i];
    }
        
}
