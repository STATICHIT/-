#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
int main(){
    int n,num=0;
    cin>>n;
    getchar();
    while(n--){
        string s;
        getline(cin,s);
        if(m.find(s)==m.end()){
            m[s]=1;
            num++;
        }
    }
    cout<<num;
    return 0;
}
