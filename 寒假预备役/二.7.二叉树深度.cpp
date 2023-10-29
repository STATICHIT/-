
#include<bits/stdc++.h>
using namespace std;
int n,ans;
struct Tree
{
    struct Tree * left;
    struct Tree * right;
} T[100000];
void dfs(struct Tree * x,int deep)//当前结点和深度
{
    ans=max(ans,deep);
    if(x->left!=NULL)
        dfs(x->left,deep+1);
    if(x->right!=NULL)
        dfs(x->right,deep+1);
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int a,b;
        cin>>a>>b;
        if(a!=0)
            T[i].left=&T[a];
        else
            T[i].left=NULL;
        if(b!=0)
            T[i].right=&T[b];
        else
            T[i].right=NULL;
    }
    dfs(&T[1],1);//根结点深度为1
    cout<<ans;
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
int n;
struct Tree
{
    struct Tree * left;
    struct Tree * right;
    int deep;
} T[1000000];
struct Tree * Creat(int n)
{
    struct Tree * head;
    for(int i=1; i<=n; i++)
    {
        int a,b;
        cin>>a>>b;
        if(i == 1)
        {
            head=&T[i];//因为T【】是个结构体数组元素，而不是指针，所以不能直接head=T【】，而应该head=&T【】
            if(a==0&&b==0)//特判一手空树
            {
                T[i].deep=0;
                T[i].left=NULL;
                T[i].right=NULL;
                return head;
            }
            T[i].deep=1;
        }
        if(a==0)
            T[i].left=NULL;
        else
            T[i].left=&T[a];//加&的原因同上
        if(b==0)
            T[i].right=NULL;
        else
            T[i].right=&T[b];//加&的原因同上
    }
    return head;
}
void dfs(struct Tree * x,int s)
{
    if(x->left!=NULL)
    {
        x->left->deep=s+1;
        dfs(x->left,s+1);
    }
    if(x->right!=NULL)
    {
        x->right->deep=s+1;
        dfs(x->right,s+1);
    }

}
int main()
{
    cin>>n;
    struct Tree * head;//创建根结点，便于使各个结点练起来
    head=Creat(n);//建树
    dfs(head,1);
    int m=T[1].deep;
    for(int i=1; i<=n; i++)
    {
        if(T[i].deep>m)
            m=T[i].deep;
    }
    cout<<m;
    return 0;
}
*/
