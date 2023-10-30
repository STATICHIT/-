
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Link
{
    int data;
    struct Link *next;
}link;
int main()
{
    link *p=(link*)malloc(sizeof(link));
    link *t=p;
    int n;
    scanf("%d",&n);
    for(int i=1;i<n+1;i++)    //造表
    {
        link *a=(link*)malloc(sizeof(link));
        scanf("%d",&a->data);
        a->next=NULL;
        t->next=a;
        t=t->next;
    }
    t=p;
    int min=t->data,ff=1;         //找最小
    for(int i=1;i<n+1;i++)
    {
        t=t->next;
        if(min>t->data){
            min=t->data;
            ff=i;
        }
    }
    t=p;
    link *s=p->next,*k;
    for(int i=1;i<n+1;i++)
    {
        t=t->next;
        if(i==ff-1)
        {
            k=t->next;
            t->next=t->next->next;
            k->next=s;
            p->next=k;
        }
    }
    t=p;
    for(int i=1;i<n+1;i++)         //输出表
    {
        t=t->next;
        if(i!=n)
        printf("%d ",t->data);
        else printf("%d",t->data);
    }
    return 0;
}
