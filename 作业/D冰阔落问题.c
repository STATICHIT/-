#include<stdio.h>
int main()
{
    int t,ans,i=1,x,y,z;
    scanf("%d",&t);
    while(i<=t)
    {
        scanf("%d %d",&x,&y);
        ans=x/y;
        z=x/y;//zΪƿ��������//
        while(z>=3)
    {
        ans=ans+z/3;
        z=z/3+z%3;
    }
    i++;
    printf("%d\n",ans);
    }

     return 0;
}

//��������ƿ�Ӻ������ǿ�ƿ��//
//��ݸ����Ҫ��������ʵ������ת��Ϊ��ѧ���⣡��//

