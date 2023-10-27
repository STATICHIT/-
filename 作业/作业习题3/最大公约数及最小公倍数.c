#include<stdio.h>

void main()

{
    long a,i,t,r;
    long long int q,d,b;//d为最小公倍数
   while(~scanf("%ld %ld",&a,&b))
   {q=a*b;//q为两数之积，两数之积等于他们的最大公约数与最小公倍数之积
        if(a<b)
        {
            t=a;
            a=b;
            b=t;
        }
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;//如果余数不为0，要再用小的数除以余数直到余数为0，除数即为最大公约数。

        }

        printf("%ld\n",b);//b为最大公约数
        d=q/b;
        printf("%lld\n",d);
   }


}

