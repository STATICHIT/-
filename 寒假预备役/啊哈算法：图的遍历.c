///城市地图--图的深度优先遍历
/*
#include<stdio.h>
int min=99999999;
int book[101];//标记是否走过
int n,m;//n为城市个数，m为路线数
int e[101][101];//邻接矩阵图
void dfs(int cur,int dis)
{
    int j;
    if(dis>min)
        return;//如果当前路程已经超多了之前找到的最短路径，就没有必要再尝试了，直接返回
    if(cur == n)//如果已经到达了终点
    {
        if(dis<min)//更新最小值
            min=dis;
        return;
    }
    for(j=1; j<=n; j++)
    {
        if(e[cur][j]!=99999999&&book[j]==0)
        {
            book[j]=1;
            dfs(j,dis+e[cur][j]);//从尝试j出发，路程加上
            book[j]=0;//之前一步探索完毕之后，取消对城市j的标记
        }
    }
    return;
}
int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    //初始化二维矩阵
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            if(i == j)
                e[i][j]=0;
            else
                e[i][j]=99999999;
        }
    //读入城市之间的关系
    int a,b,c;
    for(i=1; i<=m; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        e[a][b]=c;//表示a地到b地的路程（有向图）
    }

    //从1号（起点）城市出发
    book[1]=1;//标记起点城市已经在路径中
    dfs(1,0);//1：当前城市编号 0：当前已经走过的路程
    printf("%d",min);

    return 0;
}
*/
///最少转机--图的广度优先遍历
#include<stdio.h>
struct node
{
    int x;//城市编号
    int s;//转机次数
};
int main()
{
    struct node que[2501];
    int e[51][51]= {0},book[51]= {0};
    int head,tail;
    int i,j,cur,n,m,a,b,start,end,flag=0;
    scanf("%d %d",&n,&m);
    scanf("%d %d",&start,&end);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            if(i == j) e[i][j]=0;
            else e[i][j]=99999999;//用99999999模拟正无穷
        }

    for(i=1; i<=m; i++)
    {
        scanf("%d %d",&a,&b);
        e[a][b]=1;
        e[b][a]=1;
    }
    //初始化空队列
    head=1;
    tail=1;

    //起点入队
    que[tail].x=start;
    que[tail].s=0;
    tail++;
    book[start]=1;

    while(head<tail)
    {
        cur=que[head].x;
        for(j=1; j<=n; j++)
        {
            if(e[cur][j]!=99999999&&book[j]==0)
            {
                que[tail].x=j;//把扩展城市加入队列
                que[tail].s=que[head].s+1;//次数加一
                tail++;
                book[j]=1;//标记城市j已经在队列中
            }
            if(que[tail].x == end)//如果到达终点则标记一下，退出循环
            {
                flag=1;
                break;
            }
        }
        if(flag == 1)
            break;

        head++; //继续扩展
    }
    printf("%d",que[tail-1].s);

    return 0;
}
