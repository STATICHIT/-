#include <bits/stdc++.h>
using namespace std;
int a[20001],f[20001];
int n;
int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    f[1]=1;
    for (int i=2; i<=n; i++)
    {
        f[i]=1;//赋初值 要是该数比前面任何一个数都小 那么该数的最长上升子序列为1
        for (int j=1; j<i; j++)
        {
            if(a[i]>a[j]&&f[i]<f[j]+1) //因为该位置的数可能比前面的好几个数都大 但我们要找出最长的那个然后+1
            {
                f[i]=f[j]+1;
            }
        }
    }
    int max_=1;
    for (int i=1; i<=n; i++)//找出最大值
    {
        if(max_<f[i])
        {
            max_=f[i];
        }
    }
    cout<<max_;
    return 0;
}
