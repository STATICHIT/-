#include<stdio.h>
struct money//�ýṹ�崢��ÿ�ѽ����Ϣ
{
    double m;//����
    double v;//��ֵ
    double x;//�Լ۱�
};
int main()
{
    int n,i,j;
    double t;
    scanf("%d %lf",&n,&t);
    struct money a[101],temp;
    for(i=0; i<n; i++)
    {
        scanf("%lf %lf",&a[i].m,&a[i].v);
        a[i].x=a[i].v/a[i].m;//ÿ����������Ϣ�����������һ�ѵ��Լ۱�
    }
    for(j=0; j<n-1; j++)//��Ϊ��c���ԣ�����Ҫ�ֶ�����Ҳ���Դ��Ϊһ��������������
    {
        for(i=0; i<n-1-j; i++)
        {
            if(a[i].x<a[i+1].x)
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
    /*
    for(i=0; i<n; i++)//�����������Ƿ���ȷ
        printf("%d  %d  %f   \n",a[i].m,a[i].v,a[i].x);
    */
    double s=0,sum=0;
    for(i=0; i<n; i++)
    {
        s+=a[i].m;
        if(t>=s)//������ȫ��
        {
            sum+=a[i].v;
        }
        else if(t<s)//��������װ��
        {
            sum+=(t-s+a[i].m)*a[i].x;//ע�������Ǻ�a[i].x��ˣ����Ǹ����ͣ�
            break;                  //Ϊ�˷�ֹ����ת���������԰�����������ݸĳɸ�����
        }
    }
    printf("%.2lf",sum);
    return 0;
}
