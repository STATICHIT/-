#include<bits/stdc++.h>
using namespace std;
#include <stack>//ʵ��������ͷ�ǰ����������
stack<char> st;//�ַ����͵�ջ
bool check(string str)
{
    int n = str.size();
    if(n % 2 != 0)//�������ż�����ַ����϶���ƥ��
        return false;
    else
    {
        for(int i = 0; i < n; i++)
        {
            if( (str[i] == '(')|| (str[i] == '[')|| (str[i] == '{'))
            {
                st.push(str[i]);//���������������ջ
            }
            else
            {
                if(!st.empty()) //ע�����ж�ջ�����
                {
                    if((st.top() == '(' && str[i] == ')') || (st.top() == '{' && str[i] == '}') || (st.top() == '[' && str[i] == ']'))
                    {
                        st.pop();//���������������ǰ���ջ���ǲ��Ƕ�Ӧ��������
                    }
                    else return false;//����������ʱջ������Ӧ��ֱ���жϲ�ƥ��
                }
                else return false;//����������ʱջ�ǿյ���ֱ�ӿ��жϲ�ƥ��
            }
        }
    }
    return true;//forѭ��˳��������ȫ��ƥ��ɹ�
}
int main()
{
    int n;
    cin >> n;
    string s;
    while(n--)
    {
        cin >> s;
        if(check(s) == false) cout << "No" <<endl;
        else cout << "Yes" <<endl;
    }
    return 0;
}
