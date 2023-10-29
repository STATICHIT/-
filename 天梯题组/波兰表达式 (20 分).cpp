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
        //atof函数：把一个字符串转化为浮点数
        return atof(s.c_str());
    }//string.c_str()函数返回一个指向正规C字符串
    //的指针常量, 内容与本string串相同
}
int main()
{
    //因为有空格，所以是一个一个部分输入的
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
    else//不是加减乘除号则为数据
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
