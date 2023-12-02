#include<stdio.h>
struct node
{
    int x;//横坐标
    int y;//纵坐标
    int s;//步数
} que[2501]; //地图大小不超过50*50，所以队列扩展不会超过2500个
int a[51][51];//储存地图
int book[51][51];//用book数组标记哪些点以及在队列中了，防止一个点被重复扩展。
//tip：全局变量默认所有元素初始化为0
int main()
{
    //定义一个用于表示走的方向的数组
    int next[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};
    int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
    //k：用于枚举方向；n，m：地图大小；startx，starty：起点坐标；p，q：终点坐标；tx，ty：扩展点坐标。flag：标记是否到达终点。
    //输入地图
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            scanf("%d",&a[i][j]);
    scanf("%d %d %d %d",&startx,&starty,&p,&q);//输入起点和终点坐标
    ///初始化空队列
    int head=1;
    int tail=1;
    //往队列插入起点坐标
    que[tail].x=startx;
    que[tail].y=starty;
    que[tail].s=0;
    tail++;
    book[startx][starty]=1;

    flag=0;
    while(head<tail)//当队列不为空时循环
    {
        //枚举4个方向
        for(k=0; k<4; k++)
        {
            tx=que[head].x+next[k][0];
            ty=que[head].y+next[k][1];

            //判断是否越界
            if(tx<1||tx>n||ty<1||ty>m)
                continue;

            //判断是否是障碍物或者已在路径中
            if(a[tx][ty]==0&&book[tx][ty]==0)
            {
                //把这个点标记为已经走过
                book[tx][ty]=1;//注意宽搜每个点通常情况下只入队一次，和深搜不同，不需要将book数组还原啦。
                //插入新扩展点
                que[tail].x=tx;
                que[tail].y=ty;
                que[tail].s=que[head-1].s+1;//步数是父亲的步数+1
                tail++;
            }
            if(tx == p&&ty == q)//到达终点则推出循环
            {
                flag=1;
                break;
            }
        }
        if(flag == 1)
        {
            break;
        }
        head++;//注意这个地方前往不能忘记，当一个扩展点结束后，head++才能对下一个扩展点进行扩展
    }
    //打印末尾最后一个点（目标点）的步数
    //注意tail是指向队列的队尾的下一个位置，所以需要减一
    printf("%d",que[tail-1].s);
    return 0;
}
