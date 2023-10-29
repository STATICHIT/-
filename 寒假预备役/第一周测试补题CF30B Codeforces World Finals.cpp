#include<bits/stdc++.h>
using namespace std;
int dday[13]= {0,31,29,31,30,31,30,31,31,30,31,30,31}; //月份所对应的天数用一个数组储存，方便取用
int dd,mm,yy,bd,bm,by;
bool check(int year,int month,int day)//判断是否是个合法日期
{
    if(month > 12 || month < 1 || day < 1 || day > 31 || year < 1 || year > 99)//题目只保证了 输 入 数 据 中的年不越界
        return false;
    else if(day > dday[month])//包含闰年二月份的判断了
        return false;
    else if(year % 4 !=0 && month == 2 && day>28)
        return false;

    ///如果成功运营到此处说明是个合法日期，在此基础上接着判断是否成年

    //判断是否成年
    if(yy - year > 18)
        return true;
    else if(yy - year == 18 && mm - month > 0)
        return true;
    else if(yy - year == 18 &&mm - month == 0&&dd-day >= 0)
        return true;///else if（）是指不满足yy-year>18之外满足（）的情况，所以一定要加上yy-year==18这个前提条件
    else//除上述三种情况之外都不成年
        return false;
}
int main()
{
    scanf("%d.%d.%d %d.%d.%d",&dd,&mm,&yy,&bd,&bm,&by);
    //枚举六种搭配进行check判断
         if(check(by,bm,bd)== true)cout<<"YES";
    else if(check(by,bd,bm) == true)cout<<"YES";
    else if(check(bm,by,bd) == true)cout<<"YES";
    else if(check(bm,bd,by) == true)cout<<"YES";
    else if(check(bd,by,bm) == true)cout<<"YES";
    else if(check(bd,bm,by) == true)cout<<"YES";
    else cout<<"NO";
    return 0;
}
