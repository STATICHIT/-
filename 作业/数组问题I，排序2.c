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
                scanf("%d",&a[i]);//输入十个数
            for(j=0; j<N-1; j++)//进行N-1次循环，实现N-1次比较
                for(i=0; i<N-1-j; i++)//在每一趟中进行N-1-j次比较
                    if(a[i]>a[i+1])//相邻两次比较
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
