#include<stdio.h>
#include<stdlib.h>
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
    head = (struct node*)malloc(sizeof(struct node));
    head -> next=NULL;
    p=head;//ָ��ͷ���
    while(n--)
    {
        scanf("%d",&data);
        q = (struct node*)malloc(sizeof(struct node));
        q -> num = data;//�½�������
        q -> next = NULL;//���½����Զָ��NULL
        p -> next = q;//��������
        p=q;//pָ�����½��
    }
    return head;
}
//�������
void in(struct node * head,int data)
{
    struct node * newNode =(struct node *)malloc(sizeof(struct node));
    newNode->num =data;
    newNode->next=NULL;
    struct node * Move=head->next;
    if(data <= Move->next->num)//����������ȵ�һ������С
    {
        newNode->next=Move->next;
        Move->next=newNode;
    }
    else
    {
        while(Move != NULL)
        {
            if(data>Move->num&&data<Move->next->num)//������������м�
            {
                newNode->next=Move->next;
                Move->next=newNode;
                break;
            }
            Move=Move->next;
            if(Move->next==NULL&&data>Move->num)//��������������һ������
            {
                Move->next=newNode;
                break;
            }
        }
    }
}
void print(struct node * head)//�ӵڶ�����㿪ʼ������Զ��幦�ܺ���
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
