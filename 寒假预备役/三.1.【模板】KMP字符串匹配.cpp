/*
//ac70
#include<bits/stdc++.h>
using namespace std;

char s[1100000],t[1100000];
int l1,l2;
int nextval[1100000];
int nextt[1100000];
//求模式串T的next函数修正值并存入数组nextval

void get_nextval()
{
    int i=1,k=0;
    nextval[1]=0;
    t[l2+1]='a';
    while(i < l2+1)
    {
        if(k == 0||t[i] == t[k])//t[i]表示后缀的单个字符，t[k]表示前缀的单个字符
        {
            ++i;
            ++k;
            nextt[i]=k;
            if(t[i]!=t[k])
                nextval[i]=k;
            else
                nextval[i]=nextval[k];
        }
        else
            k=nextval[k];
    }
}

void Index_KMP(int pos)
{
    int i=pos,j=1;
    get_nextval();//求到的模式串T的nextval值被存入next数组中
    while(i<=l1 && j<=l2)
    {
        if(j == 0 || s[i] == t[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j=nextval[j];
        }
    }
    if(j > l2)//如果文本串中都已经匹配到t了
    {
        cout<<i-l2<<endl;
        Index_KMP(i-1);
    }
}

int main()
{
    scanf("%s%s",s+1,t+1);//从下标为1的位置开始存
    l1=strlen(s+1);//从下标为一的位置往后算元素个数
    l2=strlen(t+1);
    Index_KMP(1);
    for(int i=2; i<=l2+1; i++)
    {
        if(nextt[i]!=0)
        cout<<nextt[i]-1<<" ";
        else
        cout<<nextt[i]<<" ";
    }
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
#define M 1100000
char s[M],t[M];
int nextval[M];
int next_[M];//nextval的优化数组
int l1,l2;
void get_next()
{
    int i=0,k=-1;//因为i是后缀，j是前缀，所以初始时i就比j大1
    next_[0]=-1;
    while(i<l2)
    {
        if(k==-1||t[i]==t[k])
        {
            ++k;
            ++i;//匹配就继续
            nextval[i]=k;

            //优化
            if(t[i]!=t[k])
                next_[i]=k;
            else
                next_[i]=next_[k];
        }
        else//不匹配就回溯
            k=next_[k];//若字符不同，则k值回溯
    }
}
void index_KMP()
{
    int i=0;
    int j=0;
    get_next();//得到前后缀相似度表
    while(i<l1)//因为要多次查找匹配处，所以不加j<l2的限制条件
    {
        if(j==-1||s[i]==t[j])//匹配就继续
        {
            ++i;
            ++j;
        }
        else//不匹配就回溯
            j=next_[j];
        if(j==l2)//匹配成功
        {
            printf("%d\n",i-l2+1);
            j=next_[j];//j值回溯到合适的位置继续寻找
        }
    }
}
int main()
{
    cin>>s>>t;
    l1=strlen(s);
    l2=strlen(t);
    index_KMP();
    for(int i=1; i<=l2; i++)
        cout<<nextval[i]<<" ";
    return 0;
}

//模板
/*
void getNext(string s)
{
    next[0]=-1;
    int j=0,k=-1;
    while(j<s.size())
    {
        if(k == -1||s[j] == s[k])
        {
            j++;
            k++;
            next[j]=k;//在原来基础上加一位
        }
        else
        {
            k=next[k];//如果不等，则往前回溯再匹配
        }
    }
}

void index_KMP()
{
    int i=0,j=0;
    while(i<len1&&j<len2)
    {
        if(j==-1||s1[i]==s2[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }
    }
    if(j>=len2)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}

*/
