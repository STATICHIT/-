#include<stdio.h>
int n,l,a[10];//n<=8
void dfs(int sum,int data)//sum表示当前总和，data表示本次调用函数sum需从data加起
{
    int i;
    if(sum == n)
    {
       for(i=0;i<l-1;i++)
        printf("%d+",a[i]);
       printf("%d\n",a[i]);//最后一个数后面没有加号
       return;//已经得到一组答案，回溯到上一步
    }
    if(sum > n)
        return;//超过了，不合适，回到上一步
    if(sum < n)
    {
        for(i=data; i<n; i++)//加的数从1开始遍历
        {
            a[l++]=i;
            dfs(sum+i,i);
            a[--l]=0;//回溯
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    dfs(0,1);//sum起初是0，从加1开始
    return 0;
}
