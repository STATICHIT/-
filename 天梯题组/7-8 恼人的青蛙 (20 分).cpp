/*
˼·:
1.�ṹ��������
2.����
3.ö��ȷ�����㣬���㶨�ߣ���鷶Χ��Ѱ�����ϵ���
4.����������
*/
#include<bits/stdc++.h>
using namespace std;

int book[5001][5001];
int r,c,n,a,b;

struct Node
{
    int x,y;
} node[5001];//�ýṹ��������

bool cmp(Node a, Node b)
{
    return (a.x<b.x||(a.x==b.x && a.y<b.y));
}//����a��С������a���ʱb��С�����˳�����й���

bool check(int x,int y)
{
    return(x>=1&&x<=r&&y>=1&&y<=c);
}//bool���ͷ���ֵ����ֱ��дreturn��������
//�����㷵��true�������㷵��false

int main()
{
    cin>>r>>c>>n;
    //���
    for(int i=0; i<n; i++)
    {
        cin>>a>>b;
        node[i].x=a;
        node[i].y=b;
        book[a][b]=1;
    }
    //����
    sort(node,node+n,cmp);
    //for(int i=0;i<n;i++)cout<<node[i].x<<"  "<<node[i].y<<endl;

    //����ö��
    //����ȷ��ֱ���жϿ����Բ������������ans
    int ans=0;//��ʼ�����Ϊ0
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            //������������
            int dx=node[j].x-node[i].x;
            int dy=node[j].y-node[i].y;
            //���i��ǰ�滹�е�˵�������Ǹ����ϵ���ʼ�㣬��������
            if(check(node[i].x-dx,node[i].y-dy))continue;
            int xx=node[j].x+dx,yy=node[j].y+dy;//�����ⷽ�����Ƿ���������
            if(check(xx,yy) == false)continue;
            int cnt=2;//��Ϊ�����Ѿ�ȷ��������
            while(check(xx,yy))//�ڷ�Χ��
            {
                if(book[xx][yy])
                    cnt++;
                else
                    break;
                xx+=dx,yy+=dy;
                ans=max(cnt,ans);
            }
        }
    cout<<ans;
    return 0;
}
