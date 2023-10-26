#include<stdio.h>
void main()
{
    int i,j,s,sum=0;
    for(i=2; i<=1000; i++)
    {
        s=0;
        for(j=1; j<i; j++)
        {
            if(i%j==0)
                s+=j;
        }
        if(s==i);
        sum+=i;
    }
    printf("%d\n",sum);
}
