//�������Ǹ���֪�к�����ǰ�����������
#include<bits/stdc++.h>
using namespace std;
char s1[100],s2[100];
void dfs(int start1,int end1,int start2,int end2)
{
    if(start1>end1||start2>end2)
        return;
    char ch=s2[start2];//������������Ԫ��
    for(int i=start1,k=0;i<=end1;i++,k++)
    {
        if(s1[i] == ch)
        {
            dfs(start1,i-1,start2+1,start2+1+k-1);
            dfs(i+1,end1,start2+1+k,end2);
            cout<<ch;//������������Ҹ�����������
        }
    }
}
int main()
{
    cin>>s1;
    cin>>s2;
    int len=strlen(s1);
    dfs(0,len-1,0,len-1);
    return 0;
}
