#include<bits/stdc++.h>
using namespace std;

struct node
{
    int num;
    struct node * next;
};
//��������ͷ������
struct node * creat(int n)//nΪ���������ݸ���
{
    int data;
    struct node * head,*p,*q;
    head = new node;
    head -> next=NULL;
    p=head;//ָ��ͷ���
    while(n--)
    {
        cin>>data;
        q = (struct node*)malloc(sizeof(struct node));
        q -> num = data;//�½�������
        q -> next = NULL;//���½����Զָ��NULL
        p -> next = q;//��������
        p=q;//pָ�����½��
    }
    return head;
}
void fun(struct node * head)//����С���ŵ���һ��ȥ
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
