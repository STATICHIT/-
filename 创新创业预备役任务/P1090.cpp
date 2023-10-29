#include<bits/stdc++.h>
using namespace std;
int n,x,ans;
//priority_queue<int, vector<int>, greater<int> > 按照最小堆优先级 优先队列类库
//小顶堆小的在上面，所以先把所有数据加入优先队列，然后每次把最上面两个数据相加（并取出），再把结果加入优先队列。
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>x;
        q.push(x);
    }

    while(q.size()>=2)
    {
        int a=q.top();
        q.pop();
        int b=q.top();
        q.pop();
        ans+=a+b;
        q.push(a+b);
    }

    cout<<ans;
    return 0;
}
