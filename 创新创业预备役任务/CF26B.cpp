#include<bits/stdc++.h>
using namespace std;
stack<char>st;
int main()
{
    int z;
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')st.push('(');
        else if(s[i]==')')
        {
            if((!st.empty())&&st.top()=='(')
            {
                z++;
                st.pop();
            }
        }
    }
    cout<<z*2;
    return 0;
    //Ҫ����ɾ������������Ϸ�����
    //�����Ǹ������ַ��������������
}
