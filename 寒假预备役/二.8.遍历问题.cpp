#include<bits/stdc++.h>
#include<math.h>
using namespace std;
char s1[1000],s2[1000];
int len,n=0,ans=0;
int main()
{
    cin>>s1;
    cin>>s2;
    len=strlen(s1);
    for(int i=1;i<len;i++)//ע��˴�Ϊi=1��ʼ����Ϊi=0ʱ��i-1=-1�����Ϸ���
        for(int j=0;j<len;j++)
            if(s1[i]==s2[j]&&s1[i-1]==s2[j+1])//�������������ab��ba�������
                n++;
    ans=pow(2,n);
    printf("%d",ans);
}
