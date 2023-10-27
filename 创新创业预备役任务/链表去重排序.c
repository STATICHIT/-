#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node * next;
};
struct node *creat(int n)
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

void delet(struct node * head,int data)//删除操作
{
    struct node * posNode=head->next;
    struct node * posNodeFront=head;
    while(posNode!=NULL)
    {
        if(posNode -> num == data)
        {
            posNodeFront->next =posNode->next;
            free(posNode);
            posNode=posNodeFront->next;//删除之后只有当前值后移一位

        }
        else//如果不一样则后移
        {
            posNodeFront=posNode;//后移
            posNode=posNode->next;
        }

    }
}

void fun(struct node * head1,struct node * head2)//去重操作
{
    int sign[1001]= {0},si[1001]= {0};//因为题目没说数据是一位数，所以这里的范围不能只开10！否则会运行错误
    struct node *Move1,*Move2;
    Move1=head1->next;
    Move2=head2->next;
    while(Move1!=NULL)
    {
        sign[Move1->num]++;
        Move1=Move1->next;
    }
    while(Move2!=NULL)
    {
        si[Move2->num]++;
        Move2=Move2->next;
    }
    /*
    Move1=head1;
    Move2=head2;
    */
    for(int i=0; i<1001; i++)
    {
        if(sign[i]>=1&&si[i]>=1)
        {
            for(int j=0; j<sign[i]+si[i]; j++)
            {
                delet(head1,i);
                delet(head2,i);
            }
        }
    }
    //print(head1);print(head2);
}

void fun2(struct node * head)//升序操作
{
    int temp;
    struct node *i,*j;
    for(i=head->next; i!=NULL; i=i->next)
    {
        for(j=i->next; j!=NULL; j=j->next)
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

void fun3(struct node * head)//降序操作
{
    int temp;
    struct node *i,*j;
    for(i=head->next; i!=NULL; i=i->next)
    {
        for(j=i->next; j!=NULL; j=j->next)
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
    int m,n;
    while(~scanf("%d%d",&m,&n))
    {
        struct node *list1,*list2;
        list1=creat(m);//创建a链表
        list2=creat(n);//创建b链表
        //print(list1);print(list2);
        fun2(list1);//升序排链表1
        fun3(list2);//降序排链表2
        //print(list1);print(list2);
        fun(list1,list2);//去重
        print(list1);
        print(list2);
    }
    return 0;
}

