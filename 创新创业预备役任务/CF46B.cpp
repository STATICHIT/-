/*
#include<bits/stdc++.h>
using namespace std;
int k,a[10];
string str;
map<int,string>c;
int ck(string str)//������תΪ����
{
    if(str=="S")return 0;
    if(str=="M")return 1;
    if(str=="L")return 2;
    if(str=="XL")return 3;
    if(str=="XXL")return 4;
}
int main()
{
    //�������
    c[0]="S",c[1]="M",c[2]="L",c[3]="XL",c[4]="XXL";

    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
    cin>>k;
    while(k--)
    {
        cin>>str;
        int o=ck(str);
        //�������ƶ�
        for(int i=0; i<=5; i++)//��һ��iΪ0�൱���жϵ�ǰ�����޴��
        {
            //���жϴ�������
            if(a[o+i])
            {
                cout<<c[o+i]<<endl;
                a[o+i]--;
                break;
            }
            if(a[o-i])
            {
                cout<<c[o-i]<<endl;
                a[o-i]--;
                break;
            }
        }

    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str,f="edgnb";
    cin>>str;
    int cnt=0;
    for(int i=0;i<str.size()-3;i++){
        if(str[i]=='e'){
            bool flag = true;
            for(int j=0;j<5;j++,i++){
                if(str[i]!=f[j]){
                    flag=false;//��ƥ��ֱ������
                    break;
                }
            }
            if(flag){
                cnt++;
                i--;
            }
        }
    }
    cout<<cnt;
}
