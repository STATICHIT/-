#include<stdio.h>
int main()
{
    int n,i,j,sum,hang;
    float aver;
    scanf("%d",&n);
    int a[n+1][n+1];
    float v[n+1];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0; i<n; i++)
    {
        sum=0;
        for(j=0; j<n; j++)
        {
            sum=sum+a[i][j];
        }
        aver=sum*1.0/n;
        v[i]=aver;
    }
    /*for(i=0;i<n;i++)
    {printf("%f\n",v[i]);}//���ƽ��ֵ����*/
    float min=-1.0;///������������������ȡ��������min��neww
    for(i=0; i<n; i++)//��n�����
    {
        float neww=9999.0;///minѭ�����ı�Ӷ��������������
        ///��newwҪ�ָ��ܴ��ֵ����ѭ����һ����������
        for(j=0; j<n; j++)
        {
            if(v[j]>min&&v[j]<neww )//�˴���v[j]<min��
                //��Ҫ������һ����Сֵ������
            {
                neww=v[j];//Ϊ��һ���ж���С��Χ
                hang=j;
            }
        }
        for(j=0; j<n; j++)
        {
            printf("%d ",a[hang][j]);
        }
        printf("\n");
        min=v[hang];//�˴�ѭ���������Сֵ
    }
    return 0;
}
