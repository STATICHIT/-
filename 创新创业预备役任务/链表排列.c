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
void fun(struct node * head)
{
    int temp;
    struct node *i,*j;
    for(i=head->next;i!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(j->num < i->num)
            {
                temp = j->num;
                j->num = i->num;
                i->num = temp;
            }
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
        printf("%d ",pMove->num);
        pMove=pMove->next;
    }
    printf("\n");
}
int main()
{
    struct node * list;
    int n;
    scanf("%d",&n);
    getchar();
    list=creat(n);
    fun(list);
    print(list);
    return 0;
}
