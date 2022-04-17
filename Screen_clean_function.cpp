#include<iostream>
#include<cstring>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
using namespace std;

int main()
{
	for( int z = 0; z <= 1000; z++ )
    {
        for( int i = 0; i < 20; i++ )
        {
            for( int j = 0; j < 20; j++ )
                printf( "%d ", z );
            printf("\n");
        }
        usleep(200000);
        printf("\033[2J\033[1;1H");
        //usleep(1100000);

    }
   return 0;
}
