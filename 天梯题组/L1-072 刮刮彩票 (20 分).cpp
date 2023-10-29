/*
#include<bits/stdc++.h>
using namespace std;

int reward[26]= {0,0,0,0,0,0,10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,1800,3600};
int a[4][4],x,y,sum;
int main()
{
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++)
        {
            cin>>a[i][j];
            sum+=a[i][j];
            if(a[i][j]==0)
                x=i,y=j;
        }
    a[x][y]=45-sum;
    int n=3;
    while(n--)
    {
        cin>>x>>y;
        cout<<a[x][y]<<endl;
    }
    int k;
    cin>>k;
    switch(k)
    {
    case 1:
        sum=a[1][1]+a[1][2]+a[1][3];
        break;
    case 2:
        sum = a[2][1] + a[2][2] + a[2][3];
        break;
    case 3:
        sum = a[3][1] + a[3][2] + a[3][3];
        break;
    case 4:
        sum = a[1][1] + a[2][1] + a[3][1];
        break;
    case 5:
        sum = a[1][2] + a[2][2] + a[3][2];
        break;
    case 6:
        sum = a[1][3] + a[2][3] + a[3][3];
        break;
    case 7:
        sum = a[1][1] + a[2][2] + a[3][3];
        break;
    case 8:
        sum = a[1][3] + a[2][2] + a[3][1];
    }
    cout<<reward[sum];
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    getchar();
    string s;
    while(m--)
    {
        cin>>s;
        int len=s.size();
        int right=pow(2,n),left=0;
        for(int i=0; i<n-1; i++)
        {
            if(s[i]=='y')right=(right-left)/2+left;
            else left=(right-left)/2+left;
        }
        if(s[n-1]=='y')
            cout<<left+1;
        else cout<<right;
        if(m!=0)cout<<endl;
    }
    return 0;
}
