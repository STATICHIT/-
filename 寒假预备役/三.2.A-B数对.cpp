#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, c,ans;
ll a[200001];
int main ()
{
    cin>>n>>c;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+1+n); //��������
    ll r1=1,r2=1;//˫ָ��
    for(int i=1; i<=n; i++)
    {
        while(r1 <= n && a[r1] - a[i] <= c)//�±겻����n��ǰ�������a[r1]-a[i]<=c�����ƶ�ֱ��a[r1]-a[l]<= c�����λ�õ���һλ
            r1 ++;
        while(r2 <= n && a[r2] - a[i] < c )//�±겻����n��ǰ�������a[r2]-a[i]<c�����ƶ�ֱ��a[r2]-a[l]<c���һλ
            r2 ++;

        if(a[r2]-a[i] == c&&a[r1-1]-a[i] == c&&r1-1>=1)
            ans+=r1-r2;
    }
    cout<<ans;
    return 0;
}
