#include<bits/stdc++.h>
using namespace std;

int n=0;
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode;

BiTNode * creatTree(BiTNode* root)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        root = NULL;
    else
    {
        root = (BiTNode*)malloc(sizeof(BiTNode));
        root->data = ch;
        root->lchild = creatTree(root->lchild);//构造左子树
        root->rchild = creatTree(root->rchild);//构造右子树
    }
    return root;
}

void preOrder(BiTNode *T)
{
    if(T == NULL)
    {
        return;
    }
    cout<<T->data;
    preOrder(T->lchild);
    preOrder(T->rchild);
}

void inOrder(BiTNode *T)
{
    if(T == NULL)return;
    inOrder(T->lchild);
    cout<<T->data;
    inOrder(T->rchild);
}

void postOrder(BiTNode *T)
{
    if(T == NULL)return;
    postOrder(T->lchild);
    postOrder(T->rchild);
    cout<<T->data;
}
void left(BiTNode *T)//前序遍历每个点检查无左右子树的结点即为叶子结点
{
    if(T == NULL)return;
    if(T->lchild == NULL && T->rchild == NULL)
        n++;
    left(T->lchild);
    left(T->rchild);
}
int main()
{
    BiTNode *BiTree;
    BiTree=creatTree(BiTree);
    if(BiTree == NULL)cout<<"0";
    else
    {
        preOrder(BiTree);
        cout<<endl;
        inOrder(BiTree);
        cout<<endl;
        postOrder(BiTree);
        cout<<endl;
        left(BiTree);
        cout<<n;
    }
    return 0;
}
