#include<bits/stdc++.h>
using namespace std;
//̰��
struct node
{
    int l,r;
}nod[100001];

bool cmp(node a, node b)//�ȽϹ��򣬰������Ҷ˵���������
{
    return a.r<b.r;
}
int main()
{
     int n;
    cin>>n;
    for(int i=0;i<n;i++)//����������
        cin>>nod[i].l>>nod[i].r;
    sort(nod,nod+n,cmp);//������Ҷ����С����

    int point=nod[0].r;//�ȶ���ѡ��
    int cnt=1;
    for(int i=1;i<n;i++)//ѡ�������Ҷ˵㣬��֤�ܹ��������󽻲�Σ�ѡ�ĵ�����
    {
        if(nod[i].l>point)///���û�н���
        {
            cnt++;//ѡ��+1
            point=nod[i].r;//���Դ������Ҷ�Ϊ��һ�ֱȽϵĵ�
        }
    }
    cout<<cnt;
    return 0;
}
