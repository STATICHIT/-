/*
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;           //������
    struct Node *next; //ָ����
};

///��������
struct Node * creatList()
{
    struct Node *headNode = (struct Node *)malloc(sizeof(struct Node));
    //headNode��Ϊ�˽ṹ�����
    //����ʹ��ǰ�����ȳ�ʼ��
    //headNode -> data=1;(���Ե�û��Ҫ)
    headNode -> next=NULL;
    return headNode;
}

///�������
struct Node * creatNode(int data)
{
 struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
 newNode -> data =data;
 newNode -> next =NULL;//���½���ָ����Ϊ��
 return newNode;
}

///��ӡ����
void printList(struct Node * headNode)
{
    struct Node * pMove=headNode -> next;
    while(pMove)
    {
        printf("%d ",pMove -> data);
        pMove=pMove -> next;
    }
    printf("\n");
}

///������
void insertNodeByHead(struct Node * headNode,int data)
{
    //�ȴ�������Ľ��
    struct Node * newNode=creatNode(data);
    newNode -> next=headNode -> next;//�½��ָ��ԭ����ͷ����һ��
    headNode -> next=newNode;//ԭ����ͷ��ָ���½��
}

///ɾ�����
void deleteNodeByAppoin(struct Node * headNode,int posData)
{
    struct Node * posNode =headNode -> next;
    struct Node * posNodeFront=headNode;
    if(posNode == NULL)
        printf("�޷�ɾ��������Ϊ��\n");
    else
    {
        while(posNode -> data != posData)
        {
            posNodeFront=posNode;
            posNode=posNodeFront -> data;
        }
        posNodeFront -> next =posNode -> next;
        free(posNode);//�ͷű�ɾ�����ָ����λ���ڴ�
    }
}



int main()
{
    int i,n,data;
    scanf("%d",&n);
    //��������
    struct Node * list=creatList(),*q,*p;
    //�������
    q=list;
    for(i=0;i<n;i++)
        {
            scanf("%d",&data);
            p=creatNode(data);
            q->next=p;
            q=p;
        }

    printList(list);

    return 0;
}
*/


/*
//��̬ģ������
#include<stdio.h>
int main()
{
    int data[101],right[101];
    int i,n,t,len;
    scanf("%d",&n);
    //��ʼ��data����
    for(i=1;i<=n;i++)
        scanf("%d",&data[i]);
    len=n;
    //��ʼ��right�������
    for(i=1;i<=n;i++)
    {
        if(i!=n)
            right[i]=i+1;
        else
            right[i]=0;//���һ�������ұ�û��Ԫ��
    }
    len++;
    //����Ҫ��������
    scanf("%d",&data[len]);
    //�������ͷ����ʼ����
    t=1;
    while(t!=0)//t=0ʱ�������һ����
    {
        if(data[right[t]]>data[len])
        {
            right[len]=right[t];//�²���������һ�����ڵ�ǰ������һ�������
            right[t]=len;//��ǰ������һ������ž����²������ı��
            break;//������ɾͿ�������ѭ����
        }
        t=right[t];//����while��t��=0������Ӷ���������
    }
    t=1;
    while(t!=0)
    {
        printf("%d ",data[t]);
        t=right[t];
    }
    return 0;
}

*/


/*
#include<stdio.h>
#include<string.h>

struct Node
{
    int data;
    struct Node *next;
};

//��������
struct Node *creatList()
{
    struct Node *headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next=NULL;
    return headNode;
}

//�������
struct Node * creatNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

//��ӡ����
void printList(struct Node * headNode)
{
    struct Node * pMove=headNode -> next;
    while(pMove)
    {
        printf("%d ",pMove->data);
        pMove=pMove->next;
    }
    printf("\n");
}

//������
void insertNodeByHead(struct * headNode,int data)
{
    struct Node * newNode=creatNode(data);
    newNode->next=headNode->next;
    headNode->next=newNode;
}

//ɾ�����
void deleteNodeByAppoin(struct Node * headNode,int posData)
{
    struct Node * posNode =head->next;
    struct Node * posNodeFront=headNode;
    if(posNode==NULL)
        printf("�޷�ɾ��������Ϊ��\n");
    else
    {
        while(pos->data!=posData)
        {
            posNodeFront=posNode;
            posNode=posNodeFront->next;
        }
        posNodeFront->next=posNode->next;
        free(posNode)��
    }
}

int main()
{
    int n,data;
    scanf("%d",&n);
    //��������
    struct Node* list=creatList(),*p,*q;
    //�������
    q=list;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        p=creatNode(data);
        q->next=p;
        q=p;
    }
    printList(list);
    return 0;
}
*/

#include<stdio.h>
#include<string.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Node * creat(int n)
{
    struct Node * headNode,*p,*q;
    headNode=(struct Node*)malloc(sizeof(struct Node));
    headNode->next=NULL;
    p=headNode;
    while(n--)
    {
        q=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&q->data);
        q->next=NULL;
        p->next=q;
        p=q;
    }
    return headNode;
};

int fun(struct Node *list,int e)
{
    int cnt=0;
    while(list)
    {
        if(list->data==e)
            cnt++;
        list=list->next;
    }
    return cnt;
}

void printList(struct Node * List)
{
    List=List->next;
    while(List)
    {
        printf("%d ",List->data);
        List=List->next;
    }
    printf("\n");
}
int main()
{
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    int n;
    scanf("%d",&n);
    head=creat(n);
    printList(head);
    int s=fun(head,3);
    printf("������3��Ԫ�ظ���Ϊ%d��\n",s);
    return 0;
}
