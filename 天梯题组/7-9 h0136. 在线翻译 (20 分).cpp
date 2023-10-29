/*
#include<bits/stdc++.h>
using namespace std;
map<string,string>z;
int main()
{

    string ss,s1,s2;
    int i;
     while(getline(cin,ss) && ss != "")//ÊäÈë×Ö·û´®ssÇÒss²»Îª¿Õ
    {
        int x=0;
        if(ss[0]=='\n')break;
        for(i=0; i<=ss.length(); i++)
        {
            if(ss[i]==' ')
            {
                x=i;
                break;
            }
        }
        s1=ss.substr(0,i);
        s2=ss.substr(i+1,ss.length()-1-i);
        z[s2]=s1;
        //cout<<"s1="<<s1<<endl<<"s2="<<s2<<endl;
        //cout<<"z[s2]="<<z[s2]<<endl;
    }
    while(1)
    {
        string s;
        cin>>s;
        if(z.count(s)==1)
            cout<<z[s]<<endl;
        else
            cout<<"eh"<<endl;
    }

    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
map<string,string>z;
int main()
{

    string ss;
    int i;
     while(getline(cin,ss) && ss != "")//ÊäÈë×Ö·û´®ssÇÒss²»Îª¿Õ
    {
        string s1,s2;
        int x=0;
        if(ss[0]=='\n')break;
        for(i=0; i<=ss.length(); i++)
        {
            if(ss[i]==' ')
            {
                x=i;
                break;
            }
        }
          for(int i=0;i<x;i++) s1+= ss[i];
        for(int i=x+1;i<ss.size();i++) s2 += ss[i];
        z[s2]=s1;
        cout<<"s1="<<s1<<endl<<"s2="<<s2<<endl;
        cout<<"z[s2]="<<z[s2]<<endl;
    }

   string s;
     while(cin>>s)
    {
        if(z.find(s) != z.end()) cout<<z[s]<<endl;
        else cout<<"eh\n";
    }

    return 0;
}



#include<bits/stdc++.h>
using namespace std;

string s;
map<string,string>z;
int main()
{
    while(getline(cin,s) && s != "")
    {
        string x,y;
        int idx = 0;
        for(int i=0; i<s.size(); i++)
            if(s[i] == ' ') idx = i;
        for(int i=0; i<idx; i++) x += s[i];
        for(int i=idx+1; i<s.size(); i++) y += s[i];
        z[y] = x;
    }
    while(cin>>s)
    {
        if(z.find(s) != z.end()) cout<<z[s]<<endl;
        else cout<<"eh\n";
    }
    return 0;
}
