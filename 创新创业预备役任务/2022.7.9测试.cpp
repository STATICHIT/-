/*
#include<bits/stdc++.h>
using namespace std;
long long int a,b;
//������A������ֵB
//n������ ������ai������ֵbi
long long t,ha,hb,n;

struct m
{
    long long int a;//������
    long long int b;//����ֵ
} ma[1000000];
bool cmp(struct m m1,struct m m2)
{
    return m1.a==m2.b?m1.b<m2.b:m1.a<m2.a;
}
int flag;
int main()
{
    cin>>t;
    while(t--)
    {
        flag=0;
        cin>>ha>>hb>>n;
        for(int i=0; i<n; i++)cin>>ma[i].a;
        for(int i=0; i<n; i++)cin>>ma[i].b;
        sort(ma+1,ma+1+n,cmp);
        for(int i=0; i<n; i++)
        {
            int run = ma[i].b%ha==0?ma[i].b/ha:ma[i].b/ha+1;
            int hit = ma[i].a*run;
            hb-=hit;
            //cout<<run<<endl;
            if(hb<=0 &&i<n-1)
            {
                cout<<"NO"<<endl;
                flag=1;
                break;
            }
            if(hb<=0 && i==n-1 && hb+ma[i].a<=0)
            {
                cout<<"NO"<<endl;
                flag=1;
                break;
            }
        }
        if(!flag)cout<<"YES"<<endl;
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
struct m
{
    long long a;
    long long b;
}master[1010000];
long long t,ha,hb,n;
bool cmp(struct m m1,struct m m2){
    return m1.a==m2.b?m1.b<m2.b:m1.a<m2.a;
}
int main()
{
    cin>>t;
    while(t--)
    {
        int flag=0;
        cin>>ha>>hb>>n;
        for(int i=1; i<=n; i++)cin>>master[i].a;
        for(int i=1; i<=n; i++)cin>>master[i].b;
        sort(master+1,master+1+n,cmp);//�����Զ����������
        for(int i=1; i<=n; i++)
        {
            long long run=master[i].b%ha==0?master[i].b/ha:master[i].b/ha+1;//�ù����ܿ�����
            long long hit=master[i].a*run;//��������˺�
            hb-=hit;//Ӣ��Ѫ��ʣ��ֵ
            if(hb <= 0 && i < n){cout<<"NO"<<endl;flag = 1;break;}//Ӣ�����˵����޻�û����
            if(i == n && hb < 0 && hb + master[i].a <= 0){cout<<"NO"<<endl; flag = 1;break;}//Ӣ�����ˣ����һ�����޻�û��
        }
        if(flag == 0)
            cout<<"YES"<<endl;
    }
}
