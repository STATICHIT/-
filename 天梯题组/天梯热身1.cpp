#include<bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c;
    cin>>a>>b>>c;
    if(b==0)
    {
        b=2.455;
    }
    else
    {
        b=1.26;
    }
    double ans=a*b;
    printf("%.2lf ",ans);
    if(ans>=1)cout<<"T_T";
    else cout<<"^_^";
    return 0;
}
///a
///大天体密度与小天体的密度的比值开 3 次方

//*大天体的半径以及一个倍数
//（流体对应的倍数是 2.455)b=0
//(刚体对应的倍数是 1.26）b=1
//就是洛希极限的值。
