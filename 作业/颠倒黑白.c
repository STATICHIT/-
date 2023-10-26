#include<stdio.h>
#include<math.h>
unsigned fz(unsigned a)
       {
           int v[10005];
           int  j=1,k=1,A,i;
        do
        {
            A=a%10;
            a=a/10;
            v[j]=A;
            k++;j++;
        }while(a!=0);
                //printf("%d %d\n",v[1],v[2]);//测试位数保存
        A=0;
        for(i=1;i<k;i++)
        {
            A=A+v[i]*pow(10,k-i-1);
        }
        //printf("a颠倒后的A=%u\n",A);//检查翻转情况
        return (A);
        }

int main()
{
    int n,i;
    unsigned a,A,b,B;//A为反转后的a，B同理
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%u %u",&a,&b);
        int sum=a+b;
        int fzs=fz(sum);
        A=fz(a);
        B=fz(b);
        if(A+B!=fzs)
            printf("小叶子颠倒成功\n");
        else if(A+B==fzs)
            printf("%u\n",sum);
    }
    return 0;
}



















/*//洛谷第一题
#include<stdio.h>
#include<string.h>
void main()
{
    char a[101];
    scanf("%s",a);
    int len=strlen(a),i;
    for(i=0; i<len; i++)
    {
      if(a[i]>='a'&&a[i]<='z')
      {
          a[i]-=32;
      }
    }
    printf(a);
}
*/

//对角线求和题目！！！
/*
#include<stdio.h>
void main()
{
    int i,j,N;
    scanf("%d",&N);
    int a[N][N],ans=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
           scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
           if(i==j||j==N-1-i)
           {ans+=a[i][j];}
        }
    }
    printf("%d\n",ans);
}
*/

/*
//将一个数组中的元素值按逆序存放，如原来的顺序
//是1，2，3，4，5，6。要求改为6，5，4，3，2，1。
#include<stdio.h>
void main()
{
    int i,n,t;
    int a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n/2;i++)
    {
        t=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=t;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
*/



/*
//用选择法对10个整数排序。
//这里是选择排序哦！！！
#include<stdio.h>
void main()
{
    int i,j,a[11],t;
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<9;i++)//将第i项与后面的所以项比较
    {
        for(j=i+1;j<10;j++)//挑选最小的与第i项交换位置
            if(a[j]<a[i])
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;

        }
    }
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

}

*/

