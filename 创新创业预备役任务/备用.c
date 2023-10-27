///利用dfs算法解决问题：手中有编号为1到9的九张扑克牌，然后将这九张扑克牌放到九个盒子中
///使得【】【】【】 + 【】【】【】 = 【】【】【】成立
#include<stdio.h>
int a[10],book[10],total=0;
void dfs(int step)
{
    int i;
    if(step == 10)
    {
        if(a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6] == a[7]*100+a[8]*10+a[9])
        {
            total++;
            printf("%d%d%d+%d%d%d=%d%d%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
        }
        return;
    }
    for(i=1;i<=9;i++)
    {
        if(book[i] == 0)
        {
            a[step]=i;
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
    return;
}
int main()
{
    dfs(1);
    printf("total=%d\n",total/2);
    return 0;
}
