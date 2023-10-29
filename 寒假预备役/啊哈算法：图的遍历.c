///���е�ͼ--ͼ��������ȱ���
/*
#include<stdio.h>
int min=99999999;
int book[101];//����Ƿ��߹�
int n,m;//nΪ���и�����mΪ·����
int e[101][101];//�ڽӾ���ͼ
void dfs(int cur,int dis)
{
    int j;
    if(dis>min)
        return;//�����ǰ·���Ѿ�������֮ǰ�ҵ������·������û�б�Ҫ�ٳ����ˣ�ֱ�ӷ���
    if(cur == n)//����Ѿ��������յ�
    {
        if(dis<min)//������Сֵ
            min=dis;
        return;
    }
    for(j=1; j<=n; j++)
    {
        if(e[cur][j]!=99999999&&book[j]==0)
        {
            book[j]=1;
            dfs(j,dis+e[cur][j]);//�ӳ���j������·�̼���
            book[j]=0;//֮ǰһ��̽�����֮��ȡ���Գ���j�ı��
        }
    }
    return;
}
int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    //��ʼ����ά����
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            if(i == j)
                e[i][j]=0;
            else
                e[i][j]=99999999;
        }
    //�������֮��Ĺ�ϵ
    int a,b,c;
    for(i=1; i<=m; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        e[a][b]=c;//��ʾa�ص�b�ص�·�̣�����ͼ��
    }

    //��1�ţ���㣩���г���
    book[1]=1;//����������Ѿ���·����
    dfs(1,0);//1����ǰ���б�� 0����ǰ�Ѿ��߹���·��
    printf("%d",min);

    return 0;
}
*/
///����ת��--ͼ�Ĺ�����ȱ���
#include<stdio.h>
struct node
{
    int x;//���б��
    int s;//ת������
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
            else e[i][j]=99999999;//��99999999ģ��������
        }

    for(i=1; i<=m; i++)
    {
        scanf("%d %d",&a,&b);
        e[a][b]=1;
        e[b][a]=1;
    }
    //��ʼ���ն���
    head=1;
    tail=1;

    //������
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
                que[tail].x=j;//����չ���м������
                que[tail].s=que[head].s+1;//������һ
                tail++;
                book[j]=1;//��ǳ���j�Ѿ��ڶ�����
            }
            if(que[tail].x == end)//��������յ�����һ�£��˳�ѭ��
            {
                flag=1;
                break;
            }
        }
        if(flag == 1)
            break;

        head++; //������չ
    }
    printf("%d",que[tail-1].s);

    return 0;
}
