#include<stdio.h>
void main()
{
    int n,k;//nΪ�ƣ�kΪ��
    int sign[1005]= {0};
    //��־ÿյ�Ƶ�״̬����ʼʱ��ȫ���رգ�����sign[i]=0��
    int i,j;
    scanf("%d %d",&n,&k);
    for(i=1; i<=n; i++) //�����ж�ÿյ��
    {
        for(j=1; j<=k; j++) //ִ��ÿ���˶�ÿյ�ƵĲ���
        {
            if(i%j==0)
            {
                if(sign[i]==0)
                    sign[i]=1;
                else
                    sign[i]=0;
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        if(sign[i]==1)
            printf("%d ",i);
    }
    printf("\n");
}
