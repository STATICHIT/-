/*猜价格。
程序中设定一个商品的价格（1-1000之间的整数），
让用户输入他猜测的价格，系统提示猜高了还是猜
低了，或者猜对了退出猜测。如果10次内猜对价格，
显示“success”，否则显示“fail”。*/
#include<stdio.h>
void main()
{
    int s=688;
    int price,time=0;
    while(~scanf("%d",&price)!=s)
    {
        time++;
        if(price>s)
        {
            printf("高了\n");

        }
        if(price<s)
        {
            printf("低了\n");
        }
        if(price==s)
    {
        printf("success\n");
        break;
    }
        if(time>10)
        {
            break;
        }
    }
    if(time>10)
    {
        printf("fail\n");
    }
}

/*
//学长的方法
#include<stdio.h>
int main()
{
    int s=688;
    int price,time=0;
    for(int i = 0 ;i < 10;i++)
    {
        scanf("%d",&price);
        if(price>s)
        {
            printf("高了\n");

        }
        if(price<s)
        {
            printf("低了\n");
        }
        if(price==s)
        {
            printf("success");
            return 0;
        }
    }
        printf("fail\n");
    return 0;
}
*/
