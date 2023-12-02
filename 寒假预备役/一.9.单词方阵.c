#include<stdio.h>
int n,sum;
char mb[8]= {"yizhong"};
char mp[101][101];
char sign[101][101];
int next[8][2]= {{1,0},{0,1},{-1,0},{0,-1},
    {1,1},{1,-1},{-1,1},{1,-1}
};
void check(int x,int y)
{
    for(int i=0; i<8; i++)
    {
        sum=0;
        int ax=x+next[i][0];
        int ay=y+next[i][1];
        int tx=ax,ty=ay;
        for(int j=1; j<7; j++)
        {
            if(mp[tx][ty] == mb[j])
            {
                sum++;
            }
            else
            {
                break;
            }
            tx=tx+next[i][0];
            ty=ty+next[i][1];
            if(sum == 6)
            {
                //刚才那些全部sign【】【】=$
                sign[x][y]='$';
                int tx=ax,ty=ay;
                for(int j=1; j<7; j++)
                {
                    if(mp[tx][ty] == mb[j])
                    {
                        sign[tx][ty]='$';
                    }
                    tx=tx+next[i][0];
                    ty=ty+next[i][1];
                }
            }
        }

    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%s",&mp[i]);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(mp[i][j] == 'y')
                check(i,j);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(sign[i][j] == '$')
                printf("%c",mp[i][j]);
            else
                printf("*");
        }
        if(i!=n-1)
        printf("\n");
    }
    return 0;
}
