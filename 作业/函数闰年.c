//题目：问题 K: 闰年
//描述
//相信同学们对这题目已经很熟悉了，就不解释了，但是这道题目要用函数做哦！
//规定要用到
//int isLeap(int year){
//返回一个整型数据 }
//如果不使用以上函数则会出现编译错误！！
//
//格式
//输入格式
//输入一个年份   输入有多组
//输出格式
//是闰年则输出yes，否则输出no
#include<stdio.h>
void main()
{
    int N;
    int isLeap(int N);//一定要记得写即将使用的函数！！
    while(~scanf("%d",&N))
      {if(isLeap(N)==1)
        {printf("yes\n");}
        if(isLeap(N)==0)//调用函数时不用带上数据类型符号
                        //即写isLeap(N),而不是int isLeap(N)
            {printf("no\n");}

}}
int isLeap(int N)
{
    if(N%4!=0)
        return(0);
    else
        if(N%4==0&&N%100!=0)//if中不等于是！=而不是！==
        return(1);
    else
        if(N%400==0)
        return(1);
    else
        return(0);

}
