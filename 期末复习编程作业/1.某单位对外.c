/*
1. (编程题)
某单位对外公布员工的身份信息时，为保护员工的隐私，将职工编号信息（5位的字符）的若干位用*代替。由于操作人员不会
复杂的算法，他想了一个简单的规则：若在某一位上，该位上某编号的人数少于三人，则所有员工在该位的编号变为*。请你编程帮他实现。
输入：n   （n表示人数）

      第1个人的编号

      ……

      第n个人的编号

输出：改变后第1个人的编号

      改变后第2个人的编号

      ……

      改变后第n个人的编号

示例

输入：6

      10232

      20133

      30122

      41139

      11123

      21229

输出：

      *0*3*

      *0*3*

      *0*2*

      *1*3*

      *1*2*

      *1*2*
*/
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int a[n][6],temp[10];
    for(i=0; i<n; i++)
        for(j=0; j<5; j++)
            scanf("%d",a[i][j]);
    for(j=0; j<5; j++)
    {
        memset(temp,0,10);
        for(i=0; i<n; i++)
            temp[a[i][j]]++;
        for(int k=0; i<10; k++)
            if(temp[k]!=0&&temp[k]<3)
            {
                for(int g=0; g<n; g++)
                    a[g][j]=41;
            }

    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<5; j++)
        {
            if(a[i][j]==41)printf("%c",a[i][j]);
            else printf("%d",a[i][j]);
        }
        printf("\n");

    }
}
