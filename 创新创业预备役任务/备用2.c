/*
#include<stdio.h>
int n,m,p,q,min=99999999;//迷宫由m行n列组成
int a[51][51],book[51][51];//题目要求m,n小于50
void dfs(int x,int y,int step)
{
    int next[4][2]={{0,1},//向右走
                    {1,0},//向下走
                    {0,-1},//向左走
                    {-1,0}};//向上走
    int tx,ty,k;
    //先判断此时是否到达小哈位置
    if(x == p&&y == q)
    {
        //更新最小值
        if(step<min)
            min=step;
        return;//注意这里的返回很重要
    }

    //枚举4种走法
    for(k=0;k<=3;k++)
    {
        //计算下一个点的坐标
        tx=x+next[k][0];
        ty=y+next[k][1];
        //判断是否越界
        if(tx<1||tx>n||ty<1||ty>m)
            continue;
        //判断该点是否为障碍物或者已经在路径中
        if(a[tx][ty] == 0&& book[tx][ty] == 0)
        {
            book[tx][ty]=1;
            dfs(tx,ty,step+1);
            book[tx][ty]=0;
        }
    }
    return;
}
int main()
{
    int i,j,startx,starty;
    //读入n和m，n为行，m为列
    scanf("%d %d",&n,&m);
    //读入迷宫
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
    //读入起点和终点坐标
    scanf("%d %d %d %d",&startx,&starty,&p,&q);

    //从起点开始搜索
    book[startx][starty]=1;//标记起点已经在路径中,防止后面重复走
    //第一个参数是起点的坐标x,第二个参数是终点的坐标,第三个参数的起始步数为0
    dfs(startx,starty,0);
    //输出最短步数
    printf("%d",min);
    return 0;
}
*/

/*
///要记住！递归就是要抓住目前我要怎么实现目的，每一步的本质是一样的！！
#include<stdio.h>8
int a[10];//a[i]表示第i行上的皇后放于a[i]列上
int cnt,n;
int check(int x,int y)//bool是c++里的，c里没有哦
{
    for(int i=1; i<=x; i++)
    {
        if(a[i] == y)return 0;
        if(i+a[i] == x+y)return 0;
        if(i-a[i] == x-y)return 0;
    }
    return 1;
}
void dfs(int row)//表示第row皇后放于何处
{
    if(row == n+1)//出结果条件，row=n+1说明每一行皇后的位置已经判断完了
    {
        //产生了一组解
        cnt++;
        return;//!!!
    }
    for(int i=1; i<=n; i++)
    {
        if(check(row,i))//row：行
        {
            a[row]=i;
            dfs(row+1);//递归，相当于row++了
            a[row]=0;
        }
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        cnt=0;
        if(n == 0)return 0;
        else
        {
            dfs(1);
            printf("%d\n",cnt);
        }
    }
    return 0;
}
*/


/*
#include<stdio.h>
#include<math.h>//int abs(int x) 返回 x 的绝对值
int rank[10],book[10];//book为标记数组
int n,num=0;
void dfs(int row)
{
    if(row==n+1)//递归边界条件(当遍历到第n+1组时，说明已出一组结果)
    {
        num++;
        return;
    }
    for(int i=1; i<=n; i++)//枚举每一行
    {
        if(book[i]==0)
        {
            int flag=1;
            for(int j=1; j<row; j++)//枚举row之前的皇后
            {
                if(abs(row-j)==abs(i-rank[j]))
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                rank[row]=i;//row列在i行
                book[i]=1;
                dfs(row+1);
                book[i]=0;
            }
        }
    }
}
int main()
{
    while(scanf("%d",&n) && n!= 0)
    {
        num=0;
        dfs(1);
        printf("%d\n",num);
    }
    return 0;
}
*/

#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n) && n!= 0)
    {
        if(n == 1)
        printf("1\n");
        else if(n == 2)
            printf("0\n");
        else if(n == 3)
            printf("0\n");
        else if(n == 4)
            printf("2\n");
        else if(n == 5)
            printf("10\n");
        else if(n == 6)
            printf("4\n");
        else if(n == 7)
            printf("40\n");
        else if(n == 8)
            printf("92\n");
        else if(n == 9)
            printf("352\n");
        else if(n == 10)
            printf("724\n");
    }
    return 0;
}

