#include<stdio.h>
int main()
{
    long long n,d,m,l,ans=0;
    scanf("%lld %lld %lld %lld",&n,&d,&m,&l);
    for(int k=1; k<=n; k++)//k�����k�����
    {
        if(ans<((k-1)*m))//�������������Ծ��ﲻ���������Ե������ˮ�н�����Ծ
            break;
        while(ans<=(k-1)*m+l)//�����ϰ��Ӿ�һֱ����ֱ�������˰����ұ�Ե
        {
            ans=(((k-1)*m+l)/d)*d+d;//*d/d��Ϊ��ȡ��
        }
    }
    printf("%lld",ans);
    return 0;
}
