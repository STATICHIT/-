//题目：编写程序，输出9*9乘法口决。
#include<stdio.h>
void main()
{
    int i,j;//i为行，j为列
        for(i=1;i<=9;i++)
        {
            for(j=1;j<=i;j++)//每一列的式子个数为行数
            {
                printf("%d*%d=%d\t",j,i,j*i);
                if(i==j)
                    printf("\n");
            }
        }

}
