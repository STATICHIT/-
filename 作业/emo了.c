///Ҫ�����������
///1.�����������һ��������
///2.�������ȵ�һ����С
///3.���������м�
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node*next;
};
struct node*creat(int n)//�����¼��(����ͷ�ڵ�)
{
    struct node*head,*p,*q;
    head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    q = head;//qָ�����һ�����
    for(int i = 1; i<=n; i++)
    {
        //p���ڿ����½��
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

    ///����¼������
    list = creat(n);
    //printf("%d",list->next->next->num);//������˵������ı��û�����⣬�����ǲ��뺯��������

    ///������
    int data = list->next->num;
    ///�������
    struct node * newNode=(struct node *)malloc(sizeof(struct node));
    newNode -> num =data;
    newNode -> next =NULL;//���½���ָ����Ϊ��

    //printf("ѡ�еĴ�������Ϊ%d\n",data);
    if(data<list->next->next->num)
    {
        sign=1;
    }
    else
    {
        struct node * Move=list -> next;
        //printf("��һ����%d\n",Move->num);//���Move��ʼֵ
        while(Move!=NULL)
        {
            //printf("### %d\n",Move -> num);//������
            if(Move -> num < data&&Move->next->num>data)
            {
                //printf("%d����%d��%dС��%d�����ҽ�����\n",Move -> next-> num,newNode -> num,Move->num,newNode->num);

                newNode -> next=Move -> next;//�½��ָ��ԭ����ͷ����һ��
                Move -> next=newNode;//ԭ����ͷ��ָ���½��
                break;
            }
            Move=Move -> next;
            if(Move->next==NULL&&data>Move->num)
            {
                //printf("�ҽ�������\n");
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
