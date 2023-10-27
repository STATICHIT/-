///要考虑三种情况
///1.插入数比最后一个数还大
///2.插入数比第一个还小
///3.插入数在中间
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node*next;
};
struct node*creat(int n)//链表的录入(不带头节点)
{
    struct node*head,*p,*q;
    head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    q = head;//q指向最后一个结点
    for(int i = 1; i<=n; i++)
    {
        //p用于开辟新结点
        p = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&p->num);
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return head;
}
int main()
{
    int n,sign=0;
    scanf("%d",&n);
    struct node * list;

    ///数据录入链表
    list = creat(n);
    //printf("%d",list->next->next->num);//正常！说明下面的表达没有问题，可能是插入函数有问题

    ///插入结点
    int data = list->next->num;
    ///创建结点
    struct node * newNode=(struct node *)malloc(sizeof(struct node));
    newNode -> num =data;
    newNode -> next =NULL;//最新结点的指针域为空

    //printf("选中的待插入数为%d\n",data);
    if(data<list->next->next->num)
    {
        sign=1;
    }
    else
    {
        struct node * Move=list -> next;
        //printf("第一个数%d\n",Move->num);//检查Move初始值
        while(Move!=NULL)
        {
            //printf("### %d\n",Move -> num);//检查遍历
            if(Move -> num < data&&Move->next->num>data)
            {
                //printf("%d大于%d且%d小于%d所以我进来了\n",Move -> next-> num,newNode -> num,Move->num,newNode->num);

                newNode -> next=Move -> next;//新结点指向原来表头的下一个
                Move -> next=newNode;//原来表头就指向新结点
                break;
            }
            Move=Move -> next;
            if(Move->next==NULL&&data>Move->num)
            {
                //printf("我进来啦！\n");
                Move->next=newNode;
                break;
            }
        }
    }
    if(sign==0)
    {
        int f=n+1;
        while(f--)
        {
            list=list->next;
            if(f<n)
            {
                printf("%d ",list->num);
            }
        }
    }
    else if(sign == 1)
    {
        int f=n+1;
        while(f--)
        {
            list=list->next;
            printf("%d ",list->num);
        }
    }
    printf("\n");
return 0;
}
