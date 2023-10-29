//连续因子
#include<bits/stdc++.h>
using namespace std;
long long n,i,j,start,l,s=1;
bool prime(int n)//判断是否是质数
{
    for(i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int main()
{
    cin>>n;
    if(prime(n))//如果是素数，则直接输出1和该数
        cout<<"1"<<endl<<n<<endl;
    else
    {
        for(i=2; i<=sqrt(n); i++)//n的因子不会超过sqrt（n）
        {
            s=1;
            for(j=i; s*j<=n; j++)//以i开头的连续因子
            {
                s=s*j;//不断加连续因子
                if(n%s==0&&j-i+1>l)//连续数大于长度l且连续因子都为n的因子（即连续因子的积可以被n整除）才可以更新i和l
                {
                    start=i;//更新连续因子开始数
                    l=j-i+1;//更新最长连续因子长度
                }
            }
        }
        //输出阶段
        cout<<l<<endl;
        for(i=start; i<start+l; i++)
        {
            cout<<i;
            if(i!=start+l-1)//如果不是最后一个数，都要加一个*
                cout<<"*";
        }
    }
    return 0;
}




