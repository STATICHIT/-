//二叉树的前序遍历递归算法
//初始条件：二叉树T存在
//操作结果：前序递归遍历
void PreOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    printf("%c",T->data);       //显示结点数据，可以更改为其他对结点的操作
    PreOrderTraverse(T->lchild);//先序遍历左子树
    PreOrderTraverse(T->rchild);//先序遍历右子树
}

//二叉树的中序遍历递归算法
//初始条件：二叉树T存在
//操作结果：中序递归遍历
void InOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    InOrderTraverse(T->lchild);//中序遍历左子树
    printf("%c",T->data);       //显示结点数据，可以更改为其他对结点的操作
    InOrderTraverse(T->rchild);//中序遍历右子树
}

//二叉树的后序遍历递归算法
//初始条件：二叉树T存在
//操作结果：后序递归遍历
void PostOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    PostOrderTraverse(T->lchild);//后序遍历左子树
    PostOrderTraverse(T->rchild);//后序遍历右子树
    printf("%c",T->data);       //显示结点数据，可以更改为其他对结点的操作
}

//按前序输入二叉树中结点的值
//#表示空树，构造二叉链表表示二叉树T
void CreateBiTree(BiTree * T)
{
    TElemType ch;

    scanf("%c",&ch);
    ch=str[index++];

    if(ch == '#')
        *T=NULL;
    else
    {
        *T=(BiTree)malloc(sizeof(BiTNode));
        if(!*T)
            exit(OVERFLOW);
        (*T)->data=ch;              //生成根结点
        CreateBiTree(&(*T)->lchild);//构造左子树
        CreateBiTree(&(*T)->rchild);//构造右子树
    }
}
