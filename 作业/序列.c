//����һ��������Num����������������ĵ�����+1��
//�����������У�ʹ��֮�͵���Num���粻���������NULL��
#include<stdio.h>
void main()
{
    int i,s=0,num,j,k;
    scanf("%d",&num);
    for(i=2;s<=num;i++)
    {
        s=s+i;
        if((num-s)%i==0)
        {
            k=(num-s)/i;
            for(j=1;j<=i;j++)
                printf("%d ",j+k);
            printf("\n");
        }
    }
}
