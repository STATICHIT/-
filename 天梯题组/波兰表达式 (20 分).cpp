/*
#include <bits/stdc++.h>
using namespace std;

double f()
{
    string s;
    cin >> s;
    //cout<<"[[[[ "<<s<<" ]]]]"<<endl;
    if(s == "+")
    {
        return f() + f();
    }
    else if(s == "-")
    {
        return f() - f();
    }
    else if(s == "*")
    {
        return f() * f();
    }
    else if(s =="/")
    {
        return f() / f();
    }
    else
    {
        //atof��������һ���ַ���ת��Ϊ������
        return atof(s.c_str());
    }//string.c_str()��������һ��ָ������C�ַ���
    //��ָ�볣��, �����뱾string����ͬ
}
int main()
{
    //��Ϊ�пո�������һ��һ�����������
    double ans = f();
    printf("%.6lf", ans);
}
*/

#include<bits/stdc++.h>
using namespace std;

double f()
{
    string s;
    cin>>s;

    if(s == "+")
    {
        return f()+f();
    }
    else if(s == "-")
    {
        return f()-f();
    }
    else if(s == "*")
    {
        return f()*f();
    }
    else if(s == "/")
    {
        return f()/f();
    }
    else//���ǼӼ��˳�����Ϊ����
    {
        return atof(s.c_str());
    }
}
int main()
{
    double ans;
    ans=f();
    printf("%.6lf",ans);
}
