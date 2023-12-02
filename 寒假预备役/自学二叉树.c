//��������ǰ������ݹ��㷨
//��ʼ������������T����
//���������ǰ��ݹ����
void PreOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    printf("%c",T->data);       //��ʾ������ݣ����Ը���Ϊ�����Խ��Ĳ���
    PreOrderTraverse(T->lchild);//�������������
    PreOrderTraverse(T->rchild);//�������������
}

//����������������ݹ��㷨
//��ʼ������������T����
//�������������ݹ����
void InOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    InOrderTraverse(T->lchild);//�������������
    printf("%c",T->data);       //��ʾ������ݣ����Ը���Ϊ�����Խ��Ĳ���
    InOrderTraverse(T->rchild);//�������������
}

//�������ĺ�������ݹ��㷨
//��ʼ������������T����
//�������������ݹ����
void PostOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    PostOrderTraverse(T->lchild);//�������������
    PostOrderTraverse(T->rchild);//�������������
    printf("%c",T->data);       //��ʾ������ݣ����Ը���Ϊ�����Խ��Ĳ���
}

//��ǰ������������н���ֵ
//#��ʾ������������������ʾ������T
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
        (*T)->data=ch;              //���ɸ����
        CreateBiTree(&(*T)->lchild);//����������
        CreateBiTree(&(*T)->rchild);//����������
    }
}
