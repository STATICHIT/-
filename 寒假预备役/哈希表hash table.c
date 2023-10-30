#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12  //����ɢ�б���
#define NULLKEY -32768
typedef struct
{
    int *elem;  //����Ԫ�صĻ�ַ����̬������ֵ
    int count;  //��ǰ����Ԫ�صĸ���
}HashTable;

//��ʼ��ɢ�б�
Status IninHashTable(HashTable *H)
{
    H->count = HASHSIZE;
    H->elem = (int*)malloc(HASHSIZE * sizeod(int));
    if(! H->elem)
    {
        return ERROR;
    }
    for(int i=0;i<HASHSIZE;i++)
    {
        H->elem[i] =NULLKEY;
    }
    return OK;
}

//ɢ�к���
int Hash(int key)
{
    return key % HASHSIZE; //ʹ�ó���������
}

//����ؼ��ֵ�ɢ�б�
void InsertHash(HashTable *H,int key)
{
    int addr;

    addr=Hash(key);  //��ɢ�е�ַ
    while(H->elem[addr]!=NULLKEY)//�����Ϊ�գ����ͻ����
    {
        add =(addr + 1) % HASHSIZE;//���Ŷ�ַ��������̽��
    }
    H->elem[addr]=key;
}

//ɢ�б��в��ҹؼ���
Status SearchHash(HashTable *H,int key, int *addr)
{
    *addr=Hash(key); //��ɢ�е�ַ

    while(H.elem[*addr]!=key)
    {
        *addr=(*addr + 1) % HASHSIZE;
        if(H.elem[*addr]==NULLKEY||*addr ==Hash(key))
            return UNSUCCESS;
    }
    return SUCCESS;
}
