#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[110000];
int x[110000],y[110000],t[110000];
int findd(int x)//找祖宗
{
    if(f[x]==x)
        return f[x];
    else
        return f[x]=findd(f[x]);
}
void hb(int x,int y)
{
    if(findd(x)!=findd(y))
        f[findd(x)]=findd(y);
}
void quicksort(int l,int r)
{
    int i,j,mid,p;
    mid=t[(l+r)/2];
    i=l;
    j=r;
    while(i<=j)
    {
        while(t[i]<mid)i++;
        while(t[j]>mid)j--;
        if(i<=j)
        {
            p=t[i];t[i]=t[j];t[j]=p;//交换
            p=x[i];x[i]=x[j];x[j]=p;
            p=y[i];y[i]=y[j];y[j]=p;
            i++;j--;
        }
    }
    if(l<j) quicksort(l,j);
    if(i<r) quicksort(i,r);
}
bool check()
{
    int v=findd(1);
    //cout<<"v="<<v<<endl;
    for(int i=1; i<=n; i++)
    {
        //cout<<"findd("<<i<<")="<<findd(i)<<endl;
        if(findd(i)!=v)
            return false;
    }
    return true;
}
int main()
{
    cin>>n>>m;
    //初始化！
    for(int i=1; i<=n; i++)
        f[i]=i;
    int tmax=-1;
    for(int i=1; i<=m; i++)
    {
        cin>>x[i]>>y[i]>>t[i];
        if(t[i]>tmax)
            tmax=t[i];
    }
    quicksort(1,m);

    //检查快排结果
    //for(int i=1;i<=m;i++)
         //cout<<x[i]<<y[i]<<t[i]<<endl;

    int k,time=1;
    //for(k=1; k<=m; k++)
        //cout<<"t["<<k<<"]="<<t[k]<<endl;;
    for(k=1; k<=m;)
    {//cout<<"time="<<time<<endl;
        if(t[k] == time)
        {
            //cout<<"come in "<<t[k]<<" "<<time<<endl;
            hb(x[k],y[k]);
            if(check()==true)
            {
                //cout<<"come"<<check()<<endl;
                cout<<time;
                return 0;
            }
            k++;
        }
        else
        {
            time++;
        }
    }
        cout<<-1;
    return 0;
}
