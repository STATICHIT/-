#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,p,q,c,a[1000010];
//�����������������ֵ���ܺ�Ϊp����������ֵ�ܺ�Ϊq
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=2;i<=n;i++){
        c=a[i]-a[i-1];//���
        if(c>0){
            p+=c;
        }else
        q-=c;
    }
    ll ans1=max(p,q);
    ll ans2=abs(p-q)+1;
    cout<<ans1<<endl<<ans2;
    return 0;
}
