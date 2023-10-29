#include<bits/stdc++.h>
using namespace std;
int a[1000],ans,num,les,hang;
char s;
int main()
{
    int k=0;
    for(int i=1; ans<=500; i+=2)
    {
        k++;
        ans+=i;
        a[k]=ans*2-1;
    }
    cin>>num>>s;
    for(int i=1; i<k; i++)
    {
        if(num == a[i])
        {
            hang=i;
            break;
        }
        else if(num>a[i]&&num<a[i+1])
        {
            les=num-a[i];
            num=a[i];
            hang=i;
            break;
        }
    }
    for(int v=1; v<=hang; v++)
    {
        for(int j=0; j<v-1; j++)
        {
            cout<<" ";
        }
        for(int i=1; i<=2*(hang-v+1)-1; i++)
        {
            cout<<s;//用指定的符号画沙漏

        }
        cout<<endl;
    }
    for(int v=2; v<=hang; v++)
    {
        for(int j=0; j<hang-v; j++)
        {
            cout<<" ";
        }
        for(int i=1; i<=2*v-1; i++)
        {
            cout<<s;

        }
        cout<<endl;
    }
    cout<<les;//剩余的符号数是0也要打印出来哦！
    return 0;
}
