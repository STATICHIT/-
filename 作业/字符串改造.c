#include<stdio.h>
#include<string.h>
void main()
{
    char a[15+1];
    char ji[15];
    char ou[15];
    int sign[15+1]={0};//ż�����Ϊ0
    int i,j,t;
    gets(a);
    for(i=0;i<=strlen(a)+1;i=i+2)//�������Ϊ1
    {
        sign[i]=1;
    }
    /*for(i=0;i<=strlen(a)+1;i++)
    {
    printf("%d ",sign[i]);
    }*///���sign����
    for(i=0,j=0;i<=strlen(a)+1;i++)
    {if(sign[i])
    {
            ji[j++]=a[i];
    }
    }
    ji[j]='\0';///����Ϊ�ַ����鸳ֵʱҪ��ĩλ��Ϊ'\0'
    /*printf(ji);*///���ji����
    for(j=0;j<strlen(ji)-1;j++)
    {
        for(i=0;i<strlen(ji)-1-j;i++)
        {
            if(ji[i]>ji[i+1])
            {t=ji[i];ji[i]=ji[i+1];ji[i+1]=t;}
        }
    }
    //�����������
    /*printf(ji);*///���ji����˳��
    for(i=0,j=0;i<=strlen(a);i++)
//����ż������ʱ����ʹj=0�����˺ܾõ�bug����
    {if(sign[i]==0)
    {
        ou[j++]=a[i];
    }
    }
    ou[j]='\0';///����Ϊ�ַ����鸳ֵʱҪ��ĩλ��Ϊ'\0'
    /*printf(ou);*///���ou����
    for(j=0;j<strlen(ou)-1;j++)
    {
        for(i=0;i<strlen(ou)-1-j;i++)
        {
            if(ou[i]<ou[i+1])
            {t=ou[i];ou[i]=ou[i+1];ou[i+1]=t;}
        }
    }
    //ż���������
    /*printf(ou);*///���ou����˳��
    printf(strcat(ji,ou));
}
