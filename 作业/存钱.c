#include<stdio.h>
int qs(int n)//��תʮ
{
    int k=1,N,ans=0;
    while(n!=0)
    {
        N=n%10;
        n=n/10;
        ans+=N*k;//��һ��ѭ���˴�k=1.����λ����7��0�η�
        k=k*7;//��λ���ֳ�1��ʮλ���ֳ�7����λ���ֳ�7*7....�����ֱ�ӵõ�ʮ������ʽ���
    }
    return(ans);
}
int sq(int n,int m)//ʮתm����
{
    int k=1,N,a,ans=0;
    while(n!=0)
    {
        N=n%m;
        n=n/m;
        ans+=N*k;
        k=k*10;//��λ���ֳ�1��ʮλ���ֳ�10����λ���ֳ�100....�����ֱ�ӵõ�m������ʽ���
    }
    return(ans);
}
int main()
{
    int i,t,n,m,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        ans=qs(n);//�Ȱ��߽������תΪʮ����
        ans=ans+m;//�ټ���Ҫ���ʮ����Ǯ��
        ans=sq(ans,7);//�����Ǯ����תΪ�߽���
        printf("%d\n",ans);
    }
    return 0;
}
