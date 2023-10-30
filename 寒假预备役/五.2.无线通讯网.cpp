//就是要最小代价生成s个集合，其中有4个顶点，权值即距离要自己算
#include<bits/stdc++.h>
using namespace std;
int s,p;//p为哨所数量（顶点数）
int a,b,x[510],y[510];
int f[501],num;//num为集合数

struct EDGE
{
    int a,b;
    double v;
}e[250001];//范围要大于500*500用结构体数组存储边的关系，便于排序

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

double weight(int x,int y,int xx,int yy)//求两点距离即权值
{
    return sqrt((x - xx)*(x - xx) + (y - yy)*(y - yy));
}

int main()
{
    int i;
    cin>>s>>p;
    for(i=1;i<=p;i++)
    {
        f[i]=i;
        cin>>a>>b;
        x[i]=a;y[i]=b;
    }
    ///算权值,存边
    int k=0;
    for(i=1;i<=p;i++)
        for(int j=i+1;j<=p;j++)//这里j=i+1,避免重复存边，降低空间时间复杂度
    {
        k++;
        e[k].a=i;e[k].b=j;
        e[k].v=weight(x[i],y[i],x[j],y[j]);
    }

    sort(e+1,e+1+k,cmp);//按照权值排序边
    num=p;//集合数一开始等于结点数
    //Kruskal
    for(i=1;i<=k;i++)
    {
        //判断该边链接的两个顶点是否在一颗树上
        if( hebing(e[i].a,e[i].b) == 1)
        {
            hebing(e[i].a,e[i].b);
            num--;
        }
        if(num == s)break;//当集合数等于s时结束，剩下的集合可以用s个无线电收发器连接
    }
       printf("%.2 lf", e[i].v);//第i条边的长度即为最小值
}
