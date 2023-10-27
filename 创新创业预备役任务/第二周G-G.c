///A与G类似
#include <stdio.h>
#include<string.h>
int fun(int a[],int n)
{
    int b[101],i,k,top,max;
    k=1;
    top=1,max=0;//top为栈顶
    for(i=1; i<=n; i++)
    {
        b[top]=i;
        while(b[top]==a[k]&&top>0)///这里不太好理解，有时间手算过程
        {
            top--;
            k++;
        }
        top++;
        if(top>max)
            max=top;
    }
    if(k>n) return max;
    else return -1;
}
int main()
{
    int n,i,a[101];
    while(scanf("%d",&n))
    {
        for(i=1; i<=n; i++)
            scanf("%d",&a[i]);
        printf("%d\n",fun(a,n));
    }
    return 0;
}
///好不容易答案正确了又时间超限了我要哭了！！！！
