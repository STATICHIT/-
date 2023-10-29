/*
思路:
1.结构体数组存点
2.排序
3.枚举确定两点，两点定线，检查范围后寻找线上点数
4.更新最大点数
*/
#include<bits/stdc++.h>
using namespace std;

int book[5001][5001];
int r,c,n,a,b;

struct Node
{
    int x,y;
} node[5001];//用结构体数组存点

bool cmp(Node a, Node b)
{
    return (a.x<b.x||(a.x==b.x && a.y<b.y));
}//按照a从小到大且a相等时b从小到大的顺序排列规则

bool check(int x,int y)
{
    return(x>=1&&x<=r&&y>=1&&y<=c);
}//bool类型返回值函数直接写return（条件）
//则满足返回true，不满足返回false

int main()
{
    cin>>r>>c>>n;
    //存点
    for(int i=0; i<n; i++)
    {
        cin>>a>>b;
        node[i].x=a;
        node[i].y=b;
        book[a][b]=1;
    }
    //排序
    sort(node,node+n,cmp);
    //for(int i=0;i<n;i++)cout<<node[i].x<<"  "<<node[i].y<<endl;

    //暴力枚举
    //两点确定直线判断可行性并计算点数更新ans
    int ans=0;//初始最长长度为0
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            //计算两点间距离
            int dx=node[j].x-node[i].x;
            int dy=node[j].y-node[i].y;
            //如果i点前面还有点说明它不是该线上的起始点，跳过不查
            if(check(node[i].x-dx,node[i].y-dy))continue;
            int xx=node[j].x+dx,yy=node[j].y+dy;//鉴定这方向上是否有其他点
            if(check(xx,yy) == false)continue;
            int cnt=2;//因为我们已经确定了两点
            while(check(xx,yy))//在范围内
            {
                if(book[xx][yy])
                    cnt++;
                else
                    break;
                xx+=dx,yy+=dy;
                ans=max(cnt,ans);
            }
        }
    cout<<ans;
    return 0;
}
