#include<bits/stdc++.h>
using namespace std;
#include <stack>//实际上万能头是包括了这个的
stack<char> st;//字符类型的栈
bool check(string str)
{
    int n = str.size();
    if(n % 2 != 0)//如果不是偶数个字符，肯定不匹配
        return false;
    else
    {
        for(int i = 0; i < n; i++)
        {
            if( (str[i] == '(')|| (str[i] == '[')|| (str[i] == '{'))
            {
                st.push(str[i]);//如果是左括号则入栈
            }
            else
            {
                if(!st.empty()) //注意先判断栈空情况
                {
                    if((st.top() == '(' && str[i] == ')') || (st.top() == '{' && str[i] == '}') || (st.top() == '[' && str[i] == ']'))
                    {
                        st.pop();//如果是右括号则检查前面的栈顶是不是对应的左括号
                    }
                    else return false;//遇到右括号时栈顶不对应则直接判断不匹配
                }
                else return false;//遇到右括号时栈是空的则直接可判断不匹配
            }
        }
    }
    return true;//for循环顺利结束，全部匹配成功
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
