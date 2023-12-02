#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long f1,f2,f3,temp;
    f1=1,f2=1,f3=1;
    for(int i=4;i<=20190324;i++)
    {
        temp=((f1+f2)%10000+f3)%10000;
        f1=f2;
        f2=f3;
        f3=temp;
    }
    cout<<temp<<endl;

    return 0;
}
