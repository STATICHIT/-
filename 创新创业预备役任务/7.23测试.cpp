/*
//F
#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
int main()
{
    map<string,int> a;
    cin>>n>>m;
    while(n--){
        cin>>s;
        a[s]=1;
    }
    while(m--){
        cin>>s;
        if(a.find(s)!=a.end()){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
*/

/*
//B
#include<bits/stdc++.h>
using namespace std;
int n,x,a,b,c,o1,o2,o3;
int main()
{
    cin>>n;
    while(n--)
    {
        int a[4]= {0,0,0,0},b[4];
        cin>>x;
        a[x]=1;
        for(int i=1; i<=3; i++)cin>>b[i];

        o1=b[x];
        if(o1==0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            a[o1]=1;
            o2=b[o1];
            if(o2==0)
            {
                cout<<"NO"<<endl;
                continue;
            }
            else
            {
                a[o2]=1;
                int flag=1;
                for(int j=1; j<=3; j++)
                {
                    if(a[j]==0)flag=0;
                }
                if(flag==1)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;

            }
        }
    }
    return 0;
}
*/
/*
//C
#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
int main()
{
    n=0,m=0;
    cin>>s;
    for(char c:s)
    {
        if(c=='(')
        {
            ans++;
            n++;
        }
        else if(c==')')
        {
            if(n>0){
                ans++;
                n--;
            }
        }
    }
    cout<<ans-n;
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int n,l1,l2,ans,flag;
///�õ�������c++������
///��ǰ����룺s.insert (0,"111");
///intתstring��to_string(i);
string s,sum,b;

//ȥ��ǰ��0
string fun(string s)
{
    int cnt=0;
    for(char c:s)
    {
        if(c!='0')
        {
            break;
        }
        else if(c=='0')
        {
            cnt++;
        }
    }
    return s.substr(cnt,s.size()-cnt);
}
int main()
{
    cin>>n;
    while(n--)
    {
        flag=0;
        b="";
        cin>>s>>sum;
        ///���1��s��sum���ʱ��Ӧ����0
        if(s==sum)
        {
            cout<<"0"<<endl;
            continue;
        }
        l1=s.size()-1,l2=sum.size()-1;
        while(l2>=0)///ֻҪsum��û�����꣬��Ҫ����ѭ��
        {
            int i;
            if(l1>=0)///���2����Ϊs������b���ǲ�֪���ĸ��������������sû�ˣ�sum���У��Ͳ���sλ��ģ�ⲹ0
            {
                i=sum[l2]-'0'-(s[l1]-'0');
            }
            else///�������sģ�ⲹ0
            {
                i=sum[l2]-'0';
            }

            if(i>=0)///���3�����������������ʹ��ڵ���0����ֱ�Ӽ��뵽���ַ�����
            {
                b.insert(0,to_string(i));
            }
            else if(i<0 && l2>=1)///��������������С��0˵��sum�ü�һλ��������ǰһ��������Ϊʮλ������ǰ����sum���±껹���ڵ���1
            {
                l2--;
                i+=(sum[l2]-'0')*10;//���µ�һλ��Ϊʮλ��
                if(i>=10)///����õ�b����λ����ֱ������ʧ�ܣ���Ϊ���չ���s��b��һλһλ��ӵ�
                {
                    flag=-1;
                    break;
                }
                else if(i>=0 &&i<10)///����õ���b�Ǹ�λ�����������������ӵ����ַ�����ȥ
                {
                    b.insert(0,to_string(i));
                }
                else if(i<0)///���sum����һλ�õ���b��С��0�����ǲ����ܵģ��Ǿ�����ʧ�ܡ�
                {
                    flag=-1;
                    break;
                }

            }
            else if(i<0 && l2<1)///���sum�������ٽ�λ�ˣ�˵���޷����㣬ֱ������ʧ��
            {
                flag=-1;
                break;
            }
            l1--,l2--;
        }

        if(l1>=0 ||l2>=0 || flag==-1)//ʧ�����-1
        {
            cout<<"-1"<<endl;
        }
        else//�ɹ����ȥ��ǰ��0�Ĵ��ַ���b
        {
            cout<<fun(b)<<endl;
        }
    }
    return 0;
}
*/

//F
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x;//x����
    int w;//Ȩ��
};
int t,n,m,a,b,ans;
string s;
bool cmp(node a,node b)
{
    return a.w>b.w || a.w==b.w && a.x<b.x;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cout<<endl;
        cin>>n>>m;
        struct node[m+10];
        for(int i=1; i<=m; i++)
        {
            cin>>node[i].x>>node[i].w;
        }
        sort(node+1,node+1+m,cmp);

    }
    return 0;
}
