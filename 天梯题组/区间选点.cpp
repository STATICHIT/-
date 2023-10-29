#include<bits/stdc++.h>
using namespace std;
//贪心
struct node
{
    int l,r;
}nod[100001];

bool cmp(node a, node b)//比较规则，按区间右端点升序排列
{
    return a.r<b.r;
}
int main()
{
     int n;
    cin>>n;
    for(int i=0;i<n;i++)//先输入区间
        cin>>nod[i].l>>nod[i].r;
    sort(nod,nod+n,cmp);//后根据右顶点大小排序

    int point=nod[0].r;//比对者选择
    int cnt=1;
    for(int i=1;i<n;i++)//选择区间右端点，保证能够包含更大交叉段，选的点最少
    {
        if(nod[i].l>point)///如果没有交叉
        {
            cnt++;//选点+1
            point=nod[i].r;//并以此区间右端为新一轮比较的点
        }
    }
    cout<<cnt;
    return 0;
}
