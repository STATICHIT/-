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
            //�Ե�ǰ��Ϊ���½�����ε��ܺͣ�ǰ׺�ͣ���
            ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+a[i][j];
        }
    }
    //��ֹ��Χ���ޣ�����i��j��c��ʼ����
    for(int i=c;i<=n;++i){
        for(int j=c;j<=m;++j){
            //���Ըõ�Ϊ���½ǵ��׶���С���������ܺ�
            if(ans[i][j]-ans[i-c][j]-ans[i][j-c]+ans[i-c][j-c]>maxx){
                //�������ֵ
                maxx=ans[i][j]-ans[i-c][j]-ans[i][j-c]+ans[i-c][j-c];
                xx=i;
                yy=j;
            }
        }
    }
    cout<<xx-c+1<<" "<<yy-c+1;//���Ͻ�����
    return 0;
}
