#include<bits/stdc++.h>
using namespace std;
long long ans=1,n;
int main()
{
    cin>>n;
    for(int i=1;i<n;i++){
        ans=3*ans;
        ans=ans%(1000003);
    }
    cout<<ans;
    return 0;
}
