#include<bits/stdc++.h>
using namespace std;
priority_queue<int> p;//´ó¶¥¶Ñ
int n,a[100000],b[100000];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cin>>b[1];
    for(int i=1;i<=n;i++)p.push(a[i]+b[1]);

    for(int i=2;i<=n;i++){
        cin>>b[i];
        for(int j=1;j<=n;j++){
            if(a[j]+b[i]>p.top()){
                break;
            }else{
              p.pop();
              p.push(a[j]+b[i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        a[i]=p.top();
        p.pop();
    }
    for(int i=n;i>=1;i--)cout<<a[i]<<" ";
    return 0;
}
