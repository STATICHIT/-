/*
#include<stdio.h>
#include<string.h>
int n,m;
int mp[410][410];//����
int book[410][410];//����Ƿ��߹�
//ѧ�������о����Զ���check���������û��Խ��
//������Խ���������жϺ�����Խ�ʡʱ��
//(��ΪֻҪһ���������������Խ����)
//�Ͳ���Ҫһ��һ���жϲ�Խ��������Ƿ�����
int check(int x,int y)
{
    if(x<1||x>n||y<1||y>m)//ע����x>n��y<m,��Ҫ��д��n�������̷�Χ��n*m������n*n
        return 0;
    return 1;//����1��0�Ƿ������if�����ж�
}
/*�ʼ����ʶ��Ϊֻ���ĸ����򣬶����
������next[4][2],�����ĵ�ʱ�򲻼ǵøĳ�
8������ֵ����ף����˰���(�������
������)��Ȼ����������⣬��������.....

int next[8][2]= {{2,1}, //������
    {2,-1},//������
    {-2,1},//������
    {-2,-1},//������
    {1,2},//������
    {-1,2},//������
    {1,-2},//������
    {-1,-2}
};//������
struct queue//��Ϊ��bfs��Ҫ�õ����нṹ��
{
    int x;
    int y;
} que[160001];//��Χһ��Ҫ����400*400
void bfs(int x,int y)//ע���ǹ����������Ŷ
{
    int head=0,tail=1;
    int sum=0;//��������
    //��ʼ�����
    que[1].x=x;
    que[1].y=y;
    //��ǳ�ʼ��
    book[x][y]=1;
    mp[x][y]=0;
    while(head<tail)
    {
        head++;
        sum=mp[que[head].x][que[head].y]+1;//������չ�ɹ��ĵ���ȶ���һ

        for(int i=0; i<8; i++)//�Ӹõ���ÿ���������
        {
            int ax=que[head].x+next[i][0];
            int ay=que[head].y+next[i][1];
            if(check(ax,ay)&&book[ax][ay] == 0)//���δ��������������
            {
                tail++;
                que[tail].x=ax;
                que[tail].y=ay;
                book[ax][ay]=1;
                mp[ax][ay]=sum;//����Ҫ��ĵ㲽��������sum
            }
            //���û����if�ж����˵�õ㲻����Ҫ��ͨ��forѭ����չ��һ���㼴��
        }
    }
}
int main()
{
    int x,y;
    scanf("%d %d %d %d",&n,&m,&x,&y);
    memset(mp,-1,sizeof(mp));//ȫ����ʼ��Ϊ-1
    bfs(x,y);
    //����������
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            printf("%-5d",mp[i][j]);//һ��һ��һ��һ��һ����Ҫ��d��������ʶ���˿ո񣡣���Ѫ�Ľ�ѵ������
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
}que[2000000];//��Χһ��Ҫ����400*400
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
        sum=mp[que[head].x][que[head].y]+1;//��չ�㲽�����ڵ��ﵱǰ����չ�㲽����1
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
