///�䰮������Զ��Ĳ�
//������һ��ս������Ҫ��������һ��ջ
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
    struct queue q1,q2;//ģ����������
    struct stack s;
    int book[13];//���ڱ����Щ���Ѿ�������

    ///��ʼ������
    q1.head=1;q1.tail=1;
    q2.head=1;q2.tail=1;
    ///��ʼ��ջ
    s.top=0;
    ///��ʼ��������ǵ�����
    for(i=1;i<13;i++)
        book[i]=0;

    return 0;
}
