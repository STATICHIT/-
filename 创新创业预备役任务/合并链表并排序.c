#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node * next;
};

struct node * creat(int n)
{
 struct node * head,*p,*q;
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
void print(struct node * head)
{
    struct node * pMove;
    pMove=(struct node *)malloc(sizeof(struct node));
    pMove=head->next;
    while(pMove!=NULL)
    {
        printf("%d ",pMove->num);
        pMove=pMove->next;
    }
    printf("\n");
}

struct node * fun(struct node * head1,struct node * head2)
{
    struct node * Move;
    Move=head1->next;
    while(Move->next!=NULL)
    {
        Move=Move->next;
    }
    Move->next=head2->next;
    Move=head1;//重新让Move指向表头
    return Move;
}
void funnn(struct node * head)
{
    int temp;
    struct node *i,*j;
    for(i=head->next;i!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(j->num > i->num)
            {
                temp = j->num;
                j->num = i->num;
                i->num = temp;
            }
        }
    }
}
int main()
{
    int m,n;//n接到m后
    struct node *mlist,*nlist,*list;
    scanf("%d",&m);
    mlist=creat(m);
    scanf("%d",&n);
    nlist=creat(n);
    list=fun(mlist,nlist);
    funnn(list);
    print(list);
    return 0;
}
