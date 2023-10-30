#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12  //定义散列表长度
#define NULLKEY -32768
typedef struct
{
    int *elem;  //数据元素的基址，动态分配数值
    int count;  //当前数据元素的个数
}HashTable;

//初始化散列表
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

//散列函数
int Hash(int key)
{
    return key % HASHSIZE; //使用除留余数法
}

//插入关键字到散列表
void InsertHash(HashTable *H,int key)
{
    int addr;

    addr=Hash(key);  //求散列地址
    while(H->elem[addr]!=NULLKEY)//如果不为空，则冲突出现
    {
        add =(addr + 1) % HASHSIZE;//开放定址法的线性探测
    }
    H->elem[addr]=key;
}

//散列表中查找关键字
Status SearchHash(HashTable *H,int key, int *addr)
{
    *addr=Hash(key); //求散列地址

    while(H.elem[*addr]!=key)
    {
        *addr=(*addr + 1) % HASHSIZE;
        if(H.elem[*addr]==NULLKEY||*addr ==Hash(key))
            return UNSUCCESS;
    }
    return SUCCESS;
}
