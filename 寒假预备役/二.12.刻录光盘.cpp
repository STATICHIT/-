#include <bits/stdc++.h>
using namespace std;
int will[210][210];//will��Ը����Ԫ�ص�ֵȡ1��0��ʾһ�����Ƿ�Ը�������һ���˿���
int f[210],n;
int main()
{
    cin>>n;
    //memset(will,0,sizeof(will));  //��ʼ����������֮�䶼û����Ը
    //��Ϊwill������ȫ�ֱ������ǿ��Բ���ʼ����

      //��ʼ����������
    for(int i=1; i<=n; i++)
        f[i]=i;

    int x;
    for(int i=1; i<=n; i++)
        while(cin>>x && x!=0)//ÿһ�����ݸ�����ȷ��������0�������
             will[i][x]=1;  //��ʾ��i����Ը�����x���˿���

    //Floyd-Warshall����Ը��ϵת��Ϊ����·������
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(will[i][k] == 1 && will[k][j] == 1)//���iԸ���k��kԸ���j�����൱��iԸ���j
                    will[i][j]=1;

    for(int i=1; i<=n; i++)//������Ը����
        for(int j=1; j<=n; j++)
            if(will[i][j])
                f[j]=f[i];  //����ֱ�Ӻϲ�����Ϊ����Ĺ�ϵ�ǵ���ģ�Ҫf�������ˡ�=f��Ը������������ˡ�����������Ը���������������Ϊ�ϴ�

    int ans=0;
    for(int i=1; i<=n; i++)
        if(f[i]==i)
            ans++;  //�������Ժ�f��x��=x������Ҫ��һ������

    cout<<ans;
    return 0;
}
