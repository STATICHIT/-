/*
#include<bits/stdc++.h>
using namespace std;
const double eps=1e-7;
int n;
double a[100010],l,r,ans,pos[4],tmp[4];
bool ck(double k){
    int cnt=1;
    tmp[1]=a[1]+k;//第一个基地
    for(int i=2;i<=n;i++){
        if(a[i]>tmp[cnt]+k){
            if(cnt==3)return false;//如果已经三个基地了还是有更大的点没被覆盖，则不行
            cnt++;//加个点
            tmp[cnt]=a[i]+k;//作为新起点，找到下一个基地
        }
    }
    return true;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    l=0,r=a[n];//左边界为0，右边界为最右边的点坐标
    while(r-l>=eps)//防止卡精度
    {
        double mid=(r+l)*0.5;
        if(ck(mid)){
            ans=mid;
            for(int i=1;i<=3;i++)//更新答案
                pos[i]=tmp[i];
            r=mid-eps;
        }
        else l=mid+eps;
    }
    printf("%.6lf\n",ans);
	printf("%.6lf %.6lf %.6lf",pos[1],pos[2],pos[3]);//输出
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
int n,mid;//因为半径要么为x.0要么为x.5，所以直径一定为整数
int a[200010];
//二分查找第一个大于target的值
int co(double start,int d)
{
    int ends=start+d;
    if(a[n-1]<=ends)return -1;
    int l=0,r=n-1;
    while(l<=r)
    {
        int d=(l+r)/2;
        if(a[d]<=ends)l=d+1;
        else r=d-1;
    }
    return r+1;
}

bool check(int d)
{
    int i=co(a[0],d);
    if(i==-1) return true;
    i = co(a[i],d);
    if(i==-1) return true;
    return (a[i]+d)>=a[n-1];
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)cin>>a[i];
    sort(a,a+n);
    int l=0,r=(a[n-1]-a[0]);
    while(l<=r){
        int mid = l + (r-l)/2;
        if(check(mid))r = mid-1;
        else l = mid+1;
    }
    mid=l;//出循环时l即为符合条件的直径
    printf("%.6lf\n",l*0.5);
    double p1,p2,p3;
    int i;
    p1=a[0]+mid*0.5;
    i=co(a[0],mid);
    p2=a[i]+mid*0.5;
    i=co(a[i],mid);
    p3=a[i]+mid*0.5;
    printf("%.6lf %.6lf %.6lf",p1,p2,p3);
    return 0;
}
