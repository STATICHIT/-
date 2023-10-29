/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    int ans=0,t=0;
    char a;
    int ver[10000];
    while(~scanf("%c",&a))
    {
        if(a=='\n')break;
        if(a==' ')
        {
            if(!q.empty())
            {
                int o=0,v=0;
                while(!q.empty())
                {
                    o+=(q.front())*pow(10,v);
                    //cout<<"o="<<o<<endl;
                    q.pop();
                    v++;
                }
                ver[t]=o;
                cout<<"ver["<<t<<"]="<<o<<endl;
                t++;
            }
            continue;
        }
        q.push(a-'0');
    }
    if(!q.empty())
    {
        int o=0,v=0;
        while(!q.empty())
        {
            o+=(q.front())*pow(10,v);
            q.pop();
            v++;
        }
        ver[t]=o;
        cout<<"ver["<<t<<"]="<<o<<endl;
        t++;
    }
    //cout<<"t="<<t<<endl;
    int ans1=0,ans2=0;
    for(int i=0; i<t; i++)
    {
        if(i%2==0)
            ans1+=ver[i];
        else
            ans2+=ver[i];
    }
    // cout<<"ans1="<<ans1<<" ans2="<<ans2<<endl;
    ans=max(ans1,ans2);
    cout<<ans;
    return 0;
}
*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i=0,a[100];
    do{
        scanf("%d",&a[i++]);
    }while(getchar()!='\n');

    //¼ìÑé½á¹û
    for(int j=0;j<i;j++){
        cout<<"a["<<j<<"]="<<a[j]<<endl;
    }
}

