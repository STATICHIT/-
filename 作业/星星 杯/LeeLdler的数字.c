///珍爱生命，远离赌博
//两副牌一个战场，需要两个队列一个栈
#include<stdio.h>
struct queue
{
    int data[1000001];
    int head;
    int tail;
};
struct stack
{
    int data[13];
    int top;
};
int main()
{
    struct queue q1,q2;//模拟两副手牌
    struct stack s;
    int book[13];//用于标记哪些牌已经在桌上

    ///初始化队列
    q1.head=1;q1.tail=1;
    q2.head=1;q2.tail=1;
    ///初始化栈
    s.top=0;
    ///初始化用来标记的数组
    for(i=1;i<13;i++)
        book[i]=0;

    return 0;
}
