///A��G����
#include <stdio.h>
#include<string.h>
int main()
{
    int n,a[1001],b[1001],i,k,top;//a���鴢���������ݣ�bΪջ
    while(~scanf("%d",&n)&&n!=0)//ע�����ﲻ��дwhile(scanf("%d",&n)!=0)
    {
        memset(a,0,1001);
        memset(b,0,1001);

        while (~scanf("%d", &a[1]))///��Ϊ����������a[1]
        {
            if (a[1] == 0)//��Ӧ����:ÿ����n��1��n���������
                break;    //ֱ��ĳһ�е�һ������0��ʾ����������

            for (i=2;i<=n;i++)///���������i=2��ʼ
                scanf("%d",&a[i]);

            k=1;top=1;//topΪջ��
            for(i=1;i<=n;i++)
            {
                b[top]=i;
                while(b[top]==a[k]&&top>0)///���ﲻ̫����⣬��ʱ���������
                {
                    top--;
                    k++;
                }
                top++;
            }
            if(k>n) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
