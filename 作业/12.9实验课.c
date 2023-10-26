///1 、编写一个函数，由实参传来一个字符串，统计此字符串中字母、数字、空格和其他字符个数， 在主函数中输入字符串以及输出上述的结果。
///此处我用到了结构体
/*
#include<stdio.h>
#include<string.h>
struct tongji
{
    int zimu;
    int shuzi;
    int kogge;
    int qita;
};

struct tongji tj(char arr[],int l)
{
    int i;
    struct tongji o;
    o.zimu=0;
    o.shuzi=0;
    o.kogge=0;
    o.qita=0;
    for(i=0;i<l;i++)
    {
        if(arr[i]>='a'&&arr[i]<='z'||arr[i]>='A'&&arr[i]<='Z')
        {
            o.zimu++;continue;
        }
        else if(arr[i]>='0'&&arr[i]<='9')
        {
            o.shuzi++;continue;
        }
        else if(arr[i] == ' ')
        {
            o.kogge++;continue;
        }
        else
        {
            o.qita++;continue;
        }
    }
    return(o);
}
int main()
{
    char a[1000];
    struct tongji ss;
    gets(a);
    int len=strlen(a);
    ss=tj(a,len);///重要！！！要在主函数中定义一个结构体变量来接收自定义函数返回值！
    printf("字母数：%d\n数字数：%d\n空格数：%d\n其他数：%d\n",ss.zimu,ss.shuzi,ss.kogge,ss.qita);

    return 0;
}
*/

///2、验证哥德巴赫猜想：对2000以内的任意大于2的正偶数都能分解成两个素数之和，输出猜想结果。
/*
#include<stdio.h>
void ss(int n)
{
    int i,j,Prime[2000],a[2000],k=0;
    for(i=0; i<n; i++)
        Prime[i]=1;
    Prime[0]=0;
    Prime[1]=0;
    for(i=2; i<=n; i++)
        if(Prime[i])
        {
            a[k++]=i;
            for(j=2; i*j<=n; j++)
                Prime[i*j]=0;
        }
    for(i=0; i<k; i++)
    {
        for(j=i; j<k; j++)
        {
            if(a[j]+a[i] == n)
            {
                printf("%d  %d\n",a[i],a[j]);
                break;//找到后此时a[i]所对应另一个和数已确认，无需再进行内循环
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    ss(n);
    return 0;
}
*/

///3 、设有n个任意实数存放在数组A[n]，现需要把所有正数放到负数前面，请实现一个函数实现该功能。
#include<stdio.h>
void cz(int arr[],int n)
{
    int i,b[1000],c[1000];
    for(i=0;i<n;i++)
    {
        if(arr[i]>0)
        printf("%d ",arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]<0)
        printf("%d ",arr[i]);
    }

}
int main()
{
    int i,n,a[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    cz(a,n);
    return 0;
}
