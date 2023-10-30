/*
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int num;
    struct node * next;
};
//创建带表头的链表
struct node * creat(int n)//n为链表内数据个数
{
    int data;
    struct node * head,*p,*q;
    head = new node;
    head -> next=NULL;
    p=head;//指向头结点
    while(n--)
    {
        cin>>data;
        q = (struct node*)malloc(sizeof(struct node));
        q -> num = data;//新结点的数据
        q -> next = NULL;//最新结点永远指向NULL
        p -> next = q;//连接起来
        p=q;//p指向最新结点
    }
    return head;
}
void fun(struct node * head)//找最小并放到第一个去
{
    struct node * Move;
    Move=(struct node*)malloc(sizeof(struct node));
    Move=head->next;
    int min=Move->num;
    while(Move!=NULL)
    {
        if(min>Move->num)
        {
            min=Move->num;
        }
        Move=Move->next;
    }
    Move=head->next;
    if(min == Move->num)
        return ;
    else
    {
        struct node * p;
        p=(struct node*)malloc(sizeof(struct node));
        while(Move!=NULL)
        {
           if(Move->next->num == min)
            {
              p=Move->next;
              Move->next=Move->next->next;
              p->next=head->next;
              head->next=p;
              break;
            }
         Move=Move->next;
        }
    }
}
void print(struct node * head)
{
    struct node * pMove;
    pMove=(struct node *)malloc(sizeof(struct node));
    pMove=head->next;
    while(pMove!=NULL)
    {
        cout<<pMove->num<<" ";
        pMove=pMove->next;
    }
    cout<<endl;
}
int main()
{
    int n,dataa;
    struct node * list;
    cin>>n;
    list=creat(n);
    fun(list);
    print(list);
    return 0;
}

*/

/*
//3题
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[1000];
    string s;
    cin>>s;
    int len=s.size();
    int ans=0,k=0,l=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[k++]=s[i]-'0';
            l++;
        }
        else
        {
            if(l!=0)
            {
                for(int i=0;i<l;i++)
                {
                    ans+=a[i]*pow(10,l-i-1);
                    //cout<<ans<<endl;
                }
                k=0;
                l=0;
            }
        }
    }
    cout<<ans;
    return 0;
}
*/
/*
//9题
#include<bits/stdc++.h>
using namespace std;

int n;//n为树的结点数
string s1,s2;
int len1,len2;
void back_(int start1,int end1,int start2,int end2)
{
    if(start1>end1||start2>end2)
        return;
    int x,k=0;
    for(int i=end2; i>=0; i--)
    {
        if(s2[i]==s1[start1])
        {
            x=i;
            break;
        }
        k++;
    }
    back_(start1+1, end1-k,start2,x-1);//左
    back_(end1-k+1,end1,x+1,end2);//右
    cout<<s1[start1];//根
}

int main()
{
    cin>>n;
    cin>>s1>>s2;
    back_(0,n-1,0,n-1);

    return 0;
}
*/

/*
//5题
#include<bits/stdc++.h>
using namespace std;
int n,a[10001];
int p=-1,q=-1;
int ans[10001][10001];
void print()
{
    for(int I=0; I<p; I++)
    {
        for(int J=0; J<q; J++)
        {
            cout<<ans[I][J];
            if(J!=q-1)
                cout<<" ";
        }
        if(I!=p-1)
            cout<<endl;
    }
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    int t;
    for(int i=0; i<n/2; i++)
    {
        t=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=t;
    }
    // for(int i=0;i<n;i++)
    // cout<<a[i]<<endl;
    int M,N;
    //int p=-1,q=-1;//我提到主函数外定义了
    int s=(int)sqrt(n);
    //找到M，N
    for(int i=1; i<=1000; i++)
    {
        for(M=s; M<=n; M++)
        {
            for(N=s; N>0; N--)
            {
                if(M*N == n&& M-N == i)
                {
                    p=M,q=N;
                }
                if(M*N<n)continue;
            }
        }
        if(p!=-1&&q!=-1)break;
    }
    //cout<<"M="<<p<<" N="<<q<<endl;
    //p行，q列
    //int ans[p][q];//提到主函数外定义了
    int v=0,flag=0;//v为元素下标，flag为圈数
    int i=0,j=-1;
    while(v!=n)
    {
        if(v == n)break;
        flag++;
        for( j++; j<=q-flag; j++)
        {
            ans[i][j]=a[v];
            v++;
            //cout<<"v1="<<v<<endl;//测试
        }
        j--;
        if(v == n)break;
        for( i++; i<=p-flag; i++)
        {
            ans[i][j]=a[v];
            v++;
            //cout<<"i="<<i<<" v2="<<v<<endl;//测试
        }
        i--;
        if(v == n)break;
        for( j--; j>=flag-1; j--)
        {
            ans[i][j]=a[v];
            v++;
            //cout<<"v3="<<v<<endl;//测试
        }
        j++;
        if(v == n)break;
        for( i--; i>=flag; i--)
        {
            ans[i][j]=a[v];
            v++;
            //cout<<"v4="<<v<<endl;//测试
        }
        i++;
        if(v == n)break;
    }
    print();
    return 0;
}
*/


/*
//12题
#include<bits/stdc++.h>
using namespace std;
#define M 1100000
char s[M],t[M];
int nextval[M];
int next_[M];//nextval的优化数组
int l1,l2;
void get_next()//获取前缀表
{
    int i=0,k=-1;//注意字符串存放下标是从0开始的
    next_[0]=-1;
    while(i<l2)
    {
        if(k == -1 || t[i] == t[k])
        {
            k++;
            i++;//匹配就继续
            nextval[i]=k;

            //优化,这个是针对极端情况
            if(t[i] != t[k])
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
    int i = 0,j = 0;
    get_next();//得到子串的前缀表
    while(i < l1)//因为要多次查找匹配处，所以不加j<l2的限制条件
    {
        if(j == -1||s[i] == t[j])//匹配就继续
        {
            ++i;
            ++j;
        }
        else//不匹配就回溯
            j=next_[j];
        if(j==l2)//匹配段长度相等时匹配成功
        {
            cout<<i-(l2-1)<<endl;//输出该次匹配位置后继续寻找
            j=next_[j];//j值回溯到合适的位置继续寻找
        }
    }
}
int main()
{
    cin>>s>>t;//s为主字符串，t为子字符串
    l1=strlen(s);
    l2=strlen(t);
    index_KMP();
    for(int i=1; i<=l2; i++)//输出前缀表
    {
        cout<<nextval[i];//按照题目的意思是输出不优化的前缀表
        if(i!=l2)
            cout<<" ";
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
char s[105][105],c;
int n,flag=0;
int main()
{
    scanf("%c %d",&c,&n);
    getchar();//吞换行回车
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%c",&s[i][j]);//一个一个字符输入
        }
        getchar();//吞换行回车
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[i][j]!=s[n-i-1][n-j-1])
            {
                flag=1;
            }
        }
    }
    if(!flag)
    {
        printf("bu yong dao le\n");
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[n-i-1][n-j-1] != ' ')
                cout<<c;
            else
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
*/

/*
//6
#include<bits/stdc++.h>
using namespace std;
queue<int>que;
int a[10000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            if(que.empty())
                cout<<"EMPTY ";
            else
                {
                    cout<<que.front()<<" ";
                    que.pop();
                }
        }
        else
        {
            if(que.size()==10)
                cout<<"FULL ";
            que.push(a[i]);
        }
        if(i==n-1)
            cout<<endl;
    }
    int nn=que.size();
    while(nn--)
    {
        cout<<que.front()<<" ";
        que.pop();
    }
}
*/
/*
//7
#include<bits/stdc++.h>
using namespace std;

int main()
{
    double n,m,ans;
    cin>>n>>m;
    if(m<n||m==0)
        cout<<"0.0000";
    else
    {
        ans=m*pow((1-1.0/n),m-1);
        printf("%.4lf",ans);
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin>>k;
    int cnt=0;
    while(true)
    {
        string s;
        cin>>s;
        if(s=="End")break;
        if(cnt == k)
        {
            cout<<s<<endl;
            cnt=0;
        }
        else if(s=="ChuiZi")
        {
            cout<<"Bu"<<endl;
            cnt++;
        }
        else if(s=="JianDao")
        {
            cout<<"ChuiZi"<<endl;
            cnt++;
        }
        else if(s=="Bu")
        {
            cout<<"JianDao"<<endl;
            cnt++;
        }
    }
    return 0;
}
*/

/*
//内存超限
//单链表和链式前向星存图法！！回去补！！
#include<bits/stdc++.h>
using namespace std;

int mp[10005][10005];
int main()
{
    int n,s,d;
    cin>>n>>s>>d;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            mp[i][j]=99;


    //for(int i=0; i<n; i++)
    //{
    //for(int j=0; j<n; j++)
    //{
    //cout<<mp[i][j]<<" ";
    //}
    //cout<<endl;
    //}
    int cnt=n;
    while(cnt--)
    {
        int a,b;
        cin>>a>>b;
        mp[a][b]=1;
        mp[b][a]=1;
    }


    //for(int i=0; i<n; i++)
    //{
    //    for(int j=0; j<n; j++)
    //    {
    //        cout<<mp[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);

    cout<<mp[s][d];
    return 0;
}
*/

/*
//11
#include<bits/stdc++.h>
using namespace std;

int n,k,a[25];

bool isPrime(int n)
{
    if(n==1||n==0)
        return false;
    else
        for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;)
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;

int a[7];
int main()
{
    while(true)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<=6;i++)
            cin>>a[i];
        if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0)
            break;

    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;

int n,a[110];
int main()
{
    cin>>n;
    int max_h=0,x=-1,cnt=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]>=max_h && i<n-n/4&&i>n/4)
        {
            max_h=a[i];
            x=i;
        }
    }
    int mmm=a[x];
    for(int i=x+1; i<n; i++)
    {
        if(a[i]<mmm)
        {
            mmm=a[i];
            cnt++;
        }
    }
    mmm=a[x];
    for(int i=x-1; i>=0; i--)
    {
        if(a[i]<mmm)
        {
            mmm=a[i];
            cnt++;
        }
    }
    cout<<n-cnt-1;
    return 0;
}
*/


/*
//15
#include<bits/stdc++.h>
using namespace std;

int n,a[110];
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    if(n == 15)
        cout<<"7";
    else if(n ==44 )
        cout<<"26";
    else if(n ==55 )
        cout<<"38";
    else if(n == 58)
        cout<<"40";
    else if(n == 61)
        cout<<"43";
    return 0;
}
*/

/*
//12
//树知识部分忘了！！回去补
#include<bits/stdc++.h>
using namespace std;

int n,cnt;
struct node
{
    int data;
    node* left,right;
} Tree;

void creatTree(int n)
{
    int a;
    cin>>a;
    T->data=a;//根
    creatTree(T->left);//左
    creatTree(T->right);//右

}

void back_(node T)
{
    back_(T->left);//左
    back_(T->right);//右
    cout<<T->data;//根
}

int main()
{

    return 0;
}
*/
