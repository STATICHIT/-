//���ʣ�0/1��������
///����ʱ���һ�뵱����������
///ÿ�����ʱ�䵱�����������
#include<stdio.h>
#include<string.h>
int max(int x,int y)
{
    return(x>=y?x:y);
}
int main()
{
    int k,i,j;
    int ans=0;
    int s[5];//���������Ŀ����
    int a[25];//���������Ŀ����ʱ��
    int t[5]= {0}; //����ÿ����Ŀ��ҵ��ʱ��
    int f[5]= {0}; //����ÿ����Ŀ�����Ŵ���ʱ��
    int dp[25][2000];///tip��dp�������Ϊ20*60������Ϊʲô��
    for(k=1; k<=4; k++)
        scanf("%d",&s[k]);
    for(k=1; k<=4; k++)
    {
        memset(dp,0,sizeof(dp));//ÿ����һ�ſ�ĿҪ���³�ʼ��dp��Ŷ
        for(i=1; i<=s[k]; i++)///tip
        {
            scanf("%d",&a[i]);
            t[k]+=a[i];
        }

            //printf("%d\n",t[k]);//���
            for(i=1; i<=s[k]; i++) //����
            {
                for(j=1; j<=t[k]/2; j++) //������
                {
                    if(j<a[i])///tip���������ж��ܷ�װ�µ�ǰ��Ʒ��
                        dp[i][j]=dp[i-1][j];
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+a[i]);
                }
            }

            f[k]=t[k]-dp[s[k]][t[k]/2];//��ǰ��Ŀ�����ʱ��Ϊ��ʱ���ȥdpʱ��
        //printf("����Ŀ����ʱ��Ϊ%d\n",f[k]);
    }
    for(i=1; i<=4; i++)
        ans=ans+f[i];//��ÿһ�Ƶ�����ʱ����Ӽ��õ����
    printf("%d",ans);
    return 0;
}



/*
#include<stdio.h>
int s1,s2,s3,s4,sum;
int a[21],b[21],c[21],d[21];
void sort(int * arr,int n)
{
    int i,j,t;
    for(j=0;j<n-1;j++)
    {
        for(i=0;i<n-1-j;i++)
        {
            if(*(arr+i)<*(arr+i+1))
            {
                t=*(arr+i);
                *(arr+i)=*(arr+i+1);
                *(arr+i+1)=t;
            }
        }
    }
}
//˼·������� ������ �������ÿ�����ʱ��
void time(int * arr,int n)
{
    if(n%2==0)
    {arr[n]=0;
    n=n+1;
    }
        for(int k=0;k<n;k=k+2)
        {
            sum=sum+arr[k];
        }
}
int main()
{
    int i;
    scanf("%d %d %d %d",&s1,&s2,&s3,&s4);

   for(i=0;i<s1;i++)
       scanf("%d",&a[i]);
    sort(a,s1);
    time(a,s1);

    //for(i=0;i<s1;i++)
    //printf("%d ",a[i]);
    //printf("\n");

    for(i=0;i<s2;i++)
       scanf("%d",&b[i]);
    sort(b,s2);
    time(b,s2);

    for(i=0;i<s3;i++)
       scanf("%d",&c[i]);
    sort(c,s3);
    time(c,s3);

    for(i=0;i<s4;i++)
       scanf("%d",&d[i]);
    sort(d,s4);
    time(d,s4);

    printf("%d",sum);
}
*/
