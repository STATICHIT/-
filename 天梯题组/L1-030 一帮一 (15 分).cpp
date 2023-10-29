/*
定义一个char类型的数组用来存名字，一个int类型
的数组用来存性别（1表示男性，0表示女性），将存
名字的数组从两边遍历，如果两个人性别不同，将这
两个名字输出，并且将已输出的人标记一下，
这里就要建立一个和人数一样大小的数组，将它初
始化未0，若输出，置为1，直到数组中所有的数变为1
*/

#include<bits/stdc++.h>
using namespace std;

char name[55][10];
int s[55],n,book[55];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
       cin>>s[i]>>name[i];

    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(book[i]==0&&book[j]==0&&s[i]!=s[j])
            {
                book[i]=1;book[j]=1;
                cout<<name[i]<<" "<<name[j]<<endl;
            }
        }
    }
    return 0;
}

