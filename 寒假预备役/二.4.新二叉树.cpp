#include<bits/stdc++.h>
using namespace std;
int n;
struct Tree
{
    char root;
    struct Tree * left;
    struct Tree * right;
}T[1000];
void fun(struct Tree * head)//前序遍历输出
{
    if(head == NULL)
        return;
    printf("%c",head->root);//输出根
    if(head->left!=NULL)//判断左子树是否存在
        fun(head->left);//递归
    if(head->right!=NULL)//判断右子树是否存在
        fun(head->right);//递归
}
struct Tree * Creat(int n)
{
    struct Tree * head;
    for(int i=1;i<=n;i++)
    {
        char str[4];
        cin>>str;
        T[str[0]].root=str[0];//在数组中str【】自动转化为对应ascll码
        T[str[1]].root=str[1];//每个结点的根为自己
        T[str[2]].root=str[2];
        if(i == 1)
            head=&T[str[0]];//因为T【】是个结构体数组元素，而不是指针，所以不能直接head=T【】，而应该head=&T【】
        if(str[1]=='*')
           T[str[0]].left=NULL;
        else
           T[str[0]].left=&T[str[1]];//加&的原因同上
        if(str[2]=='*')
           T[str[0]].right=NULL;
        else
           T[str[0]].right=&T[str[2]];//加&的原因同上
    }
    return head;
}
int main()
{
    cin>>n;
    getchar();
    struct Tree * head;//创建根结点，便于使各个结点练起来
    head=Creat(n);//建树
    fun(head);//前序遍历输出
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
    printf("%c",T->root);//输出根
    if(T->left!=NULL)//判断左子树是否存在
        fun(T->left);//递归
    if(T->right!=NULL)//判断右子树是否存在
        fun(T->right);//递归
}
int main()
{
    cin>>n;
    getchar();
    struct Tree *head;//创建根结点，便于使各个结点练起来
    //建树
    for(int i=1;i<=n;i++)
    {
        char str[4];
        scanf("%s",str);
        if(i == 1)
            head=&T[str[0]];//头结点即根结点，因为T【】是个结构体数组元素，而不是指针，所以不能直接head=T【】，而应该head=&T【】
        T[str[0]].root=str[0];//在数组中str【】自动转化为对应ascll码
        T[str[1]].root=str[1];//每个结点的根为自己
        T[str[2]].root=str[2];
        if(str[1]!='*')
            T[str[0]].left=&T[str[1]];//加&的原因同上
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
