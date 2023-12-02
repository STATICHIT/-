/*
#include<stdio.h>
#include<string.h>
int n,m;
int mp[410][410];//棋盘
int book[410][410];//标记是否走过
//学到了新招就是自定义check函数检查有没有越界
//而且以越界条件先判断好像可以节省时间
//(因为只要一个条件不满足就是越界了)
//就不需要一个一个判断不越界的条件是否满足
int check(int x,int y)
{
    if(x<1||x>n||y<1||y>m)//注意噢x>n和y<m,不要都写成n啦，棋盘范围是n*m而不是n*n
        return 0;
    return 1;//返回1或0是方便后面if条件判断
}
/*最开始下意识以为只有四个方向，定义的
数组是next[4][2],后来改的时候不记得改成
8，答案奇怪的离谱，找了半天(真的找了
久呜呜)居然是这里的问题，麻了麻了.....

int next[8][2]= {{2,1}, //下右日
    {2,-1},//下左日
    {-2,1},//上右日
    {-2,-1},//上左日
    {1,2},//右下日
    {-1,2},//右上日
    {1,-2},//左下日
    {-1,-2}
};//左上日
struct queue//因为是bfs，要用到队列结构体
{
    int x;
    int y;
} que[160001];//范围一定要大于400*400
void bfs(int x,int y)//注意是广度优先搜索哦
{
    int head=0,tail=1;
    int sum=0;//步数清零
    //初始点入队
    que[1].x=x;
    que[1].y=y;
    //标记初始点
    book[x][y]=1;
    mp[x][y]=0;
    while(head<tail)
    {
        head++;
        sum=mp[que[head].x][que[head].y]+1;//后面扩展成功的点深度都加一

        for(int i=0; i<8; i++)//从该点往每个方向遍历
        {
            int ax=que[head].x+next[i][0];
            int ay=que[head].y+next[i][1];
            if(check(ax,ay)&&book[ax][ay] == 0)//如果未到达过，将其入队
            {
                tail++;
                que[tail].x=ax;
                que[tail].y=ay;
                book[ax][ay]=1;
                mp[ax][ay]=sum;//符合要求的点步数都等于sum
            }
            //如果没进入if判断语句说该点不符合要求，通过for循环扩展下一个点即可
        }
    }
}
int main()
{
    int x,y;
    scanf("%d %d %d %d",&n,&m,&x,&y);
    memset(mp,-1,sizeof(mp));//全部初始化为-1
    bfs(x,y);
    //输出结果罢了
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            printf("%-5d",mp[i][j]);//一定一定一定一定一定不要再d后面下意识加了空格！！！血的教训呜呜呜
        }
        if(i!=n)
            printf("\n");
    }
    return 0;
}
*/
#include<stdio.h>
#include<string.h>
int n,m;
int mp[410][410];
int book[410][410];
int next[8][2]= {{2,1},
    {2,-1},
    {-2,1},
    {-2,-1},
    {1,2},
    {-1,2},
    {1,-2},
    {-1,-2}
};

int check(int x,int y)
{
    if(x<1||x>n||y<1||y>m)
        return 0;
    else
        return 1;
}
struct node
{
    int x;
    int y;
}que[2000000];//范围一定要大于400*400
void bfs(int x,int y)
{
    int head=0,tail=1;
    int sum=0;
    que[1].x=x;
    que[1].y=y;
    mp[x][y]=0;
    book[x][y]=1;


    while(head<tail)
    {
        head++;
        sum=mp[que[head].x][que[head].y]+1;//扩展点步数等于到达当前被扩展点步数加1
        for(int i=0; i<8; i++)
        {
            int ax=que[head].x+next[i][0];
            int ay=que[head].y+next[i][1];
            if(check(ax,ay)&&book[ax][ay] == 0)
            {
                tail++;
                que[tail].x=ax;
                que[tail].y=ay;
                book[ax][ay]=1;
                mp[ax][ay]=sum;

            }
        }
    }
}
int main()
{
    int x,y,i,j;
    scanf("%d %d %d %d",&n,&m,&x,&y);
    memset(mp,-1,sizeof(mp));
    bfs(x,y);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            printf("%-5d",mp[i][j]);
        }
        if(i!=n)
            printf("\n");
    }
    return 0;
}
