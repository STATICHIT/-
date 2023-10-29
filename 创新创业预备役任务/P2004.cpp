#include<bits/stdc++.h>
using namespace std;
int n,m,c,xx,yy;
int a[1010][1010],ans[1010][1010],maxx=-999999999;
int main()
{
    cin>>n>>m>>c;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>a[i][j];
            //以当前点为右下角算矩形的总和（前缀和！）
            ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+a[i][j];
        }
    }
    //防止范围超限，所以i，j从c开始遍历
    for(int i=c;i<=n;++i){
        for(int j=c;j<=m;++j){
            //算以该点为右下角的首都大小的正方形总和
            if(ans[i][j]-ans[i-c][j]-ans[i][j-c]+ans[i-c][j-c]>maxx){
                //更新最大值
                maxx=ans[i][j]-ans[i-c][j]-ans[i][j-c]+ans[i-c][j-c];
                xx=i;
                yy=j;
            }
        }
    }
    cout<<xx-c+1<<" "<<yy-c+1;//左上角坐标
    return 0;
}
