/*
#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int a[100000];
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        int d=0,u=0;
        for(int i=1;i<=n;i++){
            cin>>k;
            string s;
            cin>>s;
            u=0,d=0;
            for(int j=0;j<k;j++){
                if(s[j]=='D')d++;
            }
            u=k-d;
            a[i]=(100+a[i]+d-u)%10;
        }
        for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int t,n,k,ans;
int a[100000];
int main()
{
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        k=10000010;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]<k)k=a[i];
        }
        for(int i=1;i<=n;i++)ans+=a[i]-k;
    cout<<ans<<endl;
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int t,n,x,ans;
int a[100000];
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>x;
        for(int i=1;i<=2*n;i++)
            cin>>a[i];
        sort(a+1,a+1+2*n);
        int flag=1;
        for(int i=1;i<=n;i++){
            if(a[n+i]-a[i]<x){
                flag=0;
                break;
            }
        }
        if(flag==1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
*/

/*
//D
#include<bits/stdc++.h>
using namespace std;
int t,n,m;
long long ans;
long long arr[210][210];

long long fun(int a,int b)
{
    long long r=0;
    int p=a-b,q=a+b;
//    for(int i=1; i<=n; i++)
//   {
//       if(i+p<=m && i+p>0)r+=arr[i][i+p];
//        if(q-i<=m && q-i>0)r+=arr[i][q-i];
//   }

    //酱紫是对的，注释掉的是错的
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(i-j==p || i+j == q)
                r+=arr[i][j];
    //r-=arr[a][b];
    return r;
}
int main()
{
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>m;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                cin>>arr[i][j];

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                long long now=fun(i,j);
                if(now>ans)ans=now;
            }
        }
        cout<<"--"<<ans<<endl;
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int a[100000];
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        int d=0,u=0;
        for(int i=1;i<=n;i++){
            cin>>k;
            string s;
            cin>>s;
            u=0,d=0;
            for(int j=0;j<k;j++){
                if(s[j]=='D')d++;
            }
            u=k-d;
            a[i]=(100+a[i]+d-u)%10;
        }
        for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int t,n,k,ans;
int a[100000];
int main()
{
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        k=10000010;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]<k)k=a[i];
        }
        for(int i=1;i<=n;i++)ans+=a[i]-k;
    cout<<ans<<endl;
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
long long t,n,q,m,sum,k,ans;
long long a[1000000];
long long uu[1000000];

bool cmp(int f,int g)
{
    return f>g;
}

//二分查找
long long fun(int m,int l,int r)
{
    ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(uu[mid]>=m && uu[mid-1]<m)
        {
            ans= mid;
            break;
        }
        if(uu[mid]<m)l=mid+1;
        else r=mid-1;
    }
    return ans;
}
int main()
{
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n>>q;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        sort(a+1,a+1+n,cmp);
        uu[0]=0;
        //计算前缀和
        for(int i=1; i<=n; i++)
        {
            uu[i]=a[i]+uu[i-1];
        }
        while(q--)
        {
            cin>>m;
            if(m>sum)
            {
                cout<<"-1"<<endl;
                continue;
            }
            if(m==sum)
            {
                cout<<n<<endl;
                continue;
            }
            cout<<fun(m,1,n)<<endl;
        }
    }
    return 0;
}
*/


/*
#include<bits/stdc++.h>
using namespace std;
int myAtoi(string s)
{
    int n=s.size(),i;
    int a[1000]= {0},j=0;
    //丢去前导空格
    for(i=0; i<n; i++)
    {
        if(s[i]!=' ')break;
    }

    int flag=1;
    //判断正负
    if(s[i]=='-')
    {
        flag=0;
        i++;
    }
    else if(s[i]=='+')
    {
        flag=1;
        i++;
    }

    for(; i<n; i++)
    {
        if(s[i]!='0')break;
    }

    for(; i<n; i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[j++]=s[i]-'0';
        }
        else
        {
            break;
        }
    }
    if(j>18)
    {
        if(flag==1)return pow(2,31)-1;
        if(flag==0)return -1*(pow(2,31));
    }
    long long sum=0;

    for(i=0; i<j; i++)
    {
        if(flag==1) sum+=a[i]*pow(10,j-i-1);
        if(flag==0) sum-=a[i]*pow(10,j-i-1);
        if(sum>=((pow(2,31)-1))) return pow(2,31)-1;
        if(sum<=(-1*(pow(2,31)))) return -1*(pow(2,31));
    }
    return sum;
}
int main()
{
    string s="-000000000000000000000000000000000000000000000000001";
    cout<<myAtoi(s);
}

*/


#include<bits/stdc++.h>
using namespace std;
int t,a,b,flag=0;
int main()
{
    cin>>t;
    while(t--)
    {
        flag=0;
        string s;
        cin>>s;
        a=0,b=0;
        int len=s.size();
        if(s[0]=='B')
        {
            cout<<"错"<<endl;
            continue;
        }
        if(s[len-1]=='A')
        {
            cout<<"错"<<endl;
            continue;
        }
        for(char c:s)
        {
            if(c=='A')a++;
            else b++;
            if(a<b)
            {
                cout<<"错"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"对"<<endl;
    }
    return 0;
}



