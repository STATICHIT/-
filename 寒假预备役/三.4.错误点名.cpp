/*
#include<bits/stdc++.h>
using namespace std;
#define base 131
#define mod 2345689345287
#define NULLKEY -32768

int n,m;
char name[50],sign[50];
int book[110000];
long long ha[110000];

typedef struct
{
    int *elem;  //数据元素的基址，动态分配数值
    int count;  //当前数据元素的个数
}HashTable;

//初始化散列表
void IninHashTable(HashTable *H)
{
    H->count = n;
    H->elem = (long long *)malloc(n * sizeof(long long));
    for(int i=0;i<n;i++)
    {
        H->elem[i] =NULLKEY;
    }
}
//哈希函数
long long hashs(char *s)
{
    int len=strlen(s);
    long long hs=0;
    for(int i=0;i<len;i++)
    {
        hs=(hs*base+(long long )s[i])%mod;
    }
    return hs&0x7ffff;
}

//插入关键字到散列表
void InsertHash(HashTable *H,char *key)
{
    long long  addr;

    addr=hashs(key);  //求散列地址
    while(H->elem[addr]!=NULLKEY)//如果不为空，则冲突出现
    {
        add =(addr + 1) % HASHSIZE;//开放定址法的线性探测
    }
    H->elem[addr]=key;
}

//散列表中查找关键字
int SearchHash(HashTable *H,char *key, int *addr)
{
    *addr=hashs(key); //求散列地址

    while(H.elem[*addr]!=key)
    {
        *addr=(*addr + 1) % HASHSIZE;
        if(H.elem[*addr]==NULLKEY||*addr ==Hash(key))
            cout<<"WRONG"<<endl;
    }
    cout<<"OK"<<endl;
}

int main()
{
    cin>>n;
    HashTable H;
    IninHashTable(H);

    for(int i=0; i<n; i++)
        {
            cin>>name;
            InsertHash(H,name);
            //cout<<ha[i]<<endl;
        }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        int addr;
        cin>>sign;
        void book=SearchHash(H,sign,*addr);
    }
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
#include<map>
map<string,int>word;//初始化默认int值为0
string s;
int n,m;
int main()
{
    cin>>n;
    while(n--)
    {
        cin>>s;
        word[s]=1;//存在的名字都对应1
    }
    cin>>m;
    while(m--)
    {
        cin>>s;
        if(word[s] == 1)
        {
            cout<<"OK"<<endl;
            word[s]=2;//喊过这个名字了就把他对应为2
        }
        else if(word[s] == 2)
            cout<<"REPEAT"<<endl;
        else
            cout<<"WRONG"<<endl;
    }
    return 0;
}
