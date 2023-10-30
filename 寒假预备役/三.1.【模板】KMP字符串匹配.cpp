/*
//ac70
#include<bits/stdc++.h>
using namespace std;

char s[1100000],t[1100000];
int l1,l2;
int nextval[1100000];
int nextt[1100000];
//��ģʽ��T��next��������ֵ����������nextval

void get_nextval()
{
    int i=1,k=0;
    nextval[1]=0;
    t[l2+1]='a';
    while(i < l2+1)
    {
        if(k == 0||t[i] == t[k])//t[i]��ʾ��׺�ĵ����ַ���t[k]��ʾǰ׺�ĵ����ַ�
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
    get_nextval();//�󵽵�ģʽ��T��nextvalֵ������next������
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
    if(j > l2)//����ı����ж��Ѿ�ƥ�䵽t��
    {
        cout<<i-l2<<endl;
        Index_KMP(i-1);
    }
}

int main()
{
    scanf("%s%s",s+1,t+1);//���±�Ϊ1��λ�ÿ�ʼ��
    l1=strlen(s+1);//���±�Ϊһ��λ��������Ԫ�ظ���
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
int next_[M];//nextval���Ż�����
int l1,l2;
void get_next()
{
    int i=0,k=-1;//��Ϊi�Ǻ�׺��j��ǰ׺�����Գ�ʼʱi�ͱ�j��1
    next_[0]=-1;
    while(i<l2)
    {
        if(k==-1||t[i]==t[k])
        {
            ++k;
            ++i;//ƥ��ͼ���
            nextval[i]=k;

            //�Ż�
            if(t[i]!=t[k])
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
    int i=0;
    int j=0;
    get_next();//�õ�ǰ��׺���ƶȱ�
    while(i<l1)//��ΪҪ��β���ƥ�䴦�����Բ���j<l2����������
    {
        if(j==-1||s[i]==t[j])//ƥ��ͼ���
        {
            ++i;
            ++j;
        }
        else//��ƥ��ͻ���
            j=next_[j];
        if(j==l2)//ƥ��ɹ�
        {
            printf("%d\n",i-l2+1);
            j=next_[j];//jֵ���ݵ����ʵ�λ�ü���Ѱ��
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

//ģ��
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
            next[j]=k;//��ԭ�������ϼ�һλ
        }
        else
        {
            k=next[k];//������ȣ�����ǰ������ƥ��
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
