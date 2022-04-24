#include "Refresh_scoreboard.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void refresh_scoreboard(char map[][100], int Now_score, string Name, int Best_score, int row, int col)
{
    // 初始化，在整合之后可以删除
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            map[i][j] = ' ';
            if (i == 0 || i == 6)
                map[i][j] = '-';
            if (j == 0 || j == col - 1)
                map[i][j] = '|';
        }
    }
    // 初始化结束
    char BS[15] = "Best Score: ";
    char CS[21] = "Current Score: ";
    char Na[15] = "Your Name: ";
    char Nam[100];
    // used to turn int into str
    int start_point_of_Name = 15;
    int start_point_of_Now = 15;
    int start_point_of_Best = 50;
    //-----process Name------------------
    for (int i = start_point_of_Name; i <= start_point_of_Name + 11; i++)
        map[2][i] = Na[i - start_point_of_Name];
    start_point_of_Name += 11;
    for (int i = 0; i < Name.size(); i++)
        Nam[i] = Name[i];
    for (int i = start_point_of_Name; i < start_point_of_Name + Name.size(); i++)
        map[2][i] = Nam[i - start_point_of_Name];

    // ----------------------------------

    // -----process Now score------------

    for (int i = start_point_of_Now; i <= start_point_of_Now + 14; i++)
        map[4][i] = CS[i - start_point_of_Now];
    start_point_of_Now += 15;
    int Now_pos = start_point_of_Now;
    int Num = 100000000;
    if (Now_score == 0)
        map[4][Now_pos] = (char)(48);
    else
    {
        while (Now_score != 0)
        {
            if (Now_score / Num != 0)
            {
                if (Now_score % Num == 0)
                {
                    int zerolength = log10(Num);

                    for (int i = Now_pos; i <= Now_pos + zerolength; ++i)
                    {
                        if (i == Now_pos)
                            map[4][i] = (char)(Now_score / Num + 48);
                        else
                        {
                            map[4][i] = (char)(48);
                        }
                    }
                    break;
                }
                else
                {
                    map[4][Now_pos] = (char)(Now_score / Num + 48);
                    Now_score %= Num;
                    Num /= 10;
                    Now_pos++;
                }
            }
            else
                Num /= 10;
        }
    }

    // ----------------------------------

    // process best score
    for (int i = start_point_of_Best; i <= start_point_of_Best + 11; i++)
        map[4][i] = BS[i - start_point_of_Best];
    start_point_of_Best += 12;
    int Best_pos = start_point_of_Best;
    Num = 100000000;
    if (Best_score == 0)
        map[4][Best_pos] = (char)(48);
    else
    {
        while (Best_score != 0)
        {
            if (Best_score / Num != 0)
            {
                if (Best_score % Num == 0)
                {
                    int zerolength = log10(Num);

                    for (int i = Best_pos; i <= Best_pos + zerolength; ++i)
                    {
                        if (i == Best_pos)
                            map[4][i] = (char)(Best_score / Num + 48);
                        else
                        {
                            map[4][i] = (char)(48);
                        }
                    }
                    break;
                }
                else
                {
                    map[4][Best_pos] = (char)(Best_score / Num + 48);
                    Best_score %= Num;
                    Num /= 10;
                    Best_pos++;
                }
            }
            else
                Num /= 10;
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << map[i][j];
        cout << endl;
    }
    return;
}
