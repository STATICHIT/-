#include<bits/stdc++.h>
using namespace std;

int main()
{
    string m="chi1 huo3 guo1";
    int n=0,hang=0,num[10000],k=0;

    while(1)
    {
        string s;
        getline(cin,s);
        if(s==".")break;
        int len=s.length();
        hang++;//ÿ����һ�μ�һ��
        if(len<14)continue;//С��14����ĸ�򲻿��ܳ���
        for(int i=0; i<=s.length()-14; i++)
        {
            string s2=s.substr(i,14);//������ȡ��һ�������±꿪ʼ��ĵڶ����������ַ��Ӵ�
            if(s2==m)
            {
                n++;
                num[k++]=hang;
                break;
            }
        }
    }
    cout<<hang<<endl;
    if(n!=0)
        cout<<num[0]<<" "<<n;
    else
        cout<<"-_-#";
    return 0;
}

