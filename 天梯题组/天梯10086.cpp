/*
//26进制
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int L,N,a,b;
    cin>>L>>N;
    N=pow(26,L)-N;
    for(int i=1; i<=L; i++)
    {
        a=pow(26,L-i);
        b=N/a;
        printf("%c",b + 'a');
        N%=a;
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int f[1009], user[1009], hobby[1009];

int findd(int x)
{
    if(f[x] == x)
        return x;
    else
        return f[x] = findd(f[x]);
}

void hebing(int x, int y)
{
    int xx = findd(x), yy = findd(y);
    if(xx != yy)
    {
        f[yy] = xx;
    }
}
bool cmp(int x, int y)//逆序规则
{
    return x > y;
}
int main()
{
    for(int i=1; i<=1000; i++)
    {
        f[i] = i;
    }
    int n,k,h,num=0;
    char ch;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> k;
        cin >> ch;//冒号
        cin >> user[i]; //user[i]：用第一个兴趣来代表每一个人
        for(int j=1; j<=k-1; j++)
        {
            cin >> h;
            hebing(user[i], h);
        }
    }
    for(int i=1; i<=n; i++)
        hobby[findd(user[i])]++;  //计算每个圈子多少人
    for(int i=1; i<=1000; i++)
        if(hobby[i]!=0) num++;  //统计圈子个数
    sort(hobby, hobby+1001, cmp);//逆序
    cout << num << endl;
    for(int i=0; i<num; i++)
    {
        if(i!=0) cout << " ";
        cout << hobby[i];
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;

int m[10],a[10],b[10],c[10];
int main()
{
    int g=0;
    long long s;
    cin>>s;
    while(s!=0)
    {
        c[++g]=s%10;
        m[c[g]]++;
        s=s/10;
    }
    //for(int i=1;i<=g;i++)
    //    cout<<c[i]<<endl;
    int k=0;
    for(int i=9;i>=0;i--)
    {
        if(m[i]!=0)
        a[++k]=i;
    }
    //cout<<"k="<<k<<endl;
    cout<<"int[] arr = new int[]{";
    for(int i=1;i<=k;i++)
    {
        if(i!=1)
        cout<<",";
        cout<<a[i];
        b[a[i]]=i-1;
    }
    cout<<"};"<<endl;
    cout<<"int[] index = new int[]{";
    for(int i=g;i>=1;i--)
    {
        if(i!=g)
        cout<<",";
        cout<<b[c[i]];
    }
    cout<<"};">>endl;
    return 0;
}

*/
/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a1,a2,n;
    cin>>a1>>a2>>n;
    if(n==1)
        cout<<a1;
    else if(n==2)
    {
        cout<<a1<<" "<<a2;
    }
    else
    {
        for(int i=1; i<=n-2; i++)
        {
            if(i%2==0)
            {
                a1=a1*a2;
                cout<<a1;
            }
            else
            {
                a2=a1*a2;
                cout<<a2;
            }
            if(i!=n-2)
                cout<<" ";
        }
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int f[10005];
int findd(int x)
{
    if(x == f[x])
        return x;
    else
        return f[x] = findd(f[x]);
}
void hb(int x, int y)
{
    int fx = findd(x);
    int fy = findd(y);
    if(fx != fy)
        f[fx] = fy;
}
int main()
{
    int t;
    cin>>t;
    for(int i = 0 ; i <= 10000; i ++)
        f[i] = i;
    int peo = 0;
    while(t-- > 0)
    {
        int num, x;
        cin>>num>>x;
        peo = max(peo, x);
        for(int i = 2; i <= num; i ++)
        {
            int y;
            cin>>y;
            hb(x,y);
            peo = max(peo, y);
        }
    }
    int flag[10005];
    int sum = 0;
    for(int i = 1; i <= peo; i ++)
    {
        if(flag[findd(i)] != 1)
        {
            flag[findd(i)] = 1;
            sum++;
        }
    }
    cout<<peo<<" "<<sum<<endl;
    cin>>t;
    while(t-- > 0)
    {
        int x, y ;
        cin>>x>>y;
        if(findd(x) == findd(y))
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
    }
    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;
long long dp[1000005][4];
char a[1000005];
int main()
{
    scanf("%s",a+1);
    long long n = strlen(a+1);
    dp[0][0] = 1;

    for(long long i = 1; i<=n ; i++)
    {
        for(long long j=0; j<=3 ; j++)
        {
            if(dp[i-1][j]==0)continue;
            if(j+1<=3)dp[i][j+1]+=dp[i-1][j];
            dp[i][j]+=dp[i-1][j];
            for(long long k = i-1; k>=1&&i-k<=j; k--)
            {
                if(a[i] == a[k])
                {
                    dp[i][j]-=dp[k-1][j-(i-k)];
                    break;
                }
            }
        }
    }
    cout<<dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3]<<endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fun(ll a,ll b)//求最大公约数
{
    int t=min(a,b);
    for(int i=t; i>=1; i--)
        if(a%i == 0 && b%i == 0)
            return i;
}
int main()
{
    ll N = 0, a = 0, b = 0, sum_a = 0, sum_b = 1, t;
    scanf("%lld", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld/%lld", &a, &b);
        //通分相加
        sum_a *= b;
        sum_a += a * sum_b;
        sum_b *= b;
        //约分
        t = fun(sum_a, sum_b);
        sum_a /= t;
        sum_b /= t;
    }
    if(sum_b==0)cout<<"0";
    else if (sum_a % sum_b == 0)cout<<sum_a/sum_b;
    else if (sum_a < sum_b)cout<<sum_a<<"/"<<sum_b;
    else cout<<sum_a / sum_b<<" "<<sum_a % sum_b<<"/"<<sum_b;
    return 0;
}
*/
/*
//卖月饼
#include<bits/stdc++.h>
using namespace std;
int nn,rq,dp[1005][1005];
struct mooncake
{
    double n;//货存
    double v;//总价
    double k;//性价比
} moon[1005];
bool cmp(mooncake a,mooncake b)
{
    return a.k>b.k;
}
int main()
{
    cin>>nn>>rq;
    for(int i=1; i<=nn; i++)
        cin>>moon[i].n;
    for(int i=1; i<=nn; i++)
        cin>>moon[i].v;
    for(int i=1; i<=nn; i++)
        moon[i].k=moon[i].v/moon[i].n;
    sort(moon+1,moon+1+nn,cmp);

    double sum=0;
    for(int i=1; i<=nn; i++)
    {
        if(rq<=moon[i].n)
        {
            sum+=moon[i].k*rq;
            break;
        }
        else
        {
            sum+=moon[i].v;
            rq-=moon[i].n;
        }
    }
    printf("%.2lf",sum);
    return 0;
}
*/

/*
//排座位 死对头 共同朋友
#include<bits/stdc++.h>
using namespace std;
int f[105],mp[105][105];

int getf(int i)
{
    if(f[i]==i)return i;
    return f[i]=getf(f[i]);
}

void hb(int a,int b)
{
    if(getf(a)!=getf(b))
        f[getf(b)]=getf(a);
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        f[i]=i;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(c==1)
            hb(a,b);
        else if(c==-1)
        {
            mp[a][b]=1;
            mp[b][a]=1;
        }
    }
    while(k--)
    {
        int a,b;
        cin>>a>>b;
        if(getf(a)==getf(b)&&mp[a][b]==0)
            cout<<"No problem";
        if(getf(a)!=getf(b)&&mp[a][b]==0)
            cout<<"OK";
        if(getf(a)==getf(b)&&mp[a][b]==1)
            cout<<"OK but...";
        if(getf(a)!=getf(b)&&mp[a][b]==1)
        cout<<"No way";
        if(k!=0)cout<<endl;
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int a[105][105],b[105][105];
int main()
{
    int h1,l1;
    cin>>h1>>l1;
    for(int i=1; i<=h1; i++)
        for(int j=1; j<=l1; j++)
            cin>>a[i][j];
    int h2,l2;
    cin>>h2>>l2;
    for(int i=1; i<=h2; i++)
        for(int j=1; j<=l2; j++)
            cin>>b[i][j];
    if(l1!=h2)cout<<"Error: "<<l1<<" != "<<h2;
    else
    {
        int c[h1+1][l2+1];
        for(int i=1; i<=h1; i++)
        {
            int sum=0;
            for(int j=1; j<=l2; j++)
            {
                int sum=0;
                for(int k=1; k<=l2; k++)
                {
                    sum+=(a[i][k]*b[k][j]);
                }
                c[i][j]=sum;
            }
        }
        //打印输出
        cout<<h1<<" "<<l2<<endl;
        for(int i=1; i<=h1; i++)
        {
            for(int j=1; j<=l2; j++)
            {
                printf("%d",c[i][j]);
                if(j!=l2)cout<<" ";
            }
            if(i!=h1)cout<<endl;
        }
    }
    return 0;
}
*/

#include<iostream>
using namespace std;
string a,b; //a是原字符串，b是修改后的字符串

int ch(string s,int x) // 判断字符是哪一类
{
    if(s[x]>='a' && s[x]<='z') return 1;
    else if(s[x]>='A' && s[x]<='Z') return 2;
    else if(s[x]>='0' && s[x]<='9') return 3;
    else if(s[x]==' ') return 4;
    else return 5; // 除空格以外的标点符号
}

int check(int x,int y) // 判断是否满足"独立的字符串"
{
    if((x<0 || b[x]==' ' || ch(b,x)==5 ) && (y>=b.size() || b[y]==' ' || ch(b,y)==5))
        return 1;
    return 0;
}

int main()
{
    int N;
    cin>>N;
    getchar();
    while(N--)
    {
        getline(cin,a);
        cout << a << endl << "AI: ";
        int l = 0,r = a.size() - 1;
        while(a[l]==' ') l++; // 去掉全部首空格
        while(a[r]==' ') r--; // 去掉全部尾空格
        for(int i=l; i<=r; i++) // 从l~r循环，这样就相当于去掉全部首尾空格了
        {
            if(ch(a,i) == 2 && a[i] != 'I') // 大写变小写
                b+=a[i]+32;
            else if(a[i] == '?')  // ?变！
                b+='!';
            else if(a[i] == ' ' && (a[i+1] == ' '||ch(a,i+1) == 5)) // 去掉多余空格（单词间的空格、标点符号前的空格）
                continue;
            else
                b+=a[i];   // 其他字符
        }
        for(int i=0; i<b.size(); i++)
        {
            if(b[i]=='I' && check(i-1,i+1))
                cout<<"you";
            else if(b.substr(i,2) == "me" && check(i-1,i+2)) // b.substr(i,2)代表截取b字符串从i下标开始的两个字符
                cout<<"you", i++;
            else if(b.substr(i,7) == "can you" && check(i-1,i+7))
                cout<<"I can", i+=6;
            else if(b.substr(i,9) == "could you" && check(i-1,i+9))
                cout<<"I could", i+=8;
            else
                cout<<b[i];
        }
        cout<<endl;
        b=""; //将b更新为空字符串
    }
}
