#include<stdio.h>
#include<string.h>
int main()
{
 char a[100],b[100];//���ַ�����������
 int x[101],y[101],z[202]={0};

    int la,lb,i,j;
    scanf("%s",a);
    getchar();
    scanf("%s",b);
    getchar();
    la=strlen(a);lb=strlen(b);
    for(j=0,i=la-1;i>=0;i--)//ת���ֲ�����
    {
        x[j++]=a[i]-'0';
    }
    for(j=0,i=lb-1;i>=0;i--)
    {
        y[j++]=b[i]-'0';
    }
    for(i=0;i<la;i++)
    {
        for(j=0;j<lb;j++)
        {
            z[i+j]=z[i+j]+x[i]*y[j];//�ȳ˲���λ
        }
    }
    for(i=0;i<202;i++)//��λ
    {
        if(z[i]>=10)//�����λ�ò��Ǹ�λ��
        {
            z[i+1]=z[i+1]+z[i]/10;//����һλ��ʮλ���ӹ���
            z[i]=z[i]%10;//����һλ�ĸ�λ���ֱ��������Լ�
        }
    }
    for(i=201;i>0;i--)//ɾ��ǰ��0
    {
        if(z[i] == 0)
        continue;
        else
        break;
    }//���������iΪ��Ϊ��һ��0�������±�
    for(;i>=0;i--)//�������
    {
        printf("%d",z[i]);
    }
    printf("\n");
    return 0;
}
