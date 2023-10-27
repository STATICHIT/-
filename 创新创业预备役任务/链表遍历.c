#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node * next;
};

struct node * creat(int n)
{
 struct node * head,*q,*p;
 head=(struct node *)malloc(sizeof(struct node));
 head->next=NULL;
 p=head;
 char s[1000];
 int i=0;
 scanf("%s",s);
 while(n--)
 {
     q=(struct node *)malloc(sizeof(struct node));
     q->num=s[i++]-'0';
     q->next=NULL;
     p->next=q;
     p=q;
 }
 return head;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        int sum=0;
        struct node *list1,*list2,*p,*q;
        scanf("%d",&n);
        list1=creat(n);
        list2=creat(n);
        p=list1->next;
        q=list2->next;
        while(n--)
        {
            //printf("1对应%d，2对应%d\n",p->num,q->num);
            if(p->num == q->num)
                sum++;
            p=p->next;
            q=q->next;
        }
        printf("%d\n",sum);
    }
    return 0;
}
