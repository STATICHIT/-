
#include<bits/stdc++.h>
using namespace std;
int n,ans;
struct Tree
{
    struct Tree * left;
    struct Tree * right;
} T[100000];
void dfs(struct Tree * x,int deep)//��ǰ�������
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
    dfs(&T[1],1);//��������Ϊ1
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
            head=&T[i];//��ΪT�����Ǹ��ṹ������Ԫ�أ�������ָ�룬���Բ���ֱ��head=T��������Ӧ��head=&T����
            if(a==0&&b==0)//����һ�ֿ���
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
            T[i].left=&T[a];//��&��ԭ��ͬ��
        if(b==0)
            T[i].right=NULL;
        else
            T[i].right=&T[b];//��&��ԭ��ͬ��
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
    struct Tree * head;//��������㣬����ʹ�������������
    head=Creat(n);//����
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
