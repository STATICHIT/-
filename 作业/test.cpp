//学长滴代码
/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        int flag = 0;
        cin>>a;
        cout<<a<<endl;
        if(a == 97 || a ==98 || a == 99){
            cin>>b>>c;
            if(a == 97) flag = 1;
            else if(a == 98) flag = 2;
            else flag = 3;
            cout<<b;
            if(flag == 1){
                cout<<"+";
                c = a+b;
            }else if(flag == 2){
                cout<<"-";
                c = a-b;
            }else {
                cout<<"*";
                c = a*b;
            }
            cout<<b<<"="<<c<<endl;
        }else{
            cin>>b;
            if(flag == 1){
                cout<<"+";
                c = a+b;
            }else if(flag == 2){
                cout<<"-";
                c = a-b;
            }else {
                cout<<"*";
                c = a*b;
            }
        }
    }
}
*/


/*
#include<stdio.h>
int jiecheng(int n)
{
    int ans;
    if(n == 0||n == 1)
    {
        return (1);
    }
    if(n > 1)
    {
        ans=jiecheng(n-1)*n;
        return(ans);
    }
}
int main()
{
    int n,m,ans;
    while(~scanf("%d %d",&n,&m))
    {ans=jiecheng(n)/(jiecheng(n-m)*jiecheng(m));
    printf("%d\n",ans);}
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
    long long int maxhe=a[8]+a[9];
    long long int maxji=(a[0]*a[1]>a[8]*a[9]?a[0]*a[1]: a[8]*a[9]);
              printf("%lld %lld\n",maxhe,maxji);
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


#include<stdio.h>
int maxs(int a[],int sizes)
{
    int i,m=a[0];
    for(i=0;i<sizes;i++)
    {
        if(m<a[i])
            m=a[i];
    }
    return m;
}
#include<string.h>
float yu[500005];
        int yuu[500005],h[500005];
int main()
{
    int n,i;
    while(~scanf("%d",&n))
    {
        memset(h,0,500005);
        for(i=0; i<n; i++)
        {
            scanf("%f",&yu[i]);
            yuu[i]=yu[i]*100;
        }
        //printf("%d \n",maxs(yuu,n));//测试自定义函数运行是否正确
        for(i=0; i<n; i++)
        {
            h[yuu[i]]++;//用h数组记录深度出现次数
            //printf("h[%d]=%d \n",yuu[i],h[yuu[i]]);//这里就有问题
        }
        printf("%d\n",maxs(h,n*100));
    }
    return 0;
}
