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

//我们想要检测S1和S2是否同时在S中出现，且S1位于S2的左边，并在S中互不交叉
//所以我们要检查s1在s中第一次出现的位置和s2在s中最后一次出现的位置
//后者减前者为最大跨度，如果小于零说明不满足题意则要输出-1
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
            k++;//当字符数组s1和字符数组s的字符相同时k++
        else
            k = 0;//否则k重置为0
        if (k == l1)
        {
            t -= i + 1;//如果k的长度等于s1的数组长度,则把-(i+1)赋值给t
            break;//跳出循环
        }
    }

    for (i = l - 1; i >= 0; i--)//从字符数组s的最后一个字符开始遍历
    {
        if (s[i] == s2[j])
            j--;//从字符数组s2倒着的第一个有效的字符算起如果和字符数组s的字符相等的话则j--
        else
            j = l2 - 1;//重置为l2-1
        if (j == 0)
        {
            t += i - 1;//如果j==0,则把t+(i-1)赋值给t;
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
    //先接收全部输入的东西
    getline(cin,str);
    int len = str.size();
    int pos1 = -1, pos2 = -1;//设置两个标志逗号的变量初始化为不会作为下标的数-1
    for(int i = 0; i < len; i++)
    {
        if(str[i] == ',')
        {
            if(pos1 == -1)//如果pos1等于-1说明遇到的是第一个逗号
                pos1=i;
            else //否则遇到的是第二个
                pos2=i;
        }
    }
    int l = pos1,l1 = pos2-pos1-1,l2=len-pos2-1;//注意字符串下标是从0开始记录的哦
    //cout<<l<<endl<<l1<<endl<<l2<<endl;//测试长度是否运算正确
    string s=str.substr(0,l);
    string s1=str.substr(pos1+1,l1);
    string s2=str.substr(pos2+1,l2);
    //cout<<s<<endl<<s1<<endl<<s2<<endl;//测试字符串提取是否正确

    int ans = 0;//ans=s2最后出现的首字母前一个字符下标-s1第一次出现的最后一个字符的后一个字符下标
    int i,k=0;//k为连续匹配字符长度
    for(i = 0; i < l; i++)
    {
        if(s[i] == s1[k])
            k++;//相同就继续匹配，k++
        else
            k=0;//否则k重置为0
        if(k == l1)
        {
            ans-=i+1;//找到了第一个匹配处，最后的结果是要减去s1第一次出现的后面一个位置的下标
            break;//跳出循环
        }
    }
    int j=l2-1;
    for(i = l;i >= 0; i--)//从后往前遍历
    {
        if(s[i] == s2[j])
            j--;//相同就继续匹配，子字符串也反过来遍历匹配
        else
            j=l2-1;//否则重置为l2-1（因为字符串是从下标0开始的，所以要-1）
        if(j == 0)
        {
            ans+=i-1;//找到了s2最后出现的匹配处，它的前一个位置下标作为减数
            break;
        }
    }
    if(ans >= 0)//如果ans<0说明不满足题目要求
        cout<<ans;
    else
        cout<<"-1";

    return 0;
}
