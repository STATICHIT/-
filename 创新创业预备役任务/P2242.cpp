#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],b[1000010];
bool cmd(int a,int b){
    return a>b;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];//¼���λ
    for(int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];//���пӹ�n-1����϶
    }
    sort(b+1,b+n,cmd);//�Ӵ�С�����϶(��Ϊֻ��n-1����϶��������b+1��b+1+n-1��b+n)
    int ans=a[n]-a[1]+1;
    for(int i=1;i<=m-1;i++)//��ȥ����m-1����϶
    {
        //��Ϊm��������m-1����϶
        ans-=b[i]-1;
    }
    cout<<ans;
    return 0;
}
