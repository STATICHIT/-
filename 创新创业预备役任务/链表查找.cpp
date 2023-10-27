#include<bits/stdc++.h>
using namespace std;

struct node
{
    int num;
    struct node * next;
};
//创建带表头的链表
struct node * creat(int n)//n为链表内数据个数
{
    int data;
    struct node * head,*p,*q;
    head = new node;
    head -> next=NULL;
    p=head;//指向头结点
    while(n--)
    {
        cin>>data;
        q = (struct node*)malloc(sizeof(struct node));
        q -> num = data;//新结点的数据
        q -> next = NULL;//最新结点永远指向NULL
        p -> next = q;//连接起来
        p=q;//p指向最新结点
    }
    return head;
}
void fun(struct node * head)//找最小并放到第一个去
{
    struct node * Move;
    Move=(struct node*)malloc(sizeof(struct node));
    Move=head->next;
    int min=Move->num;
    while(Move!=NULL)
    {
        if(min>Move->num)
        {
            min=Move->num;
        }
        Move=Move->next;
    }
    Move=head->next;
    if(min == Move->num)
        return ;
    else
    {
        struct node * p;
        p=(struct node*)malloc(sizeof(struct node));
        while(Move!=NULL)
        {
           if(Move->next->num == min)
            {
              p=Move->next;
              Move->next=Move->next->next;
              p->next=head->next;
              head->next=p;
              break;
            }
         Move=Move->next;
        }
    }
}
void print(struct node * head)
{
    struct node * pMove;
    pMove=(struct node *)malloc(sizeof(struct node));
    pMove=head->next;
    while(pMove!=NULL)
    {
        cout<<pMove->num<<" ";
        pMove=pMove->next;
    }
    cout<<endl;
}
int main()
{
    int n,dataa;
    struct node * list;
    cin>>n;
    list=creat(n);
    fun(list);
    print(list);
    return 0;
}
