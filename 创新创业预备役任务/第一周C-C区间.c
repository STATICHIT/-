///C-C.
#include<stdio.h>
struct tv
{
    int begin;
    int finish;
};
int main()
{
    int n,i,j,k,sign;
    while(~scanf("%d",&n)&&n)//n=0��ʾ�����������������.
    {
        struct tv a[110],temp;
        for(i=0; i<n; i++)
            scanf("%d %d",&a[i].begin,&a[i].finish);
        for(i=0; i<n-1; i++)//���ս���ʱ�����絽������
        {
            for(j=i+1; j<n; j++)
            {
                if(a[j].finish<a[i].finish)
                {
                    temp=a[j];
                    a[j]=a[i];
                    a[i]=temp;
                }
            }
        }
        //��鰴�ս���ʱ������Ľ��
        /*for(i=0;i<n;i++)
        {
            printf("%d %d\n",a[i].begin,a[i].finish);
        }*/
        //printf("----�ֽ���----");//
        int k=a[0].finish,time=1;
        for(i=1; i<n; i++)
        {
            if(a[i].begin>=k)
            {
                time++;
                k=a[i].finish;
                //printf("time==%d,k==%d\n",time,k);///���time��k1
            }
        }
        printf("%d\n",time);
    }
    return 0;
}
///������˼·���ǣ��Ȱѽṹ���������ݰ��ս���ʱ������
///Ϊʹ�ÿ�������Ŀ������ʱ��Խ��Խ�ã�ÿ��ѡ��ʼʱ
///�����һ������ʱ��������ʱ���������Ľ�Ŀ��
