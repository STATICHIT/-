#include<bits/stdc++.h>
using namespace std;

const int N=1001;
const int M=10001;
int n,m,x,y,z,k;
int f[N],sum,num;//并查父亲集数组,总代价,边数

struct EDGE
{
    int a,b,v;
}e[M];//用结构体数组存储边的关系，便于排序

bool cmp(EDGE a,EDGE b)
{
    return a.v<b.v;//实现根据v从小到大排序
}

int getf(int i)//并查集找祖宗函数
{
    if(f[i] == i)
        return i;
    else
        return f[i]=getf(f[i]);//压缩路径
}

int hebing(int a,int b)
{
    if( getf(a) != getf(b) )
    {
        f[getf(b)]=getf(a);
        return 1;//说明两参数顶点不在一棵树上,选他，然后把他们合并成一棵树
    }
    else
    return 0;//说明两参数顶点在同一棵树上，会成环，丢弃
}

int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)//结构体存边
    {
        cin>>x>>y>>z;
        e[i].a=x;e[i].b=y;e[i].v=z;
    }
    sort(e+1,e+1+m,cmp);//按照权值排序边
    //初始化并查集
    for(int i=1;i<=n;i++)
        f[i]=i;
    //Kruskal
    num=n;//初始时集合数即顶点数
    for(int i=1;i<=m;i++)
    {
        //判断该边链接的两个顶点是否在一颗树上
        if( hebing(e[i].a,e[i].b) == 1)
        {
            hebing(e[i].a,e[i].b);
            num--;//边数加一
            sum+=e[i].v;
        }
        if(num == k)break;//形成了k个集合就退出
    }

       cout<<sum;//输出最小代价
}
