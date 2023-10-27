#include<stdio.h>
#include<stdlib.h>
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
    head = (struct node*)malloc(sizeof(struct node));
    head -> next=NULL;
    p=head;//指向头结点
    while(n--)
    {
        scanf("%d",&data);
        q = (struct node*)malloc(sizeof(struct node));
        q -> num = data;//新结点的数据
        q -> next = NULL;//最新结点永远指向NULL
        p -> next = q;//连接起来
        p=q;//p指向最新结点
    }
    return head;
}
//插入操作
void in(struct node * head,int data)
{
    struct node * newNode =(struct node *)malloc(sizeof(struct node));
    newNode->num =data;
    newNode->next=NULL;
    struct node * Move=head->next;
    if(data <= Move->next->num)//如果插入数比第一个数还小
    {
        newNode->next=Move->next;
        Move->next=newNode;
    }
    else
    {
        while(Move != NULL)
        {
            if(data>Move->num&&data<Move->next->num)//如果插入数在中间
            {
                newNode->next=Move->next;
                Move->next=newNode;
                break;
            }
            Move=Move->next;
            if(Move->next==NULL&&data>Move->num)//如果插入数比最后一个还大
            {
                Move->next=newNode;
                break;
            }
        }
    }
}
void print(struct node * head)//从第二个结点开始输出的自定义功能函数
{
    struct node * pMove;
    pMove=(struct node *)malloc(sizeof(struct node));
    pMove=head->next->next;
    while(pMove!=NULL)
    {
        printf("%d ",pMove->num);
        pMove=pMove->next;
    }
    printf("\n");
}
int main()
{
    int n,dataa;
    struct node * list;
    scanf("%d",&n);
    list=creat(n);
    dataa=list->next->num;
    //printf("%d",data);
    in(list,dataa);
    print(list);
    return 0;
}
