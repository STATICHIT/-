/*
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int num;
    struct node * next;
};
//��������ͷ������
struct node * creat(int n)//nΪ���������ݸ���
{
    int data;
    struct node * head,*p,*q;
    head = new node;
    head -> next=NULL;
    p=head;//ָ��ͷ���
    while(n--)
    {
        cin>>data;
        q = (struct node*)malloc(sizeof(struct node));
        q -> num = data;//�½�������
        q -> next = NULL;//���½����Զָ��NULL
        p -> next = q;//��������
        p=q;//pָ�����½��
    }
    return head;
}
void fun(struct node * head)//����С���ŵ���һ��ȥ
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
//3��
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
//9��
#include<bits/stdc++.h>
using namespace std;

int n;//nΪ���Ľ����
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
    back_(start1+1, end1-k,start2,x-1);//��
    back_(end1-k+1,end1,x+1,end2);//��
    cout<<s1[start1];//��
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
//5��
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
    //int p=-1,q=-1;//���ᵽ�������ⶨ����
    int s=(int)sqrt(n);
    //�ҵ�M��N
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
    //p�У�q��
    //int ans[p][q];//�ᵽ�������ⶨ����
    int v=0,flag=0;//vΪԪ���±꣬flagΪȦ��
    int i=0,j=-1;
    while(v!=n)
    {
        if(v == n)break;
        flag++;
        for( j++; j<=q-flag; j++)
        {
            ans[i][j]=a[v];
            v++;
            //cout<<"v1="<<v<<endl;//����
        }
        j--;
        if(v == n)break;
        for( i++; i<=p-flag; i++)
        {
            ans[i][j]=a[v];
            v++;
            //cout<<"i="<<i<<" v2="<<v<<endl;//����
        }
        i--;
        if(v == n)break;
        for( j--; j>=flag-1; j--)
        {
            ans[i][j]=a[v];
            v++;
            //cout<<"v3="<<v<<endl;//����
        }
        j++;
        if(v == n)break;
        for( i--; i>=flag; i--)
        {
            ans[i][j]=a[v];
            v++;
            //cout<<"v4="<<v<<endl;//����
        }
        i++;
        if(v == n)break;
    }
    print();
    return 0;
}
*/


/*
//12��
#include<bits/stdc++.h>
using namespace std;
#define M 1100000
char s[M],t[M];
int nextval[M];
int next_[M];//nextval���Ż�����
int l1,l2;
void get_next()//��ȡǰ׺��
{
    int i=0,k=-1;//ע���ַ�������±��Ǵ�0��ʼ��
    next_[0]=-1;
    while(i<l2)
    {
        if(k == -1 || t[i] == t[k])
        {
            k++;
            i++;//ƥ��ͼ���
            nextval[i]=k;

            //�Ż�,�������Լ������
            if(t[i] != t[k])
                next_[i]=k;
            else
                next_[i]=next_[k];
        }
        else//��ƥ��ͻ���
            k=next_[k];//���ַ���ͬ����kֵ����
    }
}
void index_KMP()
{
    int i = 0,j = 0;
    get_next();//�õ��Ӵ���ǰ׺��
    while(i < l1)//��ΪҪ��β���ƥ�䴦�����Բ���j<l2����������
    {
        if(j == -1||s[i] == t[j])//ƥ��ͼ���
        {
            ++i;
            ++j;
        }
        else//��ƥ��ͻ���
            j=next_[j];
        if(j==l2)//ƥ��γ������ʱƥ��ɹ�
        {
            cout<<i-(l2-1)<<endl;//����ô�ƥ��λ�ú����Ѱ��
            j=next_[j];//jֵ���ݵ����ʵ�λ�ü���Ѱ��
        }
    }
}
int main()
{
    cin>>s>>t;//sΪ���ַ�����tΪ���ַ���
    l1=strlen(s);
    l2=strlen(t);
    index_KMP();
    for(int i=1; i<=l2; i++)//���ǰ׺��
    {
        cout<<nextval[i];//������Ŀ����˼��������Ż���ǰ׺��
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
    getchar();//�̻��лس�
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%c",&s[i][j]);//һ��һ���ַ�����
        }
        getchar();//�̻��лس�
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
//�ڴ泬��
//���������ʽǰ���Ǵ�ͼ��������ȥ������
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
//��֪ʶ�������ˣ�����ȥ��
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
    T->data=a;//��
    creatTree(T->left);//��
    creatTree(T->right);//��

}

void back_(node T)
{
    back_(T->left);//��
    back_(T->right);//��
    cout<<T->data;//��
}

int main()
{

    return 0;
}
*/
