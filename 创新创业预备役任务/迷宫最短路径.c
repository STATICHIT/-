#include<stdio.h>
int min=99999999;
int a[6][6],book[6][6],o=0,r;
struct road
{
    int X[100];
    int Y[100];///һֱ�𰸴����������������������·��������Ҫ���Ĵ�һЩ��������������
}lj;
struct road minval;

void dfs(int x,int y,int step)
{
    int next[4][2]={{0,1},//������
                    {1,0},//������
                    {0,-1},//������
                    {-1,0}};//������

    int tx,ty,k;
    //���жϴ�ʱ�Ƿ񵽴��յ�
    if(x == 4 && y == 4)//�յ�����Ϊ��4��4��
    {
        //������Сֵ
        if(step<min)
            {
                //printf("�ҽ�������\n");
                min=step;
                for(r=0;r<min;r++)//ѭ������
                {
                    minval.X[r]=lj.X[r];
                    minval.Y[r]=lj.Y[r];
                    //printf("����Ϊ(%d,%d)\n",minval.X[r],minval.Y[r]);
                }
                //printf("====���Ƿֽ���====\n");
            }
        return;//ע������ķ��غ���Ҫ
    }

    //ö��4���߷�
    for(k=0;k<=3;k++)
    {
        //������һ���������
        tx=x+next[k][0];
        ty=y+next[k][1];
        //�ж��Ƿ�Խ��
        if(tx<0||tx>4||ty<0||ty>4)
            continue;
        //�жϸõ��Ƿ�Ϊ�ϰ�������Ѿ���·����
        if(a[tx][ty] == 0&& book[tx][ty] == 0)
        {
            book[tx][ty]=1;//Ҫ�߸õ��ˣ���Ǹõ��߹�
            lj.X[o]=tx;
            lj.Y[o]=ty;
            //printf("��ʱ�ҵ�o=%d������Ϊ��%d,%d��\n",o,lj.X[o],lj.Y[o]);///////////////////
            o++;
            dfs(tx,ty,step+1);
            book[tx][ty]=0;
            o--;//����
        }
    }
    return;
}
int main()
{
    int i,j;
    //�����Թ�
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
        scanf("%d",&a[i][j]);

    //����㣨0��0����ʼ����
    book[0][0]=1;//�������Ѿ���·����,��ֹ�����ظ���

    //��һ������������x����,�ڶ�������������y����,��������������ʼ����Ϊ0
    dfs(0,0,0);
    //printf("��̲���Ϊ%d\n",min);

    //������·��
    printf("(0, 0)\n");//������λ��
    for(r=0;r<min-1;r++)
        printf("(%d, %d)\n",minval.X[r],minval.Y[r]);
    printf("(4, 4)");
    return 0;
}




/*
#include<stdio.h>
int n,m,p,q,min=99999999;//�Թ���m��n�����
int a[51][51],book[51][51];//��ĿҪ��m,nС��50
struct road
{
    int hen[50];
    int zhong[50];
}lj;
struct road minval;
void dfs(int x,int y,int step)
{
    int next[4][2]= {{0,1}, //������
                     {1,0},//������
                     {0,-1},//������
                     {-1,0}};//������
    int tx,ty,k;

    if(x == p&&y == q)//�����յ�
    {
        //������Сֵ
        if(step<min)
        {
            min=step;
            //����·��
            for(int r=0;r<step;r++)
            {
                minval.hen[r]=lj.hen[r];
                minval.zhong[r]=lj.zhong[r];
            }
        }

        return;//ע������ķ��غ���Ҫ
    }

    //ö��4���߷�
    for(k=0; k<=3; k++)
    {
        //������һ���������
        tx=x+next[k][0];
        ty=y+next[k][1];
        //�ж��Ƿ�Խ��
        if(tx<1||tx>n||ty<1||ty>m)
            continue;
        //�жϸõ��Ƿ�Ϊ�ϰ�������Ѿ���·����
        if(a[tx][ty] == 0&& book[tx][ty] == 0)
        {
            book[tx][ty]=1;
            lj.hen[step]=tx;
            lj.zhong[step]=ty;
            printf("step=%d,,��n�� %d %d\n",step,lj.hen[step],lj.zhong[step]);//���
            dfs(tx,ty,step+1);
            book[tx][ty]=0;
        }
    }
    return;
}
int main()
{
    int i,j,startx,starty;
    //����n��m��nΪ�У�mΪ��
    //�����Թ�
    for(i=0; i<5; i++)
        for(j=0; j<5; j++)
            scanf("%d",&a[i][j]);
    //���������յ�����
    startx=0;starty=0;p=4;q=4;

    //����㿪ʼ����
    book[startx][starty]=1;//�������Ѿ���·����,��ֹ�����ظ���
    //��һ����������������x,�ڶ����������յ������,��������������ʼ����Ϊ0
    dfs(startx,starty,1);
    //�����̲���
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

    int next[4][2]={{0,1},//������
                    {1,0},//������
                    {0,-1},//������
                    {-1,0}};//������

    int head,tail;
    int i,j,k,tx,ty,flag;

    //�����ͼ
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
    {
        scanf("%d",&a[i][j]);
    }

    //���г�ʼ��
    head=0;
    tail=0;
    que[tail].x=0;
    que[tail].y=0;
    que[tail].f=0;
    que[tail].s=0;
    tail++;
    book[0][0]=1;

    flag=0;//��������Ƿ��ѴﵽĿ���

    //�����в�Ϊ��ʱѭ��
    while(head<tail)
    {

        //ö���ĸ�����
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
        head++;//ע������ط�������һ������չ������head++���ܶԺ���ĵ������չ
    }
    //printf("��С����Ϊ%d\n",que[tail-1].s);
    for(i=0;i<que[tail-1].s;i++)
    {
        printf("(%d,%d)\n",que[que[i].f].x,que[que[i].f].y);
    }
    return 0;

}
*/
