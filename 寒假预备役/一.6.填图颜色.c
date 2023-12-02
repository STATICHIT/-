#include<stdio.h>
int n,a[35][35];
void dfs(int x,int y)
{
    int next[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int tx,ty,i;
    a[x][y]=-1;//��Ȧ��ĵ㶼���Ϊ-1
    for(i=0; i<4; i++)//ÿ���������α���
    {
        tx=x+next[i][0];
        ty=y+next[i][1];

        if(tx > n||tx<1||ty > n||ty<1)//ע�����ж���չ��Ŷ��tx��ty�����ǵ�ǰ�㣨x��y��
            return;

        if(a[tx][ty]==0&&tx<n&&tx>=0&&tx<n&&ty>=0)//������ڵ�ͼ������ǽ��
            //�ؼ��㣺a[tx][ty]==0������д��a[tx][ty]!=1,��Ϊ����ĵ��߹������Ϊ-1Ҳ��Ϊ1.
        {
            //���߹�������λ������ǡ�
            dfs(tx,ty);
            //a[tx][ty]=0;���ﲻ��Ҫ���ݣ�����Ϊ�����ж��ܲ����ߣ������߾Ͳ������
        }
    }
    return;
}
void outplace()
{
    //�ĸ��������α���
    for(int i=0; i<n; i++)
    {
        if(a[0][i]==0)//ԭ�㣨0��0�����ҷ���
        {
            dfs(0,i);
        }
        if(a[i][0]==0)//ԭ�㣨0��0�����·���
        {
            dfs(i,0);
        }
        if(a[n-1][i]==0)//���½ǣ�n-1��0�����ҷ���
        {
            dfs(n-1,i);
        }
        if(a[i][n-1]==0)//���Ͻǣ�0��n-1�����·���
        {
            dfs(i,n-1);
        }
    }
}//������������������ʣ�µľ��Ǳ������

int main()
{

    scanf("%d",&n);
    //�����ͼ
    for(int j=0; j<n; j++)
    {
        for(int k=0; k<n; k++)
        {
            scanf("%d",&a[j][k]);
        }
    }

    outplace();//�������Ȧ���

    //����仯���ͼ
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i][j]==0)//������1����ĵ�Ⱦ��2
            {
                a[i][j]=2;
            }              ///ע��������if˳���ܷ�������-1�����0������һ������2.
            if(a[i][j]==-1)//1����ĵ�ָ���1
            {
                a[i][j]=0;
            }
            //����0Ҳ����-1�ľ���ǽ�����������ֵ'1'����
            printf("%d ",a[i][j]);
        }
        printf("\n");//���ʱ����һ��Ҫ����
    }
    return 0;
}

/*
#include<stdio.h>
int n,a[35][35];
void dfs(int x,int y)
{
    int ax,ay,i;
    int next[4][2]= {{1,0},{0,1},{-1,0},{0,-1}};
    a[x][y]=-1;
    for(i=0; i<4; i++)
    {
        ax=x+next[i][0];
        ay=y+next[i][1];
        if(a[ax][ay] == 0 && ax>=0 && ax<n && ay>=0 && ax<n)
        {
            dfs(ax,ay);
        }
    }
    return;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    //���뷽��
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);

    for(i=0; i<n; i++)
    {
        if(a[i][0] == 0)
            dfs(i,0);
        if(a[0][i] == 0)
            dfs(0,i);
        if(a[n-1][i] == 0)
            dfs(n-1,i);
        if(a[i][n-1] == 0)
            dfs(i,n-1);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(a[i][j] == 0)///�ж�0
                a[i][j]=2;            ///ע��������if˳���ܷ�������-1�����0������һ������2.
            if(a[i][j] == -1)///�ж�-1
                a[i][j]=0;
            printf("%d ",a[i][j]);
        }
            printf("\n");
    }
    return 0;
}
*/
