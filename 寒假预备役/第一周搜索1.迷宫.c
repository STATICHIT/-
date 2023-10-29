#include<stdio.h>
int n,m,t,sum=0;//N为行，M为列，T为障碍总数
int sx,sy,fx,fy,cx,cy;//起点坐标SX,SY，终点坐标FX,FY, 障碍坐标CX，CY
int a[6][6],book[6][6];
void dfs(int x,int y)
{
    int next[4][2]={{0,1},//向右
                    {1,0},//向下
                    {0,-1},//向左
                    {-1,0}};//向上

    if(x == fx&&y == fy)//到达终点
    {
        sum++;
        return;
    }

    int tx,ty,k;
    //枚举四种走法
    for(k=0;k<4;k++)
    {
        tx=x+next[k][0];
        ty=y+next[k][1];

        if(tx<1||ty<1||tx>n||ty>m)
            continue;
        if(a[tx][ty] == 0&&book[tx][ty] == 0)
        {
            book[tx][ty]=1;
            dfs(tx,ty);
            book[tx][ty]=0;
        }
    }
    return ;
}
int main()
{
    scanf("%d %d %d",&n,&m,&t);
    scanf("%d %d %d %d",&sx,&sy,&fx,&fy);
    int k=0;
    while(t--)
    {
        scanf("%d %d",&cx,&cy);
        a[cx][cy]=1;//标记障碍处
    }
    book[sx][sy]=1;//标记起点已经在路径中
    dfs(sx,sy);
    printf("%d",sum);
    return 0;
}
