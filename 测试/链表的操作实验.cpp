#include<bits/stdc++.h>
using namespace std;

//���ṹ��
struct Node
{
    int data;
    struct Node * next;
};

//β�巨������ͷ��������
struct Node* CreatList(int n)
{
    struct Node *p,*q;
    struct Node * HeadList=(struct Node*)malloc(sizeof(struct Node));
    HeadList->next=NULL;//LΪͷ���
    p=HeadList;
    while(n--)
    {
        q=(struct Node*)malloc(sizeof(struct Node));
        cin>>q->data;
        q->next=NULL;
        p->next=q;
        p=q;//pʼ��ָ���β��ÿ�β���Ԫ���ڱ�β
    }
    return HeadList;
}

//Ѱ��ָ��Ԫ���������е�λ��
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

//��ָ��λ�ô�����ָ��Ԫ��
void insertNode(struct Node* L,int x,int i)
{
    int k=0;
    struct Node *p,*q;
    p=(struct Node*)malloc(sizeof(struct Node));
    //�ȰѴ������㴴��
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
        //��������û���ҵ���i��Ԫ�أ�����β��
        q->next=p->next;
        p->next=q;
        return ;
    }
}

//��ӡ����
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

//����������ָ��Ԫ�ظ���
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
    cout<<"�����������ȼ���Ԫ��"<<endl;
    int n;
    cin>>n;//����������
    struct Node* List;
    List=CreatList(n);

    cout<<"����������ҵ�Ԫ��ֵ"<<endl;
    int sign,x;
    cin>>x;//���������Ԫ��
    sign=find_(List,x);
    if(sign == 0)cout<<"�����в�����Ԫ�ء�"<<x<<endl;
    else cout<<x<<"�������еĵ�"<<sign<<"��Ԫ�ء�"<<endl;

    cout<<"��������Ҫ�����Ԫ��xx��λ��ii"<<endl;
    int xx,ii;
    cin>>xx>>ii;
    insertNode(List,xx,ii);
    cout<<"��ɲ�����������������"<<endl;
    PrintList(List);


    int ss,nn;
    cout<<"��������Ҫ��ѯ������Ԫ��ֵ"<<endl;
    cin>>ss;
    nn=CountNode(List,ss);
    cout<<"��������"<<nn<<"��"<<ss<<"��"<<endl;

    return 0;
}
