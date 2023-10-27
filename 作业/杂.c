#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define random(x) (rand()%x)

void main()
{
    srand((int)time(0));
    for(int x=0;x<10;x++)
        printf("%d\n",random(100));
}
