#include<bits/stdc++.h>
using namespace std;

struct Tree
{
    char data;
    struct Tree *left,*right;
}T[1000];

int n;
struct Tree * creat(int n)
{
    struct Tree * head;
    for(int i=1;i<=n;i++)
    {
        char str[4];
        cin>>str;
        T[str[0]].data=str[0];//��������str�����Զ�ת��Ϊ��Ӧascll��
        T[str[1]].data=str[1];//ÿ�����ĸ�Ϊ�Լ�
        T[str[2]].data=str[2];
        if(i == 1)
            head=&T[str[0]];//��ΪT�����Ǹ��ṹ������Ԫ�أ�������ָ�룬���Բ���ֱ��head=T��������Ӧ��head=&T����
        if(str[1]=='*')
           T[str[0]].left=NULL;
        else
           T[str[0]].left=&T[str[1]];//��&��ԭ��ͬ��
        if(str[2]=='*')
           T[str[0]].right=NULL;
        else
           T[str[0]].right=&T[str[2]];//��&��ԭ��ͬ��
    }
    return head;
}

void fun(struct Tree *T)
{
    if(T==NULL)
        return ;
    printf("%c ",T->data);

    if(T->left!=NULL)
        fun(T->left);
    if(T->right!=NULL)
        fun(T->right);
}
int main()
{
    cin>>n;
    struct Tree * head;//��������㣬����ʹ�������������
    head=creat(n);//����
    fun(head);//ǰ��������

    return 0;
}
