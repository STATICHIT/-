#include<stdio.h>
void main()
{
    int a[1005];
    int i,j,f,t,N,T;
    while(~scanf("%d",&T))
    {
        for(f=1; f<=T; f++)
        {
            scanf("%d ",&N);
            for(i=0; i<N; i++)
                scanf("%d",&a[i]);//����ʮ����
            for(j=0; j<N-1; j++)//����N-1��ѭ����ʵ��N-1�αȽ�
                for(i=0; i<N-1-j; i++)//��ÿһ���н���N-1-j�αȽ�
                    if(a[i]>a[i+1])//�������αȽ�
                    {
                        t=a[i];
                        a[i]=a[i+1];
                        a[i+1]=t;
                    }
            for(i=0; i<N; i++)
            {
                printf("%d ",a[i]);
            }
            printf("\n");
        }
    }
}
