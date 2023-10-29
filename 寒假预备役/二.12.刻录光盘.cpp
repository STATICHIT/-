#include <bits/stdc++.h>
using namespace std;
int will[210][210];//will意愿数组元素的值取1或0表示一个人是否愿意给另外一个人拷贝
int f[210],n;
int main()
{
    cin>>n;
    //memset(will,0,sizeof(will));  //初始化，起初大家之间都没有意愿
    //因为will数组是全局变量，是可以不初始化的

      //初始化父亲数组
    for(int i=1; i<=n; i++)
        f[i]=i;

    int x;
    for(int i=1; i<=n; i++)
        while(cin>>x && x!=0)//每一行数据个数不确定，输入0代表结束
             will[i][x]=1;  //表示第i个人愿意给第x个人拷贝

    //Floyd-Warshall把意愿关系转化为单向路径问题
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(will[i][k] == 1 && will[k][j] == 1)//如果i愿意给k，k愿意给j，则相当于i愿意给j
                    will[i][j]=1;

    for(int i=1; i<=n; i++)//遍历意愿数组
        for(int j=1; j<=n; j++)
            if(will[i][j])
                f[j]=f[i];  //不能直接合并，因为该题的关系是单向的，要f【拷贝人】=f【愿意给他拷贝的人】，即所有他愿意给拷贝的人认他为老大

    int ans=0;
    for(int i=1; i<=n; i++)
        if(f[i]==i)
            ans++;  //处理完以后，f【x】=x的人需要给一个光盘

    cout<<ans;
    return 0;
}
