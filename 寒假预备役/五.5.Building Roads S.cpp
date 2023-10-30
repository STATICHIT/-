#include<bits/stdc++.h>
using namespace std;

int n,m,p,q;
double x[1001],y[1001];//用double类型方便权值计算
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

//因为数据范围很大，要严格控制精度
double weight(double x,double y,double xx,double yy)
{
  return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}

int main()
{
    cin>>n>>m;
    num=m;//已经有m条边了

    for(int i=1; i<=n; i++)
    {
        f[i]=i;//蹭一下循环来初始化并查集
        scanf("%lf%lf",&x[i],&y[i]);
    }

    int k=0;//总边数
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)//这里j=i+1,避免重复存边，降低空间时间复杂度
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
            hebing(e[i].a,e[i].b);//别忘了合并哦
            num++;
            sum+=e[i].v;
        }
        if(num == n-1)break;
    }
    printf("%.2lf",sum);
        return 0;
}
