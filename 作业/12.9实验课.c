///1 ����дһ����������ʵ�δ���һ���ַ�����ͳ�ƴ��ַ�������ĸ�����֡��ո�������ַ������� ���������������ַ����Լ���������Ľ����
///�˴����õ��˽ṹ��
/*
#include<stdio.h>
#include<string.h>
struct tongji
{
    int zimu;
    int shuzi;
    int kogge;
    int qita;
};

struct tongji tj(char arr[],int l)
{
    int i;
    struct tongji o;
    o.zimu=0;
    o.shuzi=0;
    o.kogge=0;
    o.qita=0;
    for(i=0;i<l;i++)
    {
        if(arr[i]>='a'&&arr[i]<='z'||arr[i]>='A'&&arr[i]<='Z')
        {
            o.zimu++;continue;
        }
        else if(arr[i]>='0'&&arr[i]<='9')
        {
            o.shuzi++;continue;
        }
        else if(arr[i] == ' ')
        {
            o.kogge++;continue;
        }
        else
        {
            o.qita++;continue;
        }
    }
    return(o);
}
int main()
{
    char a[1000];
    struct tongji ss;
    gets(a);
    int len=strlen(a);
    ss=tj(a,len);///��Ҫ������Ҫ���������ж���һ���ṹ������������Զ��庯������ֵ��
    printf("��ĸ����%d\n��������%d\n�ո�����%d\n��������%d\n",ss.zimu,ss.shuzi,ss.kogge,ss.qita);

    return 0;
}
*/

///2����֤��°ͺղ��룺��2000���ڵ��������2����ż�����ֽܷ����������֮�ͣ������������
/*
#include<stdio.h>
void ss(int n)
{
    int i,j,Prime[2000],a[2000],k=0;
    for(i=0; i<n; i++)
        Prime[i]=1;
    Prime[0]=0;
    Prime[1]=0;
    for(i=2; i<=n; i++)
        if(Prime[i])
        {
            a[k++]=i;
            for(j=2; i*j<=n; j++)
                Prime[i*j]=0;
        }
    for(i=0; i<k; i++)
    {
        for(j=i; j<k; j++)
        {
            if(a[j]+a[i] == n)
            {
                printf("%d  %d\n",a[i],a[j]);
                break;//�ҵ����ʱa[i]����Ӧ��һ��������ȷ�ϣ������ٽ�����ѭ��
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    ss(n);
    return 0;
}
*/

///3 ������n������ʵ�����������A[n]������Ҫ�����������ŵ�����ǰ�棬��ʵ��һ������ʵ�ָù��ܡ�
#include<stdio.h>
void cz(int arr[],int n)
{
    int i,b[1000],c[1000];
    for(i=0;i<n;i++)
    {
        if(arr[i]>0)
        printf("%d ",arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]<0)
        printf("%d ",arr[i]);
    }

}
int main()
{
    int i,n,a[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    cz(a,n);
    return 0;
}
