#include<stdio.h>
void main()
{
    int i,j,sign;
    for(i=101; i<1000; i=i+2)
    {
        sign=1;
        for(j=2; j*j<i; j++)
        {
            if(i%j==0)
                sign=0;
        }
        if(sign)
        printf("%d\t",i);

    }
}
