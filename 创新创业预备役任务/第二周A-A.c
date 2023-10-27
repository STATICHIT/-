///A与G类似
#include <stdio.h>
#include<string.h>
int main()
{
    int n,a[1001],b[1001],i,k,top;//a数组储存输入数据，b为栈
    while(~scanf("%d",&n)&&n!=0)//注意这里不能写while(scanf("%d",&n)!=0)
    {
        memset(a,0,1001);
        memset(b,0,1001);

        while (~scanf("%d", &a[1]))///因为这里输入了a[1]
        {
            if (a[1] == 0)//对应题中:每行由n个1到n的整数组成
                break;    //直到某一行第一个数是0表示此输入块结束

            for (i=2;i<=n;i++)///所以这里从i=2开始
                scanf("%d",&a[i]);

            k=1;top=1;//top为栈顶
            for(i=1;i<=n;i++)
            {
                b[top]=i;
                while(b[top]==a[k]&&top>0)///这里不太好理解，有时间手算过程
                {
                    top--;
                    k++;
                }
                top++;
            }
            if(k>n) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
