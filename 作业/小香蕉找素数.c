///埃氏筛
/*#include<stdio.h>
void main()
{
   int n;
   scanf("%d",&n);
   int isPrime[n+1];//isPrime的范围为n+1
   for(int i=0;i<n+1;i++)
       {
           isPrime[i]=1;
   isPrime[0]=isPrime[1]=0;}//不能int isPrime[n+1]={1};初始化所以数，
   for(int i=2;i<=n;i++)    //所以还是要用一个循环来初始化数组内容
   {
       if(isPrime[i])
       {
           printf("%d\n",i);
           for(int j=2;i*j<=n;j++)//把小于n的2的倍数都删掉
                isPrime[i*j]=0;
       }
   }
}
*/



#include<stdio.h>
void main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int isPrime[n+1];//标记素数（1），合数（0）
        //isPrime的范围为n+1
        for(int i=0; i<=n; i++)
        {
            isPrime[i]=1;
            isPrime[0]=0;
            isPrime[1]=0;
            //不能int isPrime[n+1]={1};初始化所有数，
            //所以还是要用一个循环来初始化数组内容
        }
        printf("isprime[2]=%d\n",isPrime[2]);
        for(int i=2; i<=n; i++)
        {
            if(isPrime[i])
            {
                printf("%d\n",i);
                for(int j=2; j*i<=n; j++)//把小于n的2的倍数都删掉
                    isPrime[j*i]=0;
            }
        }
    }
}

/*
#include<stdio.h>
void main()
{
    int N,z,j;
    while(~scanf("%d",&N))
    {
         int a[N+1];
    for(j=0;j<N+1;j++)
    {
        a[j]=1;
    }
        a[0]=0;
        a[1]=0;
        for(int i=2;i<=N;i++)
        {
            if(a[i]==1)
            {
                printf("%d\n",i);
                for(z=2;z*i<=N;z++)
                    a[i*z]=0;
            }
        }
    }
}
*/
