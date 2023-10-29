#include<bits/stdc++.h>
using namespace std;
int myAtoi(string s)
{
    long long ans=0;
    int flag=1;//1:正。2：负
    int a[1000],i;
    long long maxNum=pow(2,31)-1;//10位数
    long long minNum=(-1)*pow(2,31);
    //去空格
    for(i=0; i<s.size(); i++)
    {
        if(s[i]!=' ')break;
    }
    //出来的时候是第一个非0数
    if(s[i]=='-')
    {
        flag=2;
        i++;
    }
    else if(s[i] == '+') i++;
    //去0
    for(; i<s.size(); i++)
    {
        if(s[i]!='0')break;
    }
    int j=0;
    for(; i<s.size(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[j]=s[i]-'0';
            j++;
        }
        else break;
    }
    int len=j;//此时j就是数组元素个数
    if(len>10)
    {
        if(flag==1)return maxNum;
        if(flag==2) return minNum;
    }

    for(j=0; j<len; j++)
    {
        if(flag==1)ans+=a[j]*pow(10,len-1-j);

        if(flag==2)ans-=a[j]*pow(10,len-1-j);
        if(ans >= maxNum)return maxNum;
        if(ans <= minNum)return minNum;
    }
    cout<<ans<<endl;
    return ans;
}
int main(){
      cout<<myAtoi("42");
return 0;
}
