#include<bits/stdc++.h>
using namespace std;
char s1[10],s2[10];
void dfs(int start1,int end1,int start2,int end2)//start1��������������±꣬end1�����������յ��±꣬start2��������������±꣬end2�����������յ��±�
{
    if(start1>end1||start2>end2)//�������±�����յ㣬����
        return;

    char ch=s2[end2];//�����������ĩβԪ��
    cout<<ch;

    for(int i=end1,k=0;i>=start1;k++,i--)///��ĩβ��ǰ�������������У���k��¼��ǰ����������Ԫ�ظ���
    {
        if(s1[i]==ch)
        {
            dfs(start1,i-1,start2,end2-k-1);//�ݹ鴦��������
            dfs(i+1,end1,end2-k,end2-1);//�ݹ����������
        }  ///���������������±귶Χ��end2-k��end2-1
    }
}
int main()
{
    cin>>s1>>s2;
    int len=strlen(s1);
    dfs(0,len-1,0,len-1);//������������е���ĩ���±�
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
string intree,postree;
int finds(string ch,char poos,int l)
{
    for(int i=0;i<l;i++)
        if(ch[i] == poos)
        return i;
}
void pretree(string in,string pos,int l)
{
    if(l>0)
    {
        char root=pos[l-1];
        cout<<root;//�����
        int k=finds(in,root,l);
        pretree(substr(in,0,k),substr(pos,0,k));
        pretree(substr(in,k+1,l-1),substr(k,l-k-1));

    }
}
int main()
{
    cin>>intree>>cin>>postree;
    int len=strlen(postree);
    pretree(intree,postree,len,len);
    return 0;
}
*/
