#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
    cin>>t;
    while(t--)
    {
        int point=0;
        cin>>n;
        int a[2*n+1],b[2*n+1];
        for(int i=0; i<2*n; i++)
            cin>>a[i];
        for(int i=0; i<2*n; i++)
            cin>>b[i];
       for(int i=0; i<2*n; i++)
        {
            //if(a[i]<b[i]||(a[i]==3&&b[i]==1))
            //{
            //   continue;
            //}
//            else
//          pass了上面的方法是因为这样子不好修改
            if(i<n)
              {
                if (b[i] == 1) a[i] = 3;
			    if (b[i] == 2) a[i] = 1;
			    if (b[i] == 3) a[i] = 2;
              }
            else
              {
                if (a[i] == 1) b[i] = 2;
			    if (a[i] == 2) b[i] = 3;
			    if (a[i] == 3) b[i] = 1;
              }

        }
        point=2*n;//通过寻找规律能发现a必赢，所以有多少比赛，a就多少分
        cout<<point<<endl;
        for(int i=0;i<n*2;i++)
             cout<<a[i]<<" ";
        cout<<endl;
        for(int i=0;i<n*2;i++)
            cout<<b[i]<<" ";
        if(t!=0)
        cout<<endl;
    }
    return 0;
}
