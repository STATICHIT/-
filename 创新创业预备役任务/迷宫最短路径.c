#include<stdio.h>
int min=99999999;
int a[6][6],book[6][6],o=0,r;
struct road
{
    int X[100];
    int Y[100];///一直答案错误在了这里！！！！！！存路径的数组要开的大一些！！！！！！！
}lj;
struct road minval;

void dfs(int x,int y,int step)
{
    int next[4][2]={{0,1},//向右走
                    {1,0},//向下走
                    {0,-1},//向左走
                    {-1,0}};//向上走

    int tx,ty,k;
    //先判断此时是否到达终点
    if(x == 4 && y == 4)//终点坐标为（4，4）
    {
        //更新最小值
        if(step<min)
            {
                //printf("我进来啦！\n");
                min=step;
                for(r=0;r<min;r++)//循环更新
                {
                    minval.X[r]=lj.X[r];
                    minval.Y[r]=lj.Y[r];
                    //printf("更新为(%d,%d)\n",minval.X[r],minval.Y[r]);
                }
                //printf("====我是分界线====\n");
            }
        return;//注意这里的返回很重要
    }

    //枚举4种走法
    for(k=0;k<=3;k++)
    {
        //计算下一个点的坐标
        tx=x+next[k][0];
        ty=y+next[k][1];
        //判断是否越界
        if(tx<0||tx>4||ty<0||ty>4)
            continue;
        //判断该点是否为障碍物或者已经在路径中
        if(a[tx][ty] == 0&& book[tx][ty] == 0)
        {
            book[tx][ty]=1;//要走该点了，标记该点走过
            lj.X[o]=tx;
            lj.Y[o]=ty;
            //printf("此时我的o=%d，坐标为（%d,%d）\n",o,lj.X[o],lj.Y[o]);///////////////////
            o++;
            dfs(tx,ty,step+1);
            book[tx][ty]=0;
            o--;//回溯
        }
    }
    return;
}
int main()
{
    int i,j;
    //读入迷宫
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
        scanf("%d",&a[i][j]);

    //从起点（0，0）开始搜索
    book[0][0]=1;//标记起点已经在路径中,防止后面重复走

    //第一个参数是起点的x坐标,第二个参数是起点的y坐标,第三个参数的起始步数为0
    dfs(0,0,0);
    //printf("最短步数为%d\n",min);

    //输出最短路径
    printf("(0, 0)\n");//输出起点位置
    for(r=0;r<min-1;r++)
        printf("(%d, %d)\n",minval.X[r],minval.Y[r]);
    printf("(4, 4)");
    return 0;
}




/*
#include<stdio.h>
int n,m,p,q,min=99999999;//迷宫由m行n列组成
int a[51][51],book[51][51];//题目要求m,n小于50
struct road
{
    int hen[50];
    int zhong[50];
}lj;
struct road minval;
void dfs(int x,int y,int step)
{
    int next[4][2]= {{0,1}, //向右走
                     {1,0},//向下走
                     {0,-1},//向左走
                     {-1,0}};//向上走
    int tx,ty,k;

    if(x == p&&y == q)//到达终点
    {
        //更新最小值
        if(step<min)
        {
            min=step;
            //更新路径
            for(int r=0;r<step;r++)
            {
                minval.hen[r]=lj.hen[r];
                minval.zhong[r]=lj.zhong[r];
            }
        }

        return;//注意这里的返回很重要
    }

    //枚举4种走法
    for(k=0; k<=3; k++)
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
            lj.hen[step]=tx;
            lj.zhong[step]=ty;
            printf("step=%d,,第n步 %d %d\n",step,lj.hen[step],lj.zhong[step]);//检查
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
    //读入迷宫
    for(i=0; i<5; i++)
        for(j=0; j<5; j++)
            scanf("%d",&a[i][j]);
    //读入起点和终点坐标
    startx=0;starty=0;p=4;q=4;

    //从起点开始搜索
    book[startx][starty]=1;//标记起点已经在路径中,防止后面重复走
    //第一个参数是起点的坐标x,第二个参数是终点的坐标,第三个参数的起始步数为0
    dfs(startx,starty,1);
    //输出最短步数
    ///for(i=0; i<min; i++)
       /// printf("(%d,%d)\n",minval.hen[i],minval.zhong[i]);
    return 0;
}
*/








/*
#include<stdio.h>
struct note
{
    int x;
    int y;
    int f;
    int s;
};
int main()
{
    struct note que[36];
    int a[6][6]={0},book[6][6]={0};

    int next[4][2]={{0,1},//向右走
                    {1,0},//向下走
                    {0,-1},//向左走
                    {-1,0}};//向上走

    int head,tail;
    int i,j,k,tx,ty,flag;

    //输入地图
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
    {
        scanf("%d",&a[i][j]);
    }

    //队列初始化
    head=0;
    tail=0;
    que[tail].x=0;
    que[tail].y=0;
    que[tail].f=0;
    que[tail].s=0;
    tail++;
    book[0][0]=1;

    flag=0;//用来标记是否已达到目标点

    //当队列不为空时循环
    while(head<tail)
    {

        //枚举四个方向
        for(k=0;k<4;k++)
        {
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];

            if(tx<0||tx>4||ty<0||ty>4)
                continue;

            if(a[tx][ty] == 0&&book[tx][ty] == 0)
            {
                book[tx][ty]=1;
                que[tail].x=tx;
                que[tail].y=ty;
                que[tail].f=head;
                que[tail].s=que[head].s+1;
                //printf("### x=%d,y=%d,f=%d,s=%d ###\n",que[tail].x,que[tail].y,que[tail].f,que[tail].s);
                tail++;
            }
            if(tx == 4&&ty == 4)
            {
                flag=1;
                break;
            }
        }
        if(flag == 1)
            break;
        head++;//注意这个地方！！当一个点扩展结束后，head++才能对后面的点进行扩展
    }
    //printf("最小步数为%d\n",que[tail-1].s);
    for(i=0;i<que[tail-1].s;i++)
    {
        printf("(%d,%d)\n",que[que[i].f].x,que[que[i].f].y);
    }
    return 0;

}
*/
