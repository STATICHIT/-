#include<bits/stdc++.h>
using namespace std;
int n;
struct Tree
{
    char root;
    struct Tree * left;
    struct Tree * right;
}T[1000];
void fun(struct Tree * head)//ǰ��������
{
    if(head == NULL)
        return;
    printf("%c",head->root);//�����
    if(head->left!=NULL)//�ж��������Ƿ����
        fun(head->left);//�ݹ�
    if(head->right!=NULL)//�ж��������Ƿ����
        fun(head->right);//�ݹ�
}
struct Tree * Creat(int n)
{
    struct Tree * head;
    for(int i=1;i<=n;i++)
    {
        char str[4];
        cin>>str;
        T[str[0]].root=str[0];//��������str�����Զ�ת��Ϊ��Ӧascll��
        T[str[1]].root=str[1];//ÿ�����ĸ�Ϊ�Լ�
        T[str[2]].root=str[2];
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
int main()
{
    cin>>n;
    getchar();
    struct Tree * head;//��������㣬����ʹ�������������
    head=Creat(n);//����
    fun(head);//ǰ��������
    return 0;
}











/*
#include<bits/stdc++.h>
using namespace std;
int n;
struct Tree
{
    char root;
    struct Tree * left;
    struct Tree * right;
}T[1000];

void fun(struct Tree * T)
{
    printf("%c",T->root);//�����
    if(T->left!=NULL)//�ж��������Ƿ����
        fun(T->left);//�ݹ�
    if(T->right!=NULL)//�ж��������Ƿ����
        fun(T->right);//�ݹ�
}
int main()
{
    cin>>n;
    getchar();
    struct Tree *head;//��������㣬����ʹ�������������
    //����
    for(int i=1;i<=n;i++)
    {
        char str[4];
        scanf("%s",str);
        if(i == 1)
            head=&T[str[0]];//ͷ��㼴����㣬��ΪT�����Ǹ��ṹ������Ԫ�أ�������ָ�룬���Բ���ֱ��head=T��������Ӧ��head=&T����
        T[str[0]].root=str[0];//��������str�����Զ�ת��Ϊ��Ӧascll��
        T[str[1]].root=str[1];//ÿ�����ĸ�Ϊ�Լ�
        T[str[2]].root=str[2];
        if(str[1]!='*')
            T[str[0]].left=&T[str[1]];//��&��ԭ��ͬ��
        else
            T[str[0]].left=NULL;
        if(str[2]!='*')
            T[str[0]].right=&T[str[2]];
        else
            T[str[0]].right=NULL;
    }
    fun(head);
    return 0;
}
*/
