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
        T[str[0]].data=str[0];//在数组中str【】自动转化为对应ascll码
        T[str[1]].data=str[1];//每个结点的根为自己
        T[str[2]].data=str[2];
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
    struct Tree * head;//创建根结点，便于使各个结点练起来
    head=creat(n);//建树
    fun(head);//前序遍历输出

    return 0;
}
