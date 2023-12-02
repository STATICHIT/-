///连通块问题
#include<stdio.h>
char a[101][101];//用于保存地图
int ans,n,m;
void dfs(int x,int y)
{
    //上下左右斜上方斜下方都要考虑！
    int next[9][2]={{0,0},{1,1},{-1,-1},{-1,1},{1,-1},{0,1},{1,0},{-1,0},{0,-1}};
    a[x][y]='.';//走过的地方标记为‘.’
    int dx,dy;
    for(int i=0; i<=8; i++)//搜索周围
    {
            dx=x+next[i][0];
            dy=y+next[i][1];
            if(dx>=0&&dx<=n&&dy>=0&&dy<m&&a[dx][dy]=='W')
            {
                dfs(dx,dy);
            }
    }
    return;
}
int main()
{
    //输入地图
    scanf("%d%d",&n,&m);
    for(int i=0; i<=n; i++)
    {
        scanf("%s",a[i]);//一次输入一行
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j]=='W') //遇到W开始遍历
            {
                dfs(i,j);
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
