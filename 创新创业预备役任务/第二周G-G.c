///A��G����
#include <stdio.h>
#include<string.h>
int fun(int a[],int n)
{
    int b[101],i,k,top,max;
    k=1;
    top=1,max=0;//topΪջ��
    for(i=1; i<=n; i++)
    {
        b[top]=i;
        while(b[top]==a[k]&&top>0)///���ﲻ̫����⣬��ʱ���������
        {
            top--;
            k++;
        }
        top++;
        if(top>max)
            max=top;
    }
    if(k>n) return max;
    else return -1;
}
int main()
{
    int n,i,a[101];
    while(scanf("%d",&n))
    {
        for(i=1; i<=n; i++)
            scanf("%d",&a[i]);
        printf("%d\n",fun(a,n));
    }
    return 0;
}
///�ò����״���ȷ����ʱ�䳬������Ҫ���ˣ�������
