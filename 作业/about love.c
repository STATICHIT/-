/*
#include<stdio.h>
#include<string.h>
void main()
{
    char love[1005];
    int two[1005];
    scanf("%s",love);
    getchar();
    for(int i=0; i<strlen(love); i++)
    {
        int sang,beichushu,j;
        for(beichushu=love[i], j=0;;)
        {
            sang=beichushu/2;
            two[j]=beichushu%2;
            j++;
            if(sang==0)
                break;
            if(sang!=0)
                beichushu=sang/2;
        }
        for(j=strlen(two)-1; j>=0; j--)
        {
            printf("%d",two[j]);
        }
        memset(two,0,strlen(two));
        printf("\n");
    }
}*/


#include<stdio.h>
int a[25], i;//������a����2���ƽ��
void binary_fun(int n)
{
    //�����Ʋ���8λ����ǰ�油0
    if(n<=64)//2��6�η�����64��С�ڵ���64˵�����6λ�����ƣ�Ҫ������0
        printf("00");
    else
        printf("0");//ascall���������Ϊ127��2��7�η�Ϊ128������תΪ�������ٴ�Ҳ�ﲻ����λ���������1��0

    i = 0;
    do//�� do-while ��ֹ��n<2�����
    {
        a[i++] = n % 2;
        n =n/2;
    }while (n);

    while(i--)// �������
    {
        printf("%d", a[i]);
    }
    printf("\n");
}

void main()
{
    char love[1005];
    gets(love);//C���Խ��ܴ��ո���ַ���
    for(int i=0; i<strlen(love); i++)
    {
        int two=(int)(love[i]);
        binary_fun(two);
    }
}








