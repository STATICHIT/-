#include<stdio.h>

void main()

{
    long a,i,t,r;
    long long int q,d,b;//dΪ��С������
   while(~scanf("%ld %ld",&a,&b))
   {q=a*b;//qΪ����֮��������֮���������ǵ����Լ������С������֮��
        if(a<b)
        {
            t=a;
            a=b;
            b=t;
        }
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;//���������Ϊ0��Ҫ����С������������ֱ������Ϊ0��������Ϊ���Լ����

        }

        printf("%ld\n",b);//bΪ���Լ��
        d=q/b;
        printf("%lld\n",d);
   }


}

