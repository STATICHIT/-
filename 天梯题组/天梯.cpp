/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string o="ong";
    int n;
    cin>>n;
    getchar();//吸收掉输入完n后的回车键
    int f1,f2,x;
    while(n--)
    {
        f1=0,f2=0;
        int sign[200]= {0};
        string str;
        getline(cin,str);
        int len=str.size();
        int k=0;
        for(int i=len; i>=0; i--)
        {
            if(str[i]==',')
            {
                x=i;
                break;
            }
            if(str[i]==' ')
            {
                sign[k]=i;
                k++;
            }
        }
        if(str.substr(x-3,3)== o)
            f1=1;
        if(str.substr(len-4,3)== o)
            f2=1;
        if(f1 == 1 && f2 == 1)
        {
            if(k>=3)
            {
                for(int i=0; i<=sign[2]; i++)
                    cout<<str[i];
                cout<<"qiao ben zhong.";
            }
            else
            {
                for(int i=0; i<=x; i++)
                    cout<<str[i];
                cout<<"qiao ben zhong.";
            }
        }
        else
            cout<<"Skipped";
        if(n!=0)cout<<endl;
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;

int num[100001];
int doublesort(int a,int b,int c)
{
    int mid=(b+c)/2;
    if(b>c)return -1;
    if(num[mid]==a)
        return mid;
    else if(a>num[mid])
    {
        doublesort(a,mid+1,c);
    }
    else if(a<num[mid])
    {
        doublesort(a,b,mid-1);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>num[i];
    sort(num,num+n);
    int m;
    cin>>m;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        cout<<doublesort(a,b,c);
        if(m!=0)
            cout<<endl;
    }
    return 0;
}
*/
