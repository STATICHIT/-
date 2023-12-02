#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node * next;
};
struct node * creat(int n)//创建链表（基本操作）
{
    struct node *head,*p,*q;
    head=(struct node *)malloc(sizeof(struct node));
    head->next=NULL;
    p=head;
    while(n--)
    {
        q=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&q->num);
        q->next=NULL;
        p->next=q;
        p=q;
    }
    return head;
}
void fun(struct node* head,int n)//删除操作，将head链表中第n个结点删除
{
    if(n == 1)//如果是删除第一个结点要特殊考虑
        head->next=head->next->next;
    else
    {
        int i=1;
        struct node *p;
        p=head->next;
        while(i<n-1)
        {
            p=p->next;
            i++;
        }
        p->next=p->next->next;
    }
}
void fun2(struct node *head,int n,int m)//插入操作：将m插入head的第n个位置
{
    struct node *p,*q,*t;//t为要插入的结点
    p=head->next;
    int i=1;
    while(i<n-1)//当遍历到指定位置时插入
    {
        p=p->next;
        i++;
    }
    q=p->next;//记录当前结点此时的下一位，便于插入
    t=(struct node*)malloc(sizeof(struct node));//先创建再插入
    t->num=m;//新结点中的值为m
    p->next=t;//让当前结点指向新结点
    t->next=q;//新结点指向当前结点原本的下一位
}
void print(struct node * head,int N,int n)//循环输出
{
    int i=1;
    struct node *p,*q;
    p=head->next;
    while(i<N)//此处包括后面的while里要加1还是减1，手动模拟一下过程很好判断，而且不会错
    {
        p=p->next;
        i++;
    }//遍历到指定位置前不输出
    while(i<n+1)//从指定位置输出一直到链表最后一个结点
    {
        printf("%d ",p->num);
        p=p->next;
        i++;
    }
    //再指向第一个结点，循环输出
    p=head->next;
    i=0;
    while(i<N-1)//输出未输出的数
    {
        printf("%d ",p->num);
        p=p->next;
        i++;
    }
}
int main()
{
    int n,N,m,k,area;
    scanf("%d",&n);
    struct node * list;
    list=creat(n);//创建链表
    scanf("%d",&area);//注意此处输入的area指的是删除的位置，不是删除的数据哦
    if(area!=0)//题目要求输入位置为0时不做操作
    {
        fun(list,area);
    }
    scanf("%d %d",&m,&k);
    fun2(list,m,k);//插入操作
    scanf("%d",&N);
    if(area != 0)//如果前面删除了数据再插入数据，则最终链表长度不变
    {
        print(list,N,n);
    }
    else//如果前面没有删除数据再插入数据，则最终链表长度加1
    {
        print(list,N,n+1);
    }
    return 0;
}
