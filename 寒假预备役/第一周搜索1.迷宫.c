#include<stdio.h>
int n,m,t,sum=0;//NΪ�У�MΪ�У�TΪ�ϰ�����
int sx,sy,fx,fy,cx,cy;//�������SX,SY���յ�����FX,FY, �ϰ�����CX��CY
int a[6][6],book[6][6];
void dfs(int x,int y)
{
    int next[4][2]={{0,1},//����
                    {1,0},//����
                    {0,-1},//����
                    {-1,0}};//����

    if(x == fx&&y == fy)//�����յ�
    {
        sum++;
        return;
    }

    int tx,ty,k;
    //ö�������߷�
    for(k=0;k<4;k++)
    {
        tx=x+next[k][0];
        ty=y+next[k][1];

        if(tx<1||ty<1||tx>n||ty>m)
            continue;
        if(a[tx][ty] == 0&&book[tx][ty] == 0)
        {
            book[tx][ty]=1;
            dfs(tx,ty);
            book[tx][ty]=0;
        }
    }
    return ;
}
int main()
{
    scanf("%d %d %d",&n,&m,&t);
    scanf("%d %d %d %d",&sx,&sy,&fx,&fy);
    int k=0;
    while(t--)
    {
        scanf("%d %d",&cx,&cy);
        a[cx][cy]=1;//����ϰ���
    }
    book[sx][sy]=1;//�������Ѿ���·����
    dfs(sx,sy);
    printf("%d",sum);
    return 0;
}
