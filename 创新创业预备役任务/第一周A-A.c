/*
#include<stdio.h>
struct node
{
    char name[20];
    int age;
    float score;
};
int main()
{
    struct node a;
    scanf("%s%d%f",&a.name,&a.age,&a.score);
    printf("%s %d %f",a.name,a.age,a.score);
}
*/
#include<stdio.h>
#include<string.h>
int sum[5000000];
int main()
{
    int i,j,n,m;
    while(~scanf("%d %d",&n,&m))
    {
        memset(sum,0,5000000);
        int temp=0,a[3010];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)//Ͱ��
            for(j=i+1;j<n;j++)
                sum[a[i]+a[j]]++;

        for(temp=0,i=10000;i>=0&&temp<m;i--)
        {
            if(sum[i]!=0)
                for(j=0;j<sum[i]&&temp<m;j++)///Ҫȷ����Ч��ֹ����
                {
                    if(temp == m-1)
                    {
                        printf("%d",i);//���һ�����ݵĺ���û�ÿո�
                        temp++;
                    }
                    else if(temp!=m-1)
                    {
                        printf("%d ",i);
                        temp++;
                    }
                    //printf("temp=%d    /// ",temp);///���temp
                }
        }
        //printf("sdfa");//������һ�����ֺ����Ƿ��ж���ո�
        printf("\n");
    }
    return 0;
}
///����������޾����������⣬����˶���Ķ�������
/*��Ҫ���ǰm����Ľ������ʵ������m--�����������
�����Ͳ���i<mѽ����temp++��¼����ѽ���Ƚ�ѽ�����㣬
���Լ򵥷���ܶ࣡*/
