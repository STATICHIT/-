#include<bits/stdc++.h>
using namespace std;
map<string,string> f;
string s,sf;
string getf(string i)
{
    if(i==f[i])return i;
    else return f[i]=getf(f[i]);
}
int main()
{
    char c;
    cin>>c;//���յ�һ���ַ�
    while(c!='$')
    {
        cin>>s;
        if(c=='#')//��������
        {
            sf=s;//��¼��������
            if(f[s]=="")f[s]=s;//�������û�и��ף���ô�����Լ�������
        }
        else if(c=='+') //��������
        {
            f[s]=sf;//���ĸ�������һ������¼�ĸ�������
        }
        else if(c=='?')//���ʣ�
        {
            cout<<s<<" "<<getf(s)<<endl;
        }
        cin>>c;//�ٴν��յ�һ���ַ�
    }
    return 0;
}
