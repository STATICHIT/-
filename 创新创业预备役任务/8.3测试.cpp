/*
//2
#include<bits/stdc++.h>
using namespace std;
long long x,y,x2,y2,x3,y3,x4,y4,d,d1,d2;
long long node[8][2]= {{1,2},{2,1},{-1,2},{-2,1},
    {-1,-2},{-2,-1},{1,-2},{2,-1}
};
int main()
{
    cin>>x>>y>>x2>>y2;
    d=(pow(x-x2,2))+(pow(y-y2,2));
    if(d>20)
    {
        cout<<"No";
        return 0;
    }
    else
    {
        for(int i=0; i<8; i++)
        {
            x3=x-node[i][0],y3=y-node[i][1];
            d1=pow(x-x3,2)+pow(y-y3,2);
            d2=pow(x2-x3,2)+pow(y2-y3,2);
            if(d1==d2 && d1==5)
            {
                cout<<"Yes";
                return 0;
            }
            x4=x2-node[i][0],y4=y2-node[i][1];
            d1=pow(x-x4,2)+pow(y-y4,2);
            d2=pow(x2-x4,2)+pow(y2-y4,2);
            if(d1==d2 && d1==5)
            {
                cout<<"Yes";
                return 0;
            }
        }
        cout<<"No";
    }
}
*/

/*
//3
#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,flag;
int fun(int n)
{
    if(n==1 || n==2 ||n==3)return 1;//素数
    int i=0;
    for(i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
            break;
    }
    if(i<=sqrt(n))return 0;//合数
    else return 1;//素数
}
int main()
{
    cin>>a>>b>>c>>d;
    for(int i=a; i<=b; i++)
    {
        flag=1;//前者赢，找到一个数无论后者选什么都找不到使其为素数
        for(int j=c; j<=d; j++)
            if(fun(i+j))//素数
                flag=0;//前者选此i赢不了了

        if(flag==1)
        {
            cout<<"Takahashi";
            return 0;
        }
    }
    cout<<"Aoki";
    return 0;
}
*/

/*
//4
#include<bits/stdc++.h>
using namespace std;
int n;
string s,str;
int main()
{
    cin>>n;
    cin>>s;
    for(int i=1;i<n;i++){

        if(s[i-1]=='B'&&s[i]=='A'){
            s[i]='B';
            s[i-1]='A';
        }
        if(s[i-1]=='B'&&s[i]=='B')
        {
            s=s.substr(0,i-1)+"A"+s.substr(i+1,n-i-1);
            n--;
        }
    }
    cout<<s;
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
int n,nn,b,bb,e,maxn=0,num=0;
string s,str;
int main()
{
    cin>>n;
    cin>>s;
    if(s[0]!='('&&s[0]!='_')b=0;
    else b=-1;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')
        {
            i++;
            if(s[i]!='_'&&s[i]!=')')bb=i;
            else bb=-1;
            while(1)
            {
                if(s[i]=='_'&&bb!=-1)
                {
                    num++;
                    bb=-1;
                }
                if(s[i]=='_'&&bb==-1)
                {
                    if(s[i+1]!='_'&&s[i+1]!=')')
                    {
                        bb=i+1;
                    }
                }
                if(s[i]==')')
                {
                    if(bb!=-1)num++;
                    break;
                }
                i++;
            }
            i++;
            if(s[i]!='_'&&s[i]!='(')b=i;
            else b=-1;
        }
        if(s[i]=='_'&& b!=-1)
        {
            nn=i-b;
            if(nn>maxn)
                maxn=nn;
            b=-1;
        }
        if(s[i]=='_'&& b==-1)
        {
            //新开始
            b=i+1;
        }
    }
    cout<<maxn<<" "<<num;
    return 0;
}
