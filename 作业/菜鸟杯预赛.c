/*
//G出师门，入尘世！
#include<stdio.h>
int main()
{
    int t,i,j,n,k;
    scanf("%d",&n);
    for(k=0; k<n; k++)
    {
        scanf("%d",&t);
        if(t<=2)
        {
            printf("师傅，你使诈！\n");
            continue;
        }
        int a[t][2];
        a[0][0]=1;
        for(i=1; i<t; i++)
        {
            a[i][0]=a[i-1][0]+2;
        }
        a[0][1]=2;
        for(i=1; i<t; i++)
        {
            a[i][1]=a[i-1][1]+2;
        }
        a[0][0]=a[0][1]=0;
        a[t-1][0]=a[t-1][1]=0;
        for(i=0; i<t; i++)
        {
            for(j=0; j<2; j++)
            {
                if(a[i][j]!=0)
                    printf("%d ",a[i][j]);
            }
        }
        printf("\n");

    }

    return 0;
}
*/
/*
//L:广撒网，多捕鱼
#include<stdio.h>
int main()
{
    int t,i,j,k,n,m,g;
    scanf("%d",&t);
    for(k=0; k<t; k++)
    {
        int sum[100000]= {0},g=0;
        scanf("%d %d",&n,&m);
        int a[n][m];
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(i<=n-3&&j<=m-3)
                {
                    sum[g++]=a[i][j]+a[i+1][j]+a[i+2][j]+a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]+a[i][j+2]+a[i+1][j+2]+a[i+2][j+2];
                }
            }
        }
        //for(i=0;i<g-1;g++){
        //printf("%d ",sum[i]);}
        int min=sum[0];
        for(i=0; i<g; i++)
        {
            if(min>sum[i])
                min=sum[i];
        }
        printf("%d\n",min);
    }
    return 0;
}
*/
/*
//J：中华上下五千年
#include<stdio.h>//天干以10为周期，地支以12为周期，天干地支以60为周期
int main()//我国从1949年开始使用公元纪年法，所以1949年以后的年份一定是没有问题的
{
    int t,s,n,signa,signb;
    scanf("%d",&t);
    for(s=0;s<t;s++)
    {
        scanf("%d",&n);
        signa=(n+6000-4)%10;
        signb=(n+6000-4)%12;
        switch(signa)
        {
            case (0):printf("jia");break;
            case (1):printf("yi");break;
            case (2):printf("bing");break;
            case (3):printf("ding");break;
            case (4):printf("wu");break;
            case (5):printf("ji");break;
            case (6):printf("geng");break;
            case (7):printf("xin");break;
            case (8):printf("ren");break;
            case (9):printf("gui");break;
        }
        switch(signb)
        {
            case (0):printf("zi");break;
            case (1):printf("chou");break;
            case (2):printf("yin");break;
            case (3):printf("mao");break;
            case (4):printf("chen");break;
            case (5):printf("si");break;
            case (6):printf("wu");break;
            case (7):printf("wei");break;
            case (8):printf("shen");break;
            case (9):printf("you");break;
            case (10):printf("xu");break;
            case (11):printf("hai");break;
        }
        printf("\n");
    }
    return 0;
}
*/

/*
//Y：有强迫症的会长
#include<stdio.h>
int main()
{
    int t,s,n,i,j,g,a[1005];
    scanf("%d",&t);
    for(s=0; s<t; s++)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(j=0; j<n-1; j++)
        {
            for(i=0; i<n-1-j; i++)
            {
                if(a[i]>a[i+1])
                {
                    g=a[i];
                    a[i]=a[i+1];
                    a[i+1]=g;
                }
            }
        }
            if(n%2 == 0)
            {
                for(i=0; i<n/2; i++)
                {
                    printf("%d %d ",a[i],a[n-i-1]);
                }
            }
            else
            {
                for(i=0; i<n/2; i++)
                {
                    printf("%d %d ",a[i],a[n-i-1]);
                }
                printf("%d",a[n/2]);
            }
            printf("\n");
    }
    return 0;
}
*/

/*
#include<stdio.h>
int main()
{
    long long n,m,i;
    while(~scanf("%lld %lld",&n,&m))
    {
        long long a[2*m],temp=0,k=1;
        for(i=0; i<2*m; i++)
        {
            temp++;
            if(temp<=m)
            {
                a[i]=k++*-1;}

            else if(temp>m&&temp<=2*m)
                {
                    a[i]=k++;
                    if(temp == 2*m)
                    {temp=0;}
                }
        }
        long long s=0,sum=0;
        for(i=0;i<2*m;i++)
        {
            s+=a[i];
        }
        sum=n*s/(2*m);
        printf("%lld\n",sum);
    }
     return 0;
}

*/

/*
#include<stdio.h>
int main()
{
    int n,i,j;
    while(~scanf("%d",&n))
    {
        int k=0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<4*n+1; j++)
            {
                if(j<2*(n-1-i))
                {
                    printf(" ");
                }
                else if(j >= 2*(n-1-i)&&j<2*n+2*i-1)
                {
                    printf("%d ",k++);
                    if(k == 10)
                    {
                        k=0;
                    }
                    j++;
                }
                else if(j>=2*n+2*i-1&&j<4*n+1)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
*/

/*
#include<stdio.h>
int main()
{
    char a;
    scanf("%c",&a);

        switch(a)
        {
        case('A'):
            printf("2\n2 1\n");
            break;
        case('B'):
            printf("2\n3 5\n");
            break;
        case('C'):
            printf("2\n3 3\n");
            break;
        case('D'):
            printf("3\n2 3\n");
            break;
        case('E'):
            printf("3\n1 3\n");
            break;
        case('F'):
            printf("3\n2 4\n");
            break;
        case('G'):
            printf("4\n2 5\n");
            break;
        case('H'):
            printf("4\n2 6\n");
            break;
        case('I'):
            printf("4\n1 8\n");
            break;
        case('J'):
            printf("5\n2 7\n");
            break;
        case('K'):
            printf("5\n2 8\n");
            break;
        case('L'):
            printf("5\n2 9\n");
            break;
        case('M'):
            printf("6\n3 7\n");
            break;
        case('N'):
            printf("6\n3 6\n");
            break;
        case('O'):
            printf("6\n1 9\n");
            break;
        case('P'):
            printf("7\n1 10\n");
            break;
        case('Q'):
            printf("7\n1 1\n");
            break;
        case('R'):
            printf("7\n1 4\n");
            break;
        case('S'):
            printf("7\n2 2\n");
            break;
        case('T'):
            printf("8\n1 5\n");
            break;
        case('U'):
            printf("8\n1 7\n");
            break;
        case('V'):
            printf("8\n3 4\n");
            break;
        case('W'):
            printf("9\n1 2\n");
            break;
        case('X'):
            printf("9\n3 2\n");
            break;
        case('Y'):
            printf("9\n1 6\n");
            break;
        case('Z'):
            printf("9\n3 1\n");
            break;
        }

    return 0;
}
*/

/*
#include<stdio.h>
int main()
{
    long long int a[11],i,j,t;
    while(~scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9]))
     {
    for(j=0; j<9; j++)
    {
        for(i=0; i<9-j; i++)
        {
            if(a[i]>a[i+1])
            {
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
        }
    }
    //for(i=0;i<10;i++)//检查a数组排序情况
    //{
    //    printf("%lld ",a[i]);
    //}
    long long int maxhe=a[8]+a[9];
    long long int maxji=(a[0]*a[1]>a[8]*a[9]?a[0]*a[1]: a[8]*a[9]);
              printf("%lld %lld\n",maxhe,maxji);
     }
    return 0;
}
*/


//老师的鱼叉
#include<stdio.h>
#include<string.h>
float yu[500001];//数组不能开的太大了哦！！太大了也会运行错误
int h[500001];//这道题我一直卡在把所以数组定义成了999999999！并不是怕小不怕超哦！！
int main()
{
    int n,i,temp;
    while(~scanf("%d",&n))
    {
        memset(h,0,500001);
        for(i=0; i<n; i++)
        {
            scanf("%f",&yu[i]);
            if(yu[i]>=0)//大于0的乘100为了消除小数
                {yu[i]=yu[i]*100;
                temp=yu[i];h[temp]++;}//没得到一个数，把它乘100赋给temp然后立刻丢进桶排数组里这个temp就没用啦

            else if(yu[i]<0)//小于0的乘100再加个20000与正数区分开来
                {yu[i]=yu[i]*100+20000;
                temp=yu[i];h[temp]++;}
        }
        int m=0;
        for(i=0; i<500001; i++)
      {
        if(m<h[i])
            m=h[i];
      }
         printf("%d\n",m);
    }
    return 0;
}



/*
#include<stdio.h>
int main()
{
    int i;
    char a[3][4]={"AAAA","BBBB","CCCC"};//字符二维数组的每一行末尾是'\0'哦！
    for(i=0;i<3;i++)
    {
        printf("%s",a[i]);
        printf("\n");
    }
    return 0;
}
*/

