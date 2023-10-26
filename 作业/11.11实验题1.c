///编程找到1000到2000间的所有孪生素数对。
#include<stdio.h>
#include<math.h>
int isPrime(int n)
{
    int sign=1;
    if(n==1)
        sign=0;
    else
    {
        for(int i=2; i<=sqrt(n); i++)
        {
            if(n%i==0)
                sign=0;
        }
    }
    return sign;
}
void main()
{
    int i,cnt=0;
    for(i=1000; i<2000; i++)
    {
        if(isPrime(i)&&isPrime(i+2))
        {
            printf("(%d %d)\n",i,i+2);
        }
    }
}
