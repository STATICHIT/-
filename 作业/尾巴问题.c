#include<stdio.h>
int main()
{
    int n,i;
    while(~scanf("%d",&n))
    {   long long int x=1;
        for(i=1; i<=n; i++)
        {
            x*=11;
            x%=10000;        //n��ȡֵ���Դ�10000������11��n�η�̫���ˣ���ʹ��long long int Ҳ���治��
                             //����Ӧ�ñ߳˱����ֻ࣬�����漸λ����11�ĳ˻��������һ���ģ�����Ҫһ���԰�11��n�η������
        }
        printf("%d\n",x);
    }

    return 0;
}
