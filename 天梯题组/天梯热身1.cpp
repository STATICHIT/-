#include<bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c;
    cin>>a>>b>>c;
    if(b==0)
    {
        b=2.455;
    }
    else
    {
        b=1.26;
    }
    double ans=a*b;
    printf("%.2lf ",ans);
    if(ans>=1)cout<<"T_T";
    else cout<<"^_^";
    return 0;
}
///a
///�������ܶ���С������ܶȵı�ֵ�� 3 �η�

//*������İ뾶�Լ�һ������
//�������Ӧ�ı����� 2.455)b=0
//(�����Ӧ�ı����� 1.26��b=1
//������ϣ���޵�ֵ��
