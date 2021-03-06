#include <iostream>
#include <string>
#include <cmath>
#include "Refresh_scoreboard.h"
using namespace std;
//used to make the scoreboard at the top of terminal
void refresh_scoreboard(char map[][200], int Now_score, string Name, int Best_score, int row, int col, int skill)
{
    // initializing
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 || i == 6)
                map[i][j] = '-';
            if (j == 0 || j == col - 1)
                map[i][j] = '|';
        }
    }
    // end the initializing
    char BS[15] = "Best Score: ";
    char CS[21] = "Current Score: ";
    char Na[15] = "Your Name: ";
    char skillwords[20] = "Magic numbers: ";
    char Nam[100];
    // used to turn int into str
    int start_point_of_Name = col/4-5;
    int start_point_of_Now = col/4-5;
    int start_point_of_Best = col/4-5+col/2;
    int start_point_of_skill = col/4-5+col/2;
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
    for (int i = start_point_of_skill; i <= start_point_of_skill + 14; i++)
        map[2][i] = skillwords[i - start_point_of_skill];
    start_point_of_skill += 15;
    Now_pos = start_point_of_skill;
    Num = 100000000;
    if (skill == 0)
        map[2][Now_pos] = (char)(48);
    else
    {
        while (skill != 0)
        {
            if (skill / Num != 0)
            {
                if (skill % Num == 0)
                {
                    int zerolength = log10(Num);

                    for (int i = Now_pos; i <= Now_pos + zerolength; ++i)
                    {
                        if (i == Now_pos)
                            map[2][i] = (char)(skill / Num + 48);
                        else
                        {
                            map[2][i] = (char)(48);
                        }
                    }
                    break;
                }
                else
                {
                    map[2][Now_pos] = (char)(skill / Num + 48);
                    skill %= Num;
                    Num /= 10;
                    Now_pos++;
                }
            }
            else
                Num /= 10;
        }
    }
    return;
}
