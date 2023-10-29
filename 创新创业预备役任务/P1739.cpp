#include<bits/stdc++.h>
using namespace std;
stack<char> st;
char a;
int main(){
    st.push('!');
    while(1){
        a=getchar();
        if(a=='(')st.push('(');
        else if(a ==')'){
            if(st.top()!='('){
                cout<<"NO";
                return 0;
            }else st.pop();
        }
        if(a=='@') break;
    }
    getchar();st.pop();
    if(st.empty()) cout<<"YES";
    else cout<<"NO";
    return 0;
}
