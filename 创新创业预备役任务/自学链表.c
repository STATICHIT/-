/*
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;           //数据域
    struct Node *next; //指针域
};

///创建链表
struct Node * creatList()
{
    struct Node *headNode = (struct Node *)malloc(sizeof(struct Node));
    //headNode成为了结构体变量
    //变量使用前必须先初始化
    //headNode -> data=1;(可以但没必要)
    headNode -> next=NULL;
    return headNode;
}

///创建结点
struct Node * creatNode(int data)
{
 struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
 newNode -> data =data;
 newNode -> next =NULL;//最新结点的指针域为空
 return newNode;
}

///打印链表
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

///插入结点
void insertNodeByHead(struct Node * headNode,int data)
{
    //先创建插入的结点
    struct Node * newNode=creatNode(data);
    newNode -> next=headNode -> next;//新结点指向原来表头的下一个
    headNode -> next=newNode;//原来表头就指向新结点
}

///删除结点
void deleteNodeByAppoin(struct Node * headNode,int posData)
{
    struct Node * posNode =headNode -> next;
    struct Node * posNodeFront=headNode;
    if(posNode == NULL)
        printf("无法删除，链表为空\n");
    else
    {
        while(posNode -> data != posData)
        {
            posNodeFront=posNode;
            posNode=posNodeFront -> data;
        }
        posNodeFront -> next =posNode -> next;
        free(posNode);//释放被删结点所指定的位置内存
    }
}



int main()
{
    int i,n,data;
    scanf("%d",&n);
    //创建链表
    struct Node * list=creatList(),*q,*p;
    //创建结点
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
//静态模拟链表
#include<stdio.h>
int main()
{
    int data[101],right[101];
    int i,n,t,len;
    scanf("%d",&n);
    //初始化data数组
    for(i=1;i<=n;i++)
        scanf("%d",&data[i]);
    len=n;
    //初始化right结点数组
    for(i=1;i<=n;i++)
    {
        if(i!=n)
            right[i]=i+1;
        else
            right[i]=0;//最后一个数的右边没有元素
    }
    len++;
    //输入要插入数啦
    scanf("%d",&data[len]);
    //从链表的头部开始遍历
    t=1;
    while(t!=0)//t=0时到达最后一个数
    {
        if(data[right[t]]>data[len])
        {
            right[len]=right[t];//新插入数的下一结点等于当前结点的下一个结点编号
            right[t]=len;//当前结点的下一个结点编号就是新插入数的编号
            break;//插入完成就可以跳出循环啦
        }
        t=right[t];//其与while（t！=0）搭配从而做到遍历
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

//创建链表
struct Node *creatList()
{
    struct Node *headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next=NULL;
    return headNode;
}

//创建结点
struct Node * creatNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

//打印链表
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

//插入结点
void insertNodeByHead(struct * headNode,int data)
{
    struct Node * newNode=creatNode(data);
    newNode->next=headNode->next;
    headNode->next=newNode;
}

//删除结点
void deleteNodeByAppoin(struct Node * headNode,int posData)
{
    struct Node * posNode =head->next;
    struct Node * posNodeFront=headNode;
    if(posNode==NULL)
        printf("无法删除，链表为空\n");
    else
    {
        while(pos->data!=posData)
        {
            posNodeFront=posNode;
            posNode=posNodeFront->next;
        }
        posNodeFront->next=posNode->next;
        free(posNode)；
    }
}

int main()
{
    int n,data;
    scanf("%d",&n);
    //创建链表
    struct Node* list=creatList(),*p,*q;
    //创建结点
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
    printf("链表中3的元素个数为%d个\n",s);
    return 0;
}
