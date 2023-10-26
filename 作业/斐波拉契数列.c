#include<stdio.h>
void main()
{
    long long int n,i,j;
    int digui(long long int n);
    while(~scanf("%lld",&n))
        for(i=1; i<=2*n; i++)
        {
            for(j=0; j<i; j++)
            {
                printf("%lld ",digui(j));//调用了自定义函数


            }
            printf("\n");
            i++;
        }
}
int digui(long long int n)
{
    if(n==0)
    {
        return(0);
    }
    if(n==1||n==2)
    {
        return 1;
    }
    else
    {
        return(digui(n-1)+digui(n-2));
    }//递归要放在自定义函数里！
}
/*问题 I: 斐波那契数列
描述
编写一个求斐波那契数列的递归函数，输入n值，使用该递归函数，输出如样例输出的斐波那契数列。

格式
输入格式
一个整型数n

输出格式
题目可能有多组不同的测试数据，对于每组输入数据，
按题目的要求输出相应的斐波那契图形。

样例
样例输入 Copy
6
样例输出 Copy
0
0 1 1
0 1 1 2 3
0 1 1 2 3 5 8
0 1 1 2 3 5 8 13 21
0 1 1 2 3 5 8 13 21 34 55
提示
数据的最大值不会超过long long的范围*/
