//����Ҫ�õ�ÿ������֮������Ȩֵ������Ҫ��floyd
//��o2���ܹ��������t
#include<bits/stdc++.h>
using namespace std;
#define inf 999999
int n,m,v[1010][1010];
int x,y,z;
int main()
{
    memset(v,inf,sizeof(v));
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        v[x][y]=min(z,v[x][y]);//ȥ�ر�
    }
    //flody
    for(int k=1; k<=n; ++k)
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                v[i][j]=min(v[i][k]+v[k][j],v[i][j]);
    int ans=0;
    for(int i=2; i<=n; ++i)
        ans+=v[1][i]+v[i][1];//ÿ��ȥ��ʱ��+������ʱ��
    cout<<ans;
    return 0;
}
