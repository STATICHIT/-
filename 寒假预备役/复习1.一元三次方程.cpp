#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main()
{
    cin>>a>>b>>c>>d;
    for(double i=-200;i<=200;i++)
        if(a*i*i*i+b*i*i+c*i+d==0)
        printf("%.2f ",i);
    return 0;
}
