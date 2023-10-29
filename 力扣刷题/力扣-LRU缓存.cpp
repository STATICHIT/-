#include<bits/stdc++.h>
using namespace std;

int MaxLen;
map<int,int>kv;
struct node
{
    int key;
    struct node * next;
    struct node * pre;
};
struct node *head,*tail;
void LRUCache(int capacity)
{
    MaxLen=capacity;
    head=(struct node*)malloc(sizeof(struct node));
    tail=(struct node*)malloc(sizeof(struct node));
    head->next=tail;
    head->pre=NULL;
    head->key=-1;
    tail->pre=head;
    tail->next=NULL;
    tail->key=-1;
}

//把指定元素加到链表头部
void add(int keys)
{
    struct node *up=(struct node*)malloc(sizeof(struct node));
    struct node*z=(struct node*)malloc(sizeof(struct node));
    up=head;
    z->key=keys;
    z->next=up->next;
    z->pre=up;
    up->next=z;
}

//弹出最旧的元素，即队尾元素
void remove_key()
{
    int target=tail->pre->key;
    //cout<<"被删除key为"<<target<<endl;
    kv.erase(target);
    tail->pre=tail->pre->pre;
    tail->pre->next=tail;
}

//删除指定元素,但不删除kv对
void remove_what(int key)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p=head->next;
    while(p->key!=key)
    {
        p=p->next;
    }
    p->next->pre=p->pre;
    p->pre->next=p->next;
}
//更新元素位置
void update(int keys)
{
    remove_what(keys);
    add(keys);
}
//查找关键字，返回value，若不存在1返回-1
int get(int keys)
{
    int target=-1;
    struct node *p,*q;
    p=head->next;
    while(p->key!=-1)
    {
        if(p->key==keys)
        {
            target=kv[keys];
            update(keys);
            break;
        }
        p=p->next;
    }
    //cout<<"target="<<target<<endl;
    return target;
}
//加入数据
void put(int key, int value)
{
    int n=0;
    if(kv[key]==NULL)
    {
        kv[key]=value;
    }
    else
    {
        remove_what(key);
        kv.erase(key);
        kv[key]=value;
    }
    struct node*p,*q;
    p=head->next;
    while(p->key!=-1)
    {
        n++;
        p=p->next;
    }
    if(n>=MaxLen)
        remove_key();
    add(key);
}

void print(struct node *head)
{
    struct node *p=head->next;
    while(p->key!=-1)
    {
        cout<<p->key<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{

    LRUCache(2);
    put(1,1);
    print(head);
    put(2,2);
    print(head);
    int a=get(1);
    cout<<"得到的是："<<a<<endl;
    print(head);
    put(3,3);
    print(head);
    int b=get(2);
    cout<<"得到的是："<<b<<endl;
    print(head);
    put(4,4);
    print(head);
    int c=get(1);
    cout<<"得到的是："<<c<<endl;
    print(head);
    int d=get(3);
    cout<<"得到的是："<<d<<endl;
    print(head);
    int e=get(4);
    cout<<"得到的是："<<e<<endl;
    print(head);

    /*
    LRUCache(2);
    put(2,1);
    print(head);
    put(1,1);
    print(head);
    put(2,3);
    print(head);
    put(4,1);
    print(head);
    int e=get(1);
    cout<<"得到的是："<<e<<endl;
    print(head);
    int g=get(2);
    cout<<"得到的是："<<g<<endl;
    print(head);
    */
    return 0;
}
