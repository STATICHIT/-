/*
#include<iostream>
using namespace std;
int w[35],c[35],dp[210];
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=n;i++)
        cin>>w[i]>>c[i];
    for(int i=1;i<=n;i++)
        for(int j=w[i];j<=m;j++)
            dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
    cout<<dp[m]<<endl;
    return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>

int main()
{
    char string[20];
    gets(string);
    int len=strlen(string),i;
    //printf("len=%d\n",len);
    int k=0,g=0;
    char huan[20][20];
    for(i=0; i<len; i++)
    {
        if(string[i]!=' ')
        {
            huan[k][g++]=string[i];
            printf("%c\\\n",string[i]);
        }
        else if(string[i] == ' ')
        {
            printf("遇到空格啦\n");
            k++;
            g=0;
        }
    }
    //for(i=k-1; i>=0; i++)
    //{
    printf("第一个单词%s\n",huan[0]);
       printf("len=%d\n",strlen(huan[0]));
       printf("第二个单词%s\n",huan[1]);
       printf("len=%d\n",strlen(huan[1]));
       printf("第三个单词%s\n",huan[2]);
       printf("len=%d\n",strlen(huan[2]));
    //}
    printf("\n");
    return 0;
}
*/

/*
#include<iostream>
using namespace std;

int main()
{
    cout<<""<<endl;

    system("pause");

    return 0;
}
*/

#include<iostream>
using namespace std;

const int N=10;
int a[N];//a[i]表示第i行上的皇后放于a[i]列上
int cnt,n;
bool check(int x,int y)
{
    for(int i=1;i<=x;i++)
    {
        if(a[i] == y)return false;
        if(i+a[i] == x+y)return false;
        if(i-a[i] == x-y)return false;
    }
    return true;
}
void dfs(int row)//表示第row皇后放于何处
{
    if(row == n+1)
    {
        //产生了一组解
        cnt++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(check(row,i))
        {
            a[row]=i;
            dfs(row+1);
            a[row]=0;
        }
    }
}
int main()
{
    cin>>n;
    dfs(1);
    cout<<cnt;
    return 0;
}
