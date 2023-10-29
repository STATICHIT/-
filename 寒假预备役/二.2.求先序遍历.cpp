#include<bits/stdc++.h>
using namespace std;
char s1[10],s2[10];
void dfs(int start1,int end1,int start2,int end2)//start1：中序序列起点下标，end1：中序序列终点下标，start2：后序序列起点下标，end2：后序序列终点下标
{
    if(start1>end1||start2>end2)//如果起点下标大于终点，回溯
        return;

    char ch=s2[end2];//输出后序序列末尾元素
    cout<<ch;

    for(int i=end1,k=0;i>=start1;k++,i--)///从末尾往前遍历，所以其中；【k记录当前根的右子树元素个数
    {
        if(s1[i]==ch)
        {
            dfs(start1,i-1,start2,end2-k-1);//递归处理左子树
            dfs(i+1,end1,end2-k,end2-1);//递归出库右子树
        }  ///右子树后序序列下标范围是end2-k到end2-1
    }
}
int main()
{
    cin>>s1>>s2;
    int len=strlen(s1);
    dfs(0,len-1,0,len-1);//中序与后序序列的起末点下标
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
        cout<<root;//输出根
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
