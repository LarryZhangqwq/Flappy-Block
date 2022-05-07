#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include "Getsize.h"
#include <iostream>
using namespace std;
//used to get the size of terminal
void getsize( int &x, int &y )
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		x = w.ws_row;
		y = w.ws_col;
    //printf ("lines %d\n", w.ws_row);
    //printf ("columns %d\n", w.ws_col);
    return ;  // make sure your main returns int
}

