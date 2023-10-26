//题目：编写一个程序，
//求s=1+(1+2)+(1+2+3)+…+(1+2+3+…+n)的值。
/*格式
输入格式
第一行有1个整数T，表示有T组测试数据。第二行～第T+1行，每行有1个整数N， 1<=N<=200。

输出格式
对于每组输入数据，输出一行，包含一个整数，即此时S的值。*/
#include<stdio.h>
void main()
{
    long long S,s;
    int i,j,n,T,k=1;
    scanf("%d",&T);

    while(k<=T)
    {
        S=0;
        scanf("%d",&n);
        for(i=1; i<=n; i++)//i代表计算第i组括号
        {
            s=0;
            for(j=1; j<=i; j++)//j代表每个小括号内的数
            {
                s+=j;
            }
            S+=s;
        }
        printf("%lld\n",S);
        k=k+1;
    }
}
