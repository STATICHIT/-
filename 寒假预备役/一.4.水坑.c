///��ͨ������
#include<stdio.h>
char a[101][101];//���ڱ����ͼ
int ans,n,m;
void dfs(int x,int y)
{
    //��������б�Ϸ�б�·���Ҫ���ǣ�
    int next[9][2]={{0,0},{1,1},{-1,-1},{-1,1},{1,-1},{0,1},{1,0},{-1,0},{0,-1}};
    a[x][y]='.';//�߹��ĵط����Ϊ��.��
    int dx,dy;
    for(int i=0; i<=8; i++)//������Χ
    {
            dx=x+next[i][0];
            dy=y+next[i][1];
            if(dx>=0&&dx<=n&&dy>=0&&dy<m&&a[dx][dy]=='W')
            {
                dfs(dx,dy);
            }
    }
    return;
}
int main()
{
    //�����ͼ
    scanf("%d%d",&n,&m);
    for(int i=0; i<=n; i++)
    {
        scanf("%s",a[i]);//һ������һ��
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j]=='W') //����W��ʼ����
            {
                dfs(i,j);
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
