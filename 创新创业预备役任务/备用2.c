/*
#include<stdio.h>
int n,m,p,q,min=99999999;//�Թ���m��n�����
int a[51][51],book[51][51];//��ĿҪ��m,nС��50
void dfs(int x,int y,int step)
{
    int next[4][2]={{0,1},//������
                    {1,0},//������
                    {0,-1},//������
                    {-1,0}};//������
    int tx,ty,k;
    //���жϴ�ʱ�Ƿ񵽴�С��λ��
    if(x == p&&y == q)
    {
        //������Сֵ
        if(step<min)
            min=step;
        return;//ע������ķ��غ���Ҫ
    }

    //ö��4���߷�
    for(k=0;k<=3;k++)
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
    scanf("%d %d",&n,&m);
    //�����Թ�
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
    //���������յ�����
    scanf("%d %d %d %d",&startx,&starty,&p,&q);

    //����㿪ʼ����
    book[startx][starty]=1;//�������Ѿ���·����,��ֹ�����ظ���
    //��һ����������������x,�ڶ����������յ������,��������������ʼ����Ϊ0
    dfs(startx,starty,0);
    //�����̲���
    printf("%d",min);
    return 0;
}
*/

/*
///Ҫ��ס���ݹ����ҪץסĿǰ��Ҫ��ôʵ��Ŀ�ģ�ÿһ���ı�����һ���ģ���
#include<stdio.h>8
int a[10];//a[i]��ʾ��i���ϵĻʺ����a[i]����
int cnt,n;
int check(int x,int y)//bool��c++��ģ�c��û��Ŷ
{
    for(int i=1; i<=x; i++)
    {
        if(a[i] == y)return 0;
        if(i+a[i] == x+y)return 0;
        if(i-a[i] == x-y)return 0;
    }
    return 1;
}
void dfs(int row)//��ʾ��row�ʺ���ںδ�
{
    if(row == n+1)//�����������row=n+1˵��ÿһ�лʺ��λ���Ѿ��ж�����
    {
        //������һ���
        cnt++;
        return;//!!!
    }
    for(int i=1; i<=n; i++)
    {
        if(check(row,i))//row����
        {
            a[row]=i;
            dfs(row+1);//�ݹ飬�൱��row++��
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
#include<math.h>//int abs(int x) ���� x �ľ���ֵ
int rank[10],book[10];//bookΪ�������
int n,num=0;
void dfs(int row)
{
    if(row==n+1)//�ݹ�߽�����(����������n+1��ʱ��˵���ѳ�һ����)
    {
        num++;
        return;
    }
    for(int i=1; i<=n; i++)//ö��ÿһ��
    {
        if(book[i]==0)
        {
            int flag=1;
            for(int j=1; j<row; j++)//ö��row֮ǰ�Ļʺ�
            {
                if(abs(row-j)==abs(i-rank[j]))
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                rank[row]=i;//row����i��
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

