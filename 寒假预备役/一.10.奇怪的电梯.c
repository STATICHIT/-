#include<stdio.h>
int n,start,end,k[210];//��������㣬�յ㣬ÿ���Ӧ�Ĳ�������
int book[1000];//���
struct quene//bfs�ö���ģ�⣬�����ýṹ��ʵ��
{
    int n;//��ǰ����
    int s;//��������
} que[1000];
int main()
{
    scanf("%d %d %d",&n,&start,&end);
    for(int i=1; i<=n; i++)
        scanf("%d",&k[i]);

    //��ʼ���ն���
    int head=1,tail=1;
    //������
    que[tail].n=start;
    que[tail].s=0;
    book[start]=1;
    tail++;

    while(head<tail)//���в�Ϊ��ʱ
    {
        if(que[head].n == end)//�����ʱ�Ѿ�����Ŀ���
        {
            break;//����whileѭ��
        }
        int up=que[head].n+k[que[head].n];//���ϵ���¥
        int down=que[head].n-k[que[head].n];//���µ���¥

        if(up<=n && book[up] == 0)//�����Խ����δ�����β�
        {
            que[tail].n=up;
            que[tail].s=que[head].s+1;
            book[up]=1;
            tail++;
        }
        if(down>0&&book[down] == 0)//ͬ��
        {
            que[tail].n=down;
            que[tail].s=que[head].s+1;
            book[down]=1;
            tail++;
        }
        head++;//�����Ӳſ��Խ�����չ��һ������
    }//whileѭ��ʲôʱ���������up��down�Ĳ�¥��������Ҫ��ʱ�������������ifѭ��
    //��ʱtail��û�����ӣ��Ͳ������head�����Ծͻ�����ѭ����

    if(que[head].n == end)//ע�����ﲻ��дif(que[tail-1].n == end)����Ϊ�����һ��whileѭ��up��down���ڷ�Χ�ڵĻ���tail���1���Σ���˼����һ�¾��������ԭ�򣩣��������ac80������Ϊ����
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
    int n;//��ǰ����
    int s;//��������
} que[100000];
int main()
{
    scanf("%d %d %d",&n,&start,&end);
    for(int i=1; i<=n; i++)
        scanf("%d",&k[i]);
    //��ʼ���ն���
    int head=1,tail=1;
    //������
    que[tail].n=start;
    que[tail].s=0;
    book[que[tail].n]=1;
    tail++;

    while(head<tail)//���в�Ϊ��ʱ
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
