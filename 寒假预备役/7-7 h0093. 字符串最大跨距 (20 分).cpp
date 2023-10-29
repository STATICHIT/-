/*
#include<bits/stdc++.h>
using namespace std;
#define M 1100000
char s[M],t1[M],t2[M];
int nextval[M];
int next_[M];
int l1,l2,l3;
int p1[M],p2[M];
int n1,n2;

void get_next(char *t[])
{
    int i=0,k=-1;
    next_[0]=-1;
    while(i<l2)
    {
        if(k==-1||t[i]==t[k])
        {
            ++k;
            ++i;
            nextval[i]=k;

            if(t[i]!=t[k])
                next_[i]=k;
            else
                next_[i]=next_[k];
        }
        else
            k=next_[k];
    }
}
void index_KMP(char *t[],int *num,int *p[])
{
    num=0;
    int i=0,j=0;
    get_next(t);
    while(i<l1)
    {
        if(j==-1||s[i]==t[i])
        {
            ++i;
            ++j;
        }
        else
            j=next_[j];
        if(j == 12)
        {
            num++;
            p[num]=j-12+1;
            j=next_[j];
        }
    }
}
int main()
{
    cin>>s>>t1>>t2;
    l1=strlen(s);
    l2=strlen(t1);
    l3=strlen(t2);
    index_KMP(t1,n1,p1);
    index_KMP(t2,n2,p2);
    int ans=max(p2[n2]-p1[1],p1[n1]-p2[1]);

    return 0;
}
*/

//������Ҫ���S1��S2�Ƿ�ͬʱ��S�г��֣���S1λ��S2����ߣ�����S�л�������
//��������Ҫ���s1��s�е�һ�γ��ֵ�λ�ú�s2��s�����һ�γ��ֵ�λ��
//���߼�ǰ��Ϊ����ȣ����С����˵��������������Ҫ���-1
/*
#include<bits/stdc++.h>
using namespace std;
int l1,l2,l;
int main()
{
    string str;
    getline(cin, str);
    int len = str.size();
    int pos1 = -1, pos2 = -1;
    for(int i = 0; i < len; i++)
    {
        if(str[i] == ',')
        {
            if(pos1 == -1)
            {
                pos1 = i;
            }
            else
            {
                pos2 = i;
            }
        }
    }
    l=pos1;
    l1=pos2-pos1-1;
    l2=len-pos2-1;
    //cout<<l<<endl<<l1<<endl<<l2<<endl;
    string s = str.substr(0, l);
    string s1 = str.substr(pos1+1,l1);
    string s2 = str.substr(pos2+1,l2);

    //cout<<s<<endl<<s1<<endl<<s2<<endl;
    int i, j = l2 - 1, k = 0, t = 0;
    for (i = 0; i < l; i++)
    {
        if (s[i] == s1[k])
            k++;//���ַ�����s1���ַ�����s���ַ���ͬʱk++
        else
            k = 0;//����k����Ϊ0
        if (k == l1)
        {
            t -= i + 1;//���k�ĳ��ȵ���s1�����鳤��,���-(i+1)��ֵ��t
            break;//����ѭ��
        }
    }

    for (i = l - 1; i >= 0; i--)//���ַ�����s�����һ���ַ���ʼ����
    {
        if (s[i] == s2[j])
            j--;//���ַ�����s2���ŵĵ�һ����Ч���ַ�����������ַ�����s���ַ���ȵĻ���j--
        else
            j = l2 - 1;//����Ϊl2-1
        if (j == 0)
        {
            t += i - 1;//���j==0,���t+(i-1)��ֵ��t;
            break;
        }
    }
    if (t >= 0)
        cout<<t;
    else
        cout<<"-1";
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    //�Ƚ���ȫ������Ķ���
    getline(cin,str);
    int len = str.size();
    int pos1 = -1, pos2 = -1;//����������־���ŵı�����ʼ��Ϊ������Ϊ�±����-1
    for(int i = 0; i < len; i++)
    {
        if(str[i] == ',')
        {
            if(pos1 == -1)//���pos1����-1˵���������ǵ�һ������
                pos1=i;
            else //�����������ǵڶ���
                pos2=i;
        }
    }
    int l = pos1,l1 = pos2-pos1-1,l2=len-pos2-1;//ע���ַ����±��Ǵ�0��ʼ��¼��Ŷ
    //cout<<l<<endl<<l1<<endl<<l2<<endl;//���Գ����Ƿ�������ȷ
    string s=str.substr(0,l);
    string s1=str.substr(pos1+1,l1);
    string s2=str.substr(pos2+1,l2);
    //cout<<s<<endl<<s1<<endl<<s2<<endl;//�����ַ�����ȡ�Ƿ���ȷ

    int ans = 0;//ans=s2�����ֵ�����ĸǰһ���ַ��±�-s1��һ�γ��ֵ����һ���ַ��ĺ�һ���ַ��±�
    int i,k=0;//kΪ����ƥ���ַ�����
    for(i = 0; i < l; i++)
    {
        if(s[i] == s1[k])
            k++;//��ͬ�ͼ���ƥ�䣬k++
        else
            k=0;//����k����Ϊ0
        if(k == l1)
        {
            ans-=i+1;//�ҵ��˵�һ��ƥ�䴦�����Ľ����Ҫ��ȥs1��һ�γ��ֵĺ���һ��λ�õ��±�
            break;//����ѭ��
        }
    }
    int j=l2-1;
    for(i = l;i >= 0; i--)//�Ӻ���ǰ����
    {
        if(s[i] == s2[j])
            j--;//��ͬ�ͼ���ƥ�䣬���ַ���Ҳ����������ƥ��
        else
            j=l2-1;//��������Ϊl2-1����Ϊ�ַ����Ǵ��±�0��ʼ�ģ�����Ҫ-1��
        if(j == 0)
        {
            ans+=i-1;//�ҵ���s2�����ֵ�ƥ�䴦������ǰһ��λ���±���Ϊ����
            break;
        }
    }
    if(ans >= 0)//���ans<0˵����������ĿҪ��
        cout<<ans;
    else
        cout<<"-1";

    return 0;
}
