#include<bits/stdc++.h>
using namespace std;
int n,m,p,q,numm,numh;
int f[1000000];
int findd(int x)//�����ڣ����鼯��д������
{
    if(f[x] == x)
        return x;
    else
    return f[x]=findd(f[x]);//ѹ��·��
}
void hb(int x,int y)//�ϲ����ϣ����鼯��д������
{
    int fx=findd(x);
    int fy=findd(y);
    if(fx!=fy)
        f[fx]=fy;
}
int main()
{
    cin>>n>>m>>p>>q;

    for(int i=1;i<=n+m;i++)//��Ҫ���ˣ�����ʼ�����鼯
        f[i]=i;//����Լ������Լ����ϴ�

    for(int i=1;i<=p;i++)//���������Ϣ�ϲ�С����
    {
        int a,b;
        cin>>a>>b;
        hb(a,b);
    }

    for(int i=1;i<=q;i++)//����ȫ��Ů�˵Ĺ�˾
    {
        int a,b;
        cin>>a>>b;//��ΪŮ�����ø������������鲻���ڸ����±�
        a=-1*a+n;b=-1*b+n;//�����Ȱ�a��b��Ϊ�������ټ���n��������˱��غ�
        hb(a,b);
    }

    for(int i=1;i<=n;i++)
    {
        if(findd(i)==findd(1))//�������С�������ѵ�����
            numm++;
    }
    for(int i=n+1;i<=n+m;i++)
    {//n+1��n+m����Ů��f����
        if(findd(i)==findd(1+n))//�������С�������ѵ�Ů��
            numh++;     //С��ı����-1��ת��Ϊ�غ�����Ϊ-1*-1+n��1+n��
    }
    int ans=min(numm,numh);//�̰�ЧӦ�����ս��ȡ�����ٵ���һ��
    cout<<ans;
    return 0;
}
