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
        }//�˴������printf("\n");
         //��ά���������һ�п���ֱ�ӻ��м�������
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<5;j++)
        {
            b[i][j]=a[i][j];//��������ing
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
