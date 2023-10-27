//思路要清晰，这里用到了两个结构体，且嵌套使用
#include<stdio.h>
#include<string.h>
struct normal
{
    int shi;
    int fen;
    int miao;
};
struct val
{
    char name[20];
    int t[20];
    struct normal T[20];
};

int main()
{
    int i,j,n;
    struct val time;
    scanf("%d",&n);
    int sign[20]={0};
    scanf("%s",time.name);
    for(i=0;i<n;i++)
        scanf("%d",&time.t[i]);
    for(i=0;i<n;i++)
    {
        if(time.t[i] == 0)
            sign[i]=1;//标记没做出来的题目
        else
        {
            time.T[i].shi=time.t[i]/3600;
            time.T[i].fen=(time.t[i]%3600)/60;
            time.T[i].miao=(time.t[i]%3600)%60;
        }
    }
    printf("%s ",time.name);
    for(i=0;i<n;i++)
    {
        if(sign[i] == 1)
            printf("0 ");
        else
        {
            printf("%02d:%02d:%02d ",time.T[i].shi,time.T[i].fen,time.T[i].miao);
        }
    }
    return 0;
}
