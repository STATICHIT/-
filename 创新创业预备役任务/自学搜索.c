/*
//dfs
#include<stdio.h>
int a[10],book[10],n;//此处特别说明一下：C语言的全局变量在没有赋值以前默认为0，因此这里的
//book数组无需全部再次赋初始值为0（因为自定义函数中要用到a和book数组所以定义全局变量）
void dfs(int step)//step表示现在站在第几个盒子面前
{
    int i;
        if(step == n+1)//如果站在第n+1个盒子面前，则表示前n个盒子已经放好
        {
            //输出一种排列（前1到n号盒子中的排列顺序）
            for(i=1;i<=n;i++)
            {
                printf("%d",a[i]);
            }
            printf("\n");

        return;//返回之前的一步（最近一次调用dfs函数的地方）
        }
    //此时站在第step个盒子面前，应该放哪张牌呢？
    //按照1，2，3...n的顺序一一尝试
    for(i=1; i<=n; i++)
    {
        //判断扑克牌是否还在手上
        if(book[i] == 0)//book[i]等于0表示i号扑克牌在手上
        {
            //开始尝试使用扑克牌i
            a[step]=i;//将i放入第step个盒子里
            book[i]=1;//将book[i]设为1表示扑克牌i已不在手上

            //第step个盒子已经放好扑克牌，接下来需要走到下一个盒子面前
            dfs(step+1);//递归
            book[i]=0;//将刚才尝试的扑克牌收回手中，才能进行下一次尝试
        }
    }
    return;///返回上一次递归调用
}
int main()
{
    //别忘了题目是要求1到n的全排列哦
    scanf("%d",&n);//输入的时候要注意n为1到9之间的整数
    dfs(1);//首先站在1号小盒子前面
    return 0;
}
*/
/*
#include<stdio.h>
int n,a[10],book[10];
void dfs(int step)
{
    if(step == n+1)
    {
        for(int i=1;i<=n;i++)
            printf("%d",a[i]);
        printf("\n");

        return;//注意位置
    }
    for(int i=1;i<=n;i++)
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
    scanf("%d",&n);
    dfs(1);
    return 0;
}
*/
#include<stdio.h>
int n,book[10],a[10];
void dfs(int step)
{
    if(step == n+1)
    {
        for(int i=1;i<=n;i++)
            printf("%d",a[i]);
        printf("\n");

        return;
    }

    for(int i=1;i<=n;i++)
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
    scanf("%d",&n);
    dfs(1);
    return 0;
}
