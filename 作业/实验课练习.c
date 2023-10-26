/*
//1 、求所有不超过200的N值，N的平方是具有对称性质的回文数。
//回文数就是将一个数从左向右读是一样的，如满足题意要求的数有：N＝11，11平方＝121；
#include<stdio.h>
int huiwen(int n)//自定义回文函数
{
    int i;
    if(n == 0||n == 1||n == 4||n == 9)//个位数时一定是回文数
        return(1);
    else
    {
        char a[10];
        int k=0,sign=1,N;
        while(n!=0)//拆解每一位数
        {
            N=n%10;
            a[k++]=N;
            n=n/10;
        }
        for(i=0; i<k/2; i++)
        {
            if(a[i] != a[k-1-i])
                sign=0;
        }
        if(sign == 1)return(1);
        if(sign == 0)return(0);
    }
}
int main()
{
    int i,n,j;
    for(i=0;i<=200;i++)
    {
        n=i*i;
        if(huiwen(n) == 1)
            printf("%d ",i);
    }
    return 0;
}

*/

/*
#include<stdio.h>
int Prime(int n)
{
    int isPrime[1001],i,j;
    for(i=0; i<1001; i++)
        isPrime[i]=1;
    isPrime[0]=0;
    isPrime[1]=0;
    //for(i=0;i<1001;i++)//检查isPrime数组赋值情况
    //printf("%d ",isPrime[i]);
    for(i=0; i<1001; i++) ///埃氏筛
        if(isPrime[i] == 1)
        {
            for(j=2; j*i<1001; j++)
                isPrime[j*i]=0;
        }
    if(isPrime[n] == 1)
        return 1;
    else if(isPrime[n] == 0)
        return 0;

}
int main()
{
    int i;
    for(i=0; i<1001; i++)
    {
        if(Prime(i) == 1)
            printf("%d ",i);
    }
    return 0;
}
*/

/*
#include<stdio.h>
int jiecheng(int n)
{
    int ans;
    if(n == 1||n == 0)
        return 1;
    else
        ans=jiecheng(n-1)*n;
    return ans;
}
int main()
{
    int m,n,ans=0;
    scanf("%d %d",&m,&n);
    ans=jiecheng(m)/(jiecheng(n)*jiecheng(m-n));
    printf("%d\n",ans);
    return 0;
}
*/

/*
#include<stdio.h>
#include<math.h>
void x()
{
    int i,j;
    for(i=0;i<=45;i++)
        for(j=0;j<45;j++)
            if(i*i+j*j == 1989)
                printf("%d %d\n",i,j);
}
int main()
{
    x();
return 0;
}
​*/

/*
#include<stdio.h>
#include<math.h>
int fz(int x,int y)
{
    int i,j=0;
    int t=x>y?y:x;
    for(i=2;i<=t;i++)
        {
            if(x%i == 0&&y%i == 0)
                {j=1;break;}
        }
    return j;
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    if(fz(m,n) == 0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

*/
/*
#include<stdio.h>
#include<string.h>
int ji(char a[])
{
    int i,k=0;
    char b[30];
    for(i=0;i<strlen(a);i++)
    {
        if((a[i]-'0')%2 != 0)
            b[k++]=a[i];
    }
    printf(b);

}
int main()
{
    char a[30];
    scanf("%s",a);
    ji(a);

    return 0;
}
*/

/*
#include<stdio.h>
int fun(int n)
{
    int i,sum=0;
    for(i=2;i<n;i++)
        if(n%i == 0)
        sum+=i;
    return(sum);
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",fun(n));
    return 0;
}
*/
