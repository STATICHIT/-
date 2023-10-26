#include<stdio.h>
void main()
{
    unsigned n,sum=0,a,b,c,ab,bc,ac,abc;
    while(~scanf("%u",&n))
    {
        a=n/2;
        b=n/3;
        c=n/5;
        ab=n/6;
        ac=n/10;
        bc=n/15;
        abc=n/30;
        sum=a+b+c-ab-ac-bc+abc;

        printf("%u\n",sum);
    }
}

/*问题 F: 数数字
描述
问题很简单有个1到n的数列，数一下其中能够被2，3，5整除的数字的个数。例如当n = 6 ，的时候有 2，3，4，5 , 6.这5个数满足条件，所以我们应该输出5，是不是很简单？

格式
输入格式
多组输入到文件尾，每组输入一个n （n < 1e9 )

输出格式
输出对应的个数*/
///时间超限是因为方法不是最简单的哦！
///时间超限经常因为数据很大的循环而出现
