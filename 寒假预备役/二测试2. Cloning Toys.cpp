#include<bits/stdc++.h>
using namespace std;
int x,y;//x:������¡������y:����������
int ax,ay;
int main()
{
    cin>>x>>y;
    int m=x;
    int n=y/2;
    for(int i=0;i<=m+10;i++)//��¡��¡�����
        for(int j=0;j<=n+10;j++)//��¡�������
    {
        if(i>0)
        ax=i+j*2;
        //cout<<"now ay="<<ay<<"  i="<<i<<"  j="<<j<<endl;}
        else
        ax=0;
        ay=1+i;
        //cout<<"now ax="<<ax<<endl;
        if(ax==x&&ay==y)
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}
