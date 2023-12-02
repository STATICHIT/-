#include<bits/stdc++.h>
using namespace std;

//结点结构体
struct Node
{
    int data;
    struct Node * next;
};

//尾插法创建带头结点的链表
struct Node* CreatList(int n)
{
    struct Node *p,*q;
    struct Node * HeadList=(struct Node*)malloc(sizeof(struct Node));
    HeadList->next=NULL;//L为头结点
    p=HeadList;
    while(n--)
    {
        q=(struct Node*)malloc(sizeof(struct Node));
        cin>>q->data;
        q->next=NULL;
        p->next=q;
        p=q;//p始终指向表尾，每次插入元素于表尾
    }
    return HeadList;
}

//寻找指定元素在链表中的位置
int find_(struct Node * L,int x)
{
    struct Node *p;
    p=L->next;
    int sign =0;
    while(p!=NULL)
    {
        sign++;
        if(p->data == x)
            return sign;
        p=p->next;
    }
    return 0;
}

//在指定位置处插入指定元素
void insertNode(struct Node* L,int x,int i)
{
    int k=0;
    struct Node *p,*q;
    p=(struct Node*)malloc(sizeof(struct Node));
    //先把待插入结点创好
    q=(struct Node*)malloc(sizeof(struct Node));
    q->data=x;
    q->next=NULL;
    p=L;
    if(i <= 0)
    {
        q->next=p->next;
        p->next=q;
        return ;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
            k++;
            if(k == i)
            {
                q->next=p->next;
                p->next=q;
                return ;
            }
        }
        //如果到最后还没有找到第i个元素，插入尾部
        q->next=p->next;
        p->next=q;
        return ;
    }
}

//打印链表
void PrintList(struct Node *L)
{
    L=L->next;
    while(L!=NULL)
    {
        cout<<L->data<<" ";
        L=L->next;
    }
    cout<<endl;
}

//计算链表中指定元素个数
int CountNode(struct Node* L,int x)
{
    struct Node *p;
    int cnt=0;
    p=L->next;
    while(p!=NULL)
    {
        if(p->data==x)
            cnt++;
        p=p->next;
    }
    return cnt;
}

int main()
{
    cout<<"请输入链表长度及其元素"<<endl;
    int n;
    cin>>n;//输入链表长度
    struct Node* List;
    List=CreatList(n);

    cout<<"请输入待查找的元素值"<<endl;
    int sign,x;
    cin>>x;//输入待查找元素
    sign=find_(List,x);
    if(sign == 0)cout<<"链表中不存在元素。"<<x<<endl;
    else cout<<x<<"是链表中的第"<<sign<<"个元素。"<<endl;

    cout<<"请输入需要插入的元素xx和位置ii"<<endl;
    int xx,ii;
    cin>>xx>>ii;
    insertNode(List,xx,ii);
    cout<<"完成插入操作后的链表如下"<<endl;
    PrintList(List);


    int ss,nn;
    cout<<"请输入需要查询个数的元素值"<<endl;
    cin>>ss;
    nn=CountNode(List,ss);
    cout<<"链表中有"<<nn<<"个"<<ss<<"。"<<endl;

    return 0;
}
