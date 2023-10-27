#include<iostream>
using namespace std;
int a[5][5],ans=0,mni=10;
void fun(int x,int y)//按灯
{
    //为1时，1-1=0，变换成功
    //为0时，1-0=1，变换成功
    //妙啊~~ovo
    a[x][y]=1-a[x][y];
    a[x+1][y]=1-a[x+1][y];
    a[x][y+1]=1-a[x][y+1];
    a[x-1][y]=1-a[x-1][y];
    a[x][y-1]=1-a[x][y-1];
}
void dfs(int k)//搜索
{
    if(k>mni)return;
    int s=0;//开灯状态的灯数量
    for(int i=1; i<=3; i++)//计算开灯的数量
        for(int j=1; j<=3; j++)
            s+=a[i][j];
    if(s==9){//已达到全开状态，更新最小值
        ans=k-1;
        mni=min(ans,mni);
    }
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++){
            fun(i,j);
            dfs(k+1);
            fun(i,j);//回溯，再按一次等于没按，相当于回溯
        }
    return;
}
int main()
{
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++)
            cin>>a[i][j];

    dfs(1);//搜索
    cout<<mni;
    return 0;
}
