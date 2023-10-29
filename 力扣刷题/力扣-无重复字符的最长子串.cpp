#include<bits/stdc++.h>
using namespace std;

int main()
{
    int maxlen=0;
    int length=1;
    string a="au";
    if(a=="")//空
    {
        cout<<"0";
    }
    else if(a==" ")//一个空格
    {
        cout<<"1";
    }
    else
    {
        string str=a.substr(0,1);
        //cout<<str<<endl;
        for(int i=1; i<a.length(); i++)
        {
            length = str.length();
            if(length>=maxlen)
                maxlen=length;
            string s=a.substr(i,1);
            int idx=str.find(s);
            if(idx!=-1)
            {
                str.erase(0,idx+1);
                str.append(s);
            }
            else
                str.append(s);
        }
        length = str.length();
        if(length>=maxlen)
                maxlen=length;
        cout<<"最长子字符串长度为"<<maxlen;
    }

    return 0;

}
