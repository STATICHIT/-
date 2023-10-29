/*
//C
#include<bits/stdc++.h>
using namespace std;

void fun(char ch)
{
    switch(ch)
    {
    case'0':
            cout<<"零";
        break;
    case'1':
            cout<<"一";
        break;
    case'2':
            cout<<"二";
        break;
    case'3':
            cout<<"三";
        break;
    case'4':
            cout<<"四";
        break;
    case'5':
            cout<<"五";
        break;
    case'6':
            cout<<"六";
        break;
    case'7':
            cout<<"七";
        break;
    case'8':
            cout<<"八";
        break;
    case'9':
            cout<<"九";
        break;
    }
}
int main()
{
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        fun(str[i]);
    }

    return 0;
}
*/
/*
//D
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    double a1,a2;
    if(n>=2)cout<<"L";
    else
        cout<<"A";
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;

long long C(int n, int m)
{
    long long ans=1;
    for(int i=1; i<=m; i++)
        ans = ans * (n - i + 1) / i;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    if(n==1||n==2)
        cout<<n;
    else if(n==3)cout<<"4";
    else if(n==4)cout<<"8";
    else
    {
        long long ans;
        ans=C(n,4)+C(n,2)+1;
        cout<<ans;
    }
    return 0;
}
*/

/*
//K
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
} no[100005];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
int main()
{
    int n;
    std::cin>>n;
    int xx,yy=-100001;
    for(int i=0; i<n; i++)
    {
        std::cin>>no[i].x>>no[i].y;
        if(no[i].y<0)
            no[i].y*=-1;
        if(yy<=no[i].y)
        {
            xx=no[i].x,yy=no[i].y;
        }
    }
    sort(no,no+n,cmp);
    //cout<<xx<<  "  "<<yy<<endl;
    long long sum=-1,minn=1000000000;
    int x;
    for(int i=no[0].x; i<=no[n-1].x; i++)
    {
        for(int j=0; j<n; j++)
        {
            sum+=no[j].x-i+no[j].y;
        }
        if(sum<=minn)
        {
            x=i;
        }
    }
    //cout<<x<<endl;
    cout<<(xx-x)*(xx-x)+(yy*yy);
    return 0;
}
*/

/*
//K
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
} no[100005];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
int main()
{
    int n;
    cin>>n;
    int xx,yy=-100001;
    for(int i=0; i<n; i++)
    {
        cin>>no[i].x>>no[i].y;
        if(no[i].y<0)
            no[i].y*=-1;
        if(yy<=no[i].y)
        {
            xx=no[i].x,yy=no[i].y;
        }
    }
    sort(no,no+n,cmp);
    //cout<<xx<<  "  "<<yy<<endl;
    long long sum=-1,minn=1000000000;
    int x;
    for(int i=no[0].x; i<=no[n-1].x; i++)
    {
        for(int j=0; j<n; j++)
        {
            sum+=(no[j].x-i)*(no[j].x-i)+(no[j].y)*(no[j].y);
        }
        if(sum<=minn)
        {
            x=i;
        }
    }
    //cout<<x<<endl;
    cout<<(xx-x)*(xx-x)+(yy*yy);
    return 0;
}
*/
/*
//N
#include<bits/stdc++.h>
using namespace std;
int num[200001];
int book[200001];
int mp[200001];
int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        cin>>num[i];
        if(book[num[i]]==0)
        {
            mp[ans]=num[i];
            ans++;
            for(int j=1; j*num[i]<=200000; j++)
            {
                book[j*num[i]]=1;
            }
        }
    }
    cout<<ans<<endl;
    for(int i=0; i<ans; i++)
    {
        cout<<mp[i]<<" ";
    }
}
*/
/*
//N
#include<bits/stdc++.h>
using namespace std;

int n,a[200005],book[200005];
int main()
{
    cin>>n;
    int max_=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        max_=max(max_,a[i]);
    }
    //sort(a,a+n);
    //cout<<max_<<endl;//测试
    int flag=-1;
    for(int i=0; i<n; i++)
    {
        if(a[i]==1)//如果出现了1，后面的数都是1的倍数
        {
            flag=i;
            break;
        }
        //if(book[i]==1)
        //   continue;
        //else
        for(int j=2; j*a[i]<=max_; j++)
        {
            book[j*a[i]]=1;
        }
    }
    if(flag==-1)
    {
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            if(book[a[i]]==0)
                cnt++;
        }
        cout<<cnt<<endl;
        for(int i=0; i<n; i++)
        {
            if(book[a[i]]==0)
                cout<<a[i]<<" ";
        }
    }
    else
    {
        int cnt=0;
        for(int i=0; i<=flag; i++)
        {
            if(book[a[i]]==0)
                cnt++;
        }
        cout<<cnt<<endl;
        for(int i=0; i<=flag; i++)
        {
            if(book[a[i]]==0)
                cout<<a[i]<<" ";
        }
    }

    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int m;
        cin>>m;
        int h=2*m-1;

        for(int i=0; i<m; i++)
        {
            if(i==0)
            {
                cout<<" ";
                for(int j=0; j<h-2; j++)
                    cout<<"*";
            }
            else
            {
                int k=m-i;
                while(k--)
                    cout<<"*";
                int g=2*i-1;
                while(g--)
                    cout<<" ";
                k=m-i;
                while(k--)
                    cout<<"*";
            }
            cout<<endl;
        }

        for(int i=m; i<h; i++)
        {
            if(i==h-1)
            {
                cout<<" ";
                for(int j=0; j<h-2; j++)
                    cout<<"*";
            }
            else
            {
                int k=i-m+2;
                while(k--)
                    cout<<"*";
                int g=h-(i-m+2)*2;
                while(g--)
                    cout<<" ";
                k=i-m+2;
                while(k--)
                    cout<<"*";
            }
            cout<<endl;
        }
    }
    return 0;
}
*/
/*
//H
#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long int x;//攻击力
    long long int m;//牌数
}no[10005];
int n;
bool cmp(node a,node b)
{
    return a.x>b.x;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>no[i].x>>no[i].m;
    }
    sort(no,no+n,cmp);
    long long int dj=0;//叠加数
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<no[i].m;j++)
        {
            sum+=no[i].x+dj;
            dj+=no[i].x;
        }
    }
    cout<<sum;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    return 0;
}
*/
/*
//M
#include<bits/stdc++.h>
using namespace std;
string str;

bool huiwen(int y,int m,int d)
{
    string s1,s2,s3;
    int k=-1;
    while(y!=0)
    {
       int r=y%10;
        s1[++k]=r+'0';
        y=y/10;
    }
    int nn=k;
    for(int i=0;i<=k;i++)
    {
        str[i]=s1[k-i];
    }
    while(m!=0)
    {
       int r=m%10;
        s2[++k]=r+'0';
        m=m/10;
    }
    for(int i=nn+1;i<=k;i++)
    {
        str[i]=s1[k-i];
    }
    nn=k;
    while(d!=0)
    {
       int r=d%10;
        s3[++k]=r+'0';
        d=d/10;
    }
    for(int i=nn+1;i<=k;i++)
    {
        str[i]=s1[k-i];
    }

    for(int i=0;i<(k+1)/2;i++)
    {
        if(str[i]!=str[k-i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int month,day,y,m,d;
    cin>>month>>day;
    cin>>y>>m>>d;
for(int i=y;i<200000;i++)
{
    for(int j=m;j<=month;j++)
    {
        for(int k=d;k<=day;k++)
        {
            if(huiwen(y,m,d))
                cout<<i<<" "<<j<<" "<<k;
        }
    }
}

    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[10]={1,2,3,4,5,6,7,8};
    for(int arr:a)//增强for循环
    {
        cout<<arr<<endl;
    }
    return 0;
}
//增强for循环的格式：
//for(数据类型 变量名 :遍历的目标)
//{
//数据类型 变量名:声明一个变量用来
//接收遍历目标遍历后的元素
//}
