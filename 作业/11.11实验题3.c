/*�¼۸�
�������趨һ����Ʒ�ļ۸�1-1000֮�����������
���û��������²�ļ۸�ϵͳ��ʾ�¸��˻��ǲ�
���ˣ����߲¶����˳��²⡣���10���ڲ¶Լ۸�
��ʾ��success����������ʾ��fail����*/
#include<stdio.h>
void main()
{
    int s=688;
    int price,time=0;
    while(~scanf("%d",&price)!=s)
    {
        time++;
        if(price>s)
        {
            printf("����\n");

        }
        if(price<s)
        {
            printf("����\n");
        }
        if(price==s)
    {
        printf("success\n");
        break;
    }
        if(time>10)
        {
            break;
        }
    }
    if(time>10)
    {
        printf("fail\n");
    }
}

/*
//ѧ���ķ���
#include<stdio.h>
int main()
{
    int s=688;
    int price,time=0;
    for(int i = 0 ;i < 10;i++)
    {
        scanf("%d",&price);
        if(price>s)
        {
            printf("����\n");

        }
        if(price<s)
        {
            printf("����\n");
        }
        if(price==s)
        {
            printf("success");
            return 0;
        }
    }
        printf("fail\n");
    return 0;
}
*/
