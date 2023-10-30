#include<bits/stdc++.h>
using namespace std;
#define base 131
#define mod 19260817
int n,ans;
char str[11000];
long long int ha[11000];

long long hashs(char s[])
{
    int len=strlen(s);
    long long hs=0;
    for(int i=0;i<len;i++)//前缀和的思想
    {
        hs=(hs*base+(long long)s[i])%mod;
    }
    return hs;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        ha[i]=hashs(str);
        cout<<ha[i]<<endl;
    }
    sort(ha,ha+n);

    //for(int i=0;i<5;i++)
      //  cout<<ha[i]<<endl;

    for(int i=1;i<n;i++)
    {
        if(ha[i]!=ha[i-1])
            ans++;
    }
    cout<<ans+1;
    return 0;
}
