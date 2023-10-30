#include<bits/stdc++.h>
using namespace std;

int n,m,p,q;
double x[1001],y[1001];//��double���ͷ���Ȩֵ����
int f[1001],num;
double sum=0;

struct EDGE
{
    int a,b;
    double v;
} e[1000001];

bool cmp(EDGE a,EDGE b)
{
    return a.v<b.v;
}

int getf(int i)
{
    if(f[i] == i)
        return i;
    else
        return f[i]=getf(f[i]);
}

void hebing(int x,int y)
{
    if( getf(x) != getf(y) )
        f[getf(y)]=getf(x);
}

//��Ϊ���ݷ�Χ�ܴ�Ҫ�ϸ���ƾ���
double weight(double x,double y,double xx,double yy)
{
  return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}

int main()
{
    cin>>n>>m;
    num=m;//�Ѿ���m������

    for(int i=1; i<=n; i++)
    {
        f[i]=i;//��һ��ѭ������ʼ�����鼯
        scanf("%lf%lf",&x[i],&y[i]);
    }

    int k=0;//�ܱ���
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)//����j=i+1,�����ظ���ߣ����Ϳռ�ʱ�临�Ӷ�
    {
        k++;
        e[k].a=i;e[k].b=j;
        e[k].v=weight(x[i],y[i],x[j],y[j]);
    }
    sort(e+1,e+1+k,cmp);
    while(m--)
    {
        cin>>p>>q;
        hebing(p,q);
    }
    //kruskal
    for(int i=1;i<=k;i++)
    {
        if( getf(e[i].a) != getf(e[i].b) )
        {
            hebing(e[i].a,e[i].b);//�����˺ϲ�Ŷ
            num++;
            sum+=e[i].v;
        }
        if(num == n-1)break;
    }
    printf("%.2lf",sum);
        return 0;
}
