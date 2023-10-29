#include<bits/stdc++.h>
using namespace std;

bool _isPrime(long long n)
{
    if(n==0||n==1)//记住，0和1不是素数，
        return false;
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)return false;
    }
    return true;
}
int main()
{
    long long n;
    cin>>n;
    while(n--)
    {
        long long s;
        cin>>s;
        if(_isPrime(s))cout<<"Yes";
        else
            cout<<"No";
        if(n!=0)
            cout<<endl;
    }
    return 0;
}
