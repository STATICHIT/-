#include<stdio.h>
int main()
{
    int n,i;
    while(~scanf("%d",&n))
    {   long long int x=1;
        for(i=1; i<=n; i++)
        {
            x*=11;
            x%=10000;        //n的取值可以大到10000，所以11的n次方太大了，即使是long long int 也储存不下
                             //所以应该边乘边求余，只看后面几位的与11的乘积，结果是一样的，而不要一次性把11的n次方求出来
        }
        printf("%d\n",x);
    }

    return 0;
}
