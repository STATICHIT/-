#include<stdio.h>
void main()
{
    int i,j;
    int a[2][5];
    int b[2][5];
    for(i=0;i<2;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&a[i][j]);
        }//此处无需加printf("\n");
         //二维数组输完第一行可以直接换行继续输入
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<5;j++)
        {
            b[i][j]=a[i][j];//复制数组ing
        }
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
}
