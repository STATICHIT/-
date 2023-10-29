#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i=150;i<=333;i++){
        int v[10],a1,a2;
        for(int i=0;i<=9;i++)v[i]=0;
        int a=i,b=i*2,c=i*3;
        //cout<<a<<b<<c<<endl;
        a1=a%10;v[a1]=1;
        a=a/10;a2=a%10;v[a2]=1;
        a=a/10;v[a]=1;
        //cout<<a1<<" "<<v[a1]<<endl;
        //cout<<a2<<" "<<v[a2]<<endl;
        //cout<<a<<" "<<v[a]<<endl;
        a1=b%10;v[a1]=1;
        b=b/10;a2=b%10;v[a2]=1;
        b=b/10;v[b]=1;
        //        cout<<a1<<" "<<v[a1]<<endl;
        //cout<<a2<<" "<<v[a2]<<endl;
        //cout<<b<<" "<<v[b]<<endl;
        a1=c%10;v[a1]=1;
        c=c/10;a2=c%10;v[a2]=1;
        c=c/10;v[c]=1;
        //        cout<<a1<<" "<<v[a1]<<endl;
        //cout<<a2<<" "<<v[a2]<<endl;
        //cout<<c<<" "<<v[c]<<endl;
        int flag=1;
        for(int i=1;i<=9;i++)
        {
            if(v[i]==0){
                flag=0;
                break;
            }
        }
        if(flag==1){
            cout<<i<<" "<<i*2<<" "<<i*3<<endl;
        }
    }
    return 0;
}
