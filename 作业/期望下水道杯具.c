//����ֵ����ˮ��
#include<stdio.h>
void main()
{
    int n,i;
    double E;
    while(~scanf("%d",&n))
    {
        long long int a[100010]={0};//����ѭ������Ҫ���¹�0
        long long int sum=0;//����ѭ������ҲҪ���¹�0
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            sum+=a[i];
        }
        E=(sum*1.0)/n;
        printf("%.10f\n",E);
    }
}

