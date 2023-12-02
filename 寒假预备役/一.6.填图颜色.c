#include<stdio.h>
int n,a[35][35];
void dfs(int x,int y)
{
    int next[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int tx,ty,i;
    a[x][y]=-1;//把圈外的点都标记为-1
    for(i=0; i<4; i++)//每个方向依次遍历
    {
        tx=x+next[i][0];
        ty=y+next[i][1];

        if(tx > n||tx<1||ty > n||ty<1)//注意是判断扩展点哦（tx，ty）不是当前点（x，y）
            return;

        if(a[tx][ty]==0&&tx<n&&tx>=0&&tx<n&&ty>=0)//如果不在地图外且在墙内
            //关键点：a[tx][ty]==0（不能写成a[tx][ty]!=1,因为外面的点走过后会标记为-1也不为1.
        {
            //把走过的数组位置作标记。
            dfs(tx,ty);
            //a[tx][ty]=0;这里不需要回溯！！因为会先判断能不能走，不能走就不会操作
        }
    }
    return;
}
void outplace()
{
    //四个角落依次遍历
    for(int i=0; i<n; i++)
    {
        if(a[0][i]==0)//原点（0，0）往右方向
        {
            dfs(0,i);
        }
        if(a[i][0]==0)//原点（0，0）往下方向
        {
            dfs(i,0);
        }
        if(a[n-1][i]==0)//左下角（n-1，0）往右方向
        {
            dfs(n-1,i);
        }
        if(a[i][n-1]==0)//右上角（0，n-1）往下方向
        {
            dfs(i,n-1);
        }
    }
}//沿四条边搜索都走完剩下的就是被里面的

int main()
{

    scanf("%d",&n);
    //输入地图
    for(int j=0; j<n; j++)
    {
        for(int k=0; k<n; k++)
        {
            scanf("%d",&a[j][k]);
        }
    }

    outplace();//搜索标记圈外点

    //输出变化后地图
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i][j]==0)//由题意1里面的点染成2
            {
                a[i][j]=2;
            }              ///注意这两个if顺序不能反，否则-1处变成0后在下一步会变成2.
            if(a[i][j]==-1)//1外面的点恢复成1
            {
                a[i][j]=0;
            }
            //不是0也不是-1的就是墙，就输出它的值'1'即可
            printf("%d ",a[i][j]);
        }
        printf("\n");//输出时输完一行要换行
    }
    return 0;
}

/*
#include<stdio.h>
int n,a[35][35];
void dfs(int x,int y)
{
    int ax,ay,i;
    int next[4][2]= {{1,0},{0,1},{-1,0},{0,-1}};
    a[x][y]=-1;
    for(i=0; i<4; i++)
    {
        ax=x+next[i][0];
        ay=y+next[i][1];
        if(a[ax][ay] == 0 && ax>=0 && ax<n && ay>=0 && ax<n)
        {
            dfs(ax,ay);
        }
    }
    return;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    //输入方阵
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);

    for(i=0; i<n; i++)
    {
        if(a[i][0] == 0)
            dfs(i,0);
        if(a[0][i] == 0)
            dfs(0,i);
        if(a[n-1][i] == 0)
            dfs(n-1,i);
        if(a[i][n-1] == 0)
            dfs(i,n-1);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(a[i][j] == 0)///判断0
                a[i][j]=2;            ///注意这两个if顺序不能反，否则-1处变成0后在下一步会变成2.
            if(a[i][j] == -1)///判断-1
                a[i][j]=0;
            printf("%d ",a[i][j]);
        }
            printf("\n");
    }
    return 0;
}
*/
