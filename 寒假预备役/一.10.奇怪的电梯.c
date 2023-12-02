#include<stdio.h>
int n,start,end,k[210];//层数，起点，终点，每层对应的操作层数
int book[1000];//标记
struct quene//bfs用队列模拟，队列用结构体实现
{
    int n;//当前层数
    int s;//按键次数
} que[1000];
int main()
{
    scanf("%d %d %d",&n,&start,&end);
    for(int i=1; i<=n; i++)
        scanf("%d",&k[i]);

    //初始化空队列
    int head=1,tail=1;
    //起点入队
    que[tail].n=start;
    que[tail].s=0;
    book[start]=1;
    tail++;

    while(head<tail)//队列不为空时
    {
        if(que[head].n == end)//如果此时已经到达目标层
        {
            break;//跳出while循环
        }
        int up=que[head].n+k[que[head].n];//按上到几楼
        int down=que[head].n-k[que[head].n];//按下到几楼

        if(up<=n && book[up] == 0)//如果不越界且未来过次层
        {
            que[tail].n=up;
            que[tail].s=que[head].s+1;
            book[up]=1;
            tail++;
        }
        if(down>0&&book[down] == 0)//同上
        {
            que[tail].n=down;
            que[tail].s=que[head].s+1;
            book[down]=1;
            tail++;
        }
        head++;//这样子才可以接着扩展下一个点噢
    }//while循环什么时候结束：当up或down的层楼都不符合要求时，不会进入两个if循环
    //此时tail就没有增加，就不会大于head，所以就会跳出循环噢

    if(que[head].n == end)//注意这里不能写if(que[tail-1].n == end)，因为如果上一次while循环up和down都在范围内的话，tail会加1两次（我思考了一下觉得是这个原因），我最后卡在ac80就是因为这里
        printf("%d",que[head].s);
    else
        printf("-1");
    return 0;
}
/*
#include<stdio.h>
int n,start,end,k[210],ans,sign=0;
int book[100000];
struct quene
{
    int n;//当前层数
    int s;//按键次数
} que[100000];
int main()
{
    scanf("%d %d %d",&n,&start,&end);
    for(int i=1; i<=n; i++)
        scanf("%d",&k[i]);
    //初始化空队列
    int head=1,tail=1;
    //起点入队
    que[tail].n=start;
    que[tail].s=0;
    book[que[tail].n]=1;
    tail++;

    while(head<tail)//队列不为空时
    {
        if(que[head].n == end)
        {
            break;
        }
        int up=que[head].n+k[que[head].n];
        int down=que[head].n-k[que[head].n];

        if((up>n && down<0)||k[que[head].n] == 0)
        {
            sign=1;
            break;
        }

        if((book[up] == 1&&down<0)||(book[down] == 1&&up>n))
        {
            sign=1;
            break;
        }

        if(up<=n&&book[up] == 0)
        {
            que[tail].n=up;
            book[que[tail].n]=1;
            que[tail].s=que[head].s+1;
            tail++;
        }
        if(down>0&&book[down] == 0)
        {
            que[tail].n=down;
            book[que[tail].n]=1;
            que[tail].s=que[head].s+1;
            tail++;
        }
        head++;
    }
    if(sign == 0)
        printf("%d",que[tail-1].s);
    else
        printf("-1");
    return 0;
}

*/
