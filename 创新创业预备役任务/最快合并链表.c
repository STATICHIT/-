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
int main()
{
    int m,n;//n接到m后
    struct node *mlist,*nlist;
    scanf("m=%d",&m);
    mlist=creat(m);
    getchar();
    getchar();
    scanf("n=%d",&n);
    nlist=creat(n);
    print(fun(mlist,nlist));
    return 0;
}
