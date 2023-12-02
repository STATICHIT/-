#include<bits/stdc++.h>
using namespace std;

const int N=5001;
const int M=200001;
int n,m,x,y,z;
int f[N],sum,num;//���鸸�׼�����,�ܴ���,����

struct EDGE
{
    int a,b,v;
}e[M];//�ýṹ������洢�ߵĹ�ϵ����������

bool cmp(EDGE a,EDGE b)
{
    return a.v<b.v;//ʵ�ָ���v��С��������
}

int getf(int i)//���鼯�����ں���
{
    if(f[i] == i)
        return i;
    else
        return f[i]=getf(f[i]);//ѹ��·��
}

int hebing(int a,int b)
{
    if( getf(a) != getf(b) )
    {
        f[getf(b)]=getf(a);
        return 1;//˵�����������㲻��һ������,ѡ����Ȼ������Ǻϲ���һ����
    }
    else
    return 0;//˵��������������ͬһ�����ϣ���ɻ�������
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)//�ṹ����
    {
        cin>>x>>y>>z;
        e[i].a=x;e[i].b=y;e[i].v=z;
    }
    sort(e+1,e+1+m,cmp);//����Ȩֵ�����
    //��ʼ�����鼯
    for(int i=1;i<=n;i++)
        f[i]=i;
    //Kruskal
    for(int i=1;i<=m;i++)
    {
        //�жϸñ����ӵ����������Ƿ���һ������
        if( hebing(e[i].a,e[i].b) == 1)
        {
            hebing(e[i].a,e[i].b);
            num++;//������һ
            sum+=e[i].v;
        }
        if(num == n-1)break;//ѡ��n-1�����˾��˳�
    }
    if(num < n-1)
       cout<<"orz"<<endl;
    else
       cout<<sum<<endl;//�����С����
}
