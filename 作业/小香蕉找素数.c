///����ɸ
/*#include<stdio.h>
void main()
{
   int n;
   scanf("%d",&n);
   int isPrime[n+1];//isPrime�ķ�ΧΪn+1
   for(int i=0;i<n+1;i++)
       {
           isPrime[i]=1;
   isPrime[0]=isPrime[1]=0;}//����int isPrime[n+1]={1};��ʼ����������
   for(int i=2;i<=n;i++)    //���Ի���Ҫ��һ��ѭ������ʼ����������
   {
       if(isPrime[i])
       {
           printf("%d\n",i);
           for(int j=2;i*j<=n;j++)//��С��n��2�ı�����ɾ��
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
        int isPrime[n+1];//���������1����������0��
        //isPrime�ķ�ΧΪn+1
        for(int i=0; i<=n; i++)
        {
            isPrime[i]=1;
            isPrime[0]=0;
            isPrime[1]=0;
            //����int isPrime[n+1]={1};��ʼ����������
            //���Ի���Ҫ��һ��ѭ������ʼ����������
        }
        printf("isprime[2]=%d\n",isPrime[2]);
        for(int i=2; i<=n; i++)
        {
            if(isPrime[i])
            {
                printf("%d\n",i);
                for(int j=2; j*i<=n; j++)//��С��n��2�ı�����ɾ��
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
