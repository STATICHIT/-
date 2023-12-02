#include<bits/stdc++.h>
using namespace std;

long long a[100010];
long long sum,Max;
int main()
{
    int n,i;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>a[i];
    sum=Max=a[1];
    int step=1,S=1;//层数
    i=1;
    while(i<=n)
    {
        if(sum>Max)
        {
            S=step;
            Max=sum;
        }
        int m=step*2;
        sum=0;//层和重置为0
        while(m--)
        {
            i++;
            sum+=a[i];
        }
        step++;
    }
    cout<<S;
    return 0;
}
