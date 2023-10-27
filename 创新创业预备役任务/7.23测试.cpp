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
///用到的两个c++函数。
///从前面插入：s.insert (0,"111");
///int转string：to_string(i);
string s,sum,b;

//去除前导0
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
        ///情况1：s和sum相等时，应返回0
        if(s==sum)
        {
            cout<<"0"<<endl;
            continue;
        }
        l1=s.size()-1,l2=sum.size()-1;
        while(l2>=0)///只要sum还没遍历完，就要继续循环
        {
            int i;
            if(l1>=0)///情况2：因为s和所求b我们不知道哪个更长，所以如果s没了，sum还有，就不加s位置模拟补0
            {
                i=sum[l2]-'0'-(s[l1]-'0');
            }
            else///这里就是s模拟补0
            {
                i=sum[l2]-'0';
            }

            if(i>=0)///情况3：如果两个数字相减和大于等于0，就直接加入到答案字符串里
            {
                b.insert(0,to_string(i));
            }
            else if(i<0 && l2>=1)///如果两个数字相减小于0说明sum得加一位，即加上前一个数字作为十位数，但前提是sum的下标还大于等于1
            {
                l2--;
                i+=(sum[l2]-'0')*10;//将新的一位作为十位数
                if(i>=10)///如果得到b是两位数，直接宣告失败，因为按照规则，s和b是一位一位相加的
                {
                    flag=-1;
                    break;
                }
                else if(i>=0 &&i<10)///如果得到的b是个位数，则满足条件，加到答案字符串里去
                {
                    b.insert(0,to_string(i));
                }
                else if(i<0)///如果sum进了一位得到的b还小于0，这是不可能的，那就宣告失败。
                {
                    flag=-1;
                    break;
                }

            }
            else if(i<0 && l2<1)///如果sum不足以再进位了，说明无法满足，直接宣布失败
            {
                flag=-1;
                break;
            }
            l1--,l2--;
        }

        if(l1>=0 ||l2>=0 || flag==-1)//失败输出-1
        {
            cout<<"-1"<<endl;
        }
        else//成功输出去掉前导0的答案字符串b
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
    int x;//x坐标
    int w;//权重
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
