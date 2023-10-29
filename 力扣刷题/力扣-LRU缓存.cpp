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

//��ָ��Ԫ�ؼӵ�����ͷ��
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

//������ɵ�Ԫ�أ�����βԪ��
void remove_key()
{
    int target=tail->pre->key;
    //cout<<"��ɾ��keyΪ"<<target<<endl;
    kv.erase(target);
    tail->pre=tail->pre->pre;
    tail->pre->next=tail;
}

//ɾ��ָ��Ԫ��,����ɾ��kv��
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
//����Ԫ��λ��
void update(int keys)
{
    remove_what(keys);
    add(keys);
}
//���ҹؼ��֣�����value����������1����-1
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
//��������
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
    cout<<"�õ����ǣ�"<<a<<endl;
    print(head);
    put(3,3);
    print(head);
    int b=get(2);
    cout<<"�õ����ǣ�"<<b<<endl;
    print(head);
    put(4,4);
    print(head);
    int c=get(1);
    cout<<"�õ����ǣ�"<<c<<endl;
    print(head);
    int d=get(3);
    cout<<"�õ����ǣ�"<<d<<endl;
    print(head);
    int e=get(4);
    cout<<"�õ����ǣ�"<<e<<endl;
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
    cout<<"�õ����ǣ�"<<e<<endl;
    print(head);
    int g=get(2);
    cout<<"�õ����ǣ�"<<g<<endl;
    print(head);
    */
    return 0;
}
