
#include<stdio.h>
#include<string.h>
int main()
{
    char a[101],b[101];
    int i,j,k,flag;
    while(~scanf("%s",&a))
    {
        int m=0;//ÿ������Ҫ���½�m��0
        memset(b,-7,101);//��b��������Ԫ�ض���Ϊ-7(�����Ҳ�У�
        for(i=0; i<strlen(a); i++)//��һ��˫��ѭ����ifǶ����Ϊ���ҳ����ظ����ַ�
        {
            for(j=0; j<strlen(a); j++)
            {
                if((a[i]==a[j])&&(i!=j))//�����ֹ����һ�ξ��������
                {
                    flag=1;
                    break;
                }
                else
                    flag=0;
            }
            if(flag==0)
            {
                b[m++]=a[i];///b[m]���治�ظ����ַ�
            }
        }

        for(i=0; i<strlen(a); i++)//���ѭ����Ҫ��ǲ��ظ�����Ϊ-1
        {
            for(j=0;j<m;j++)
            if(a[i]==b[j])
            {
                a[i]=-1;break;
            }
        }

        for(i=0; i<strlen(a); i++)
        {
            //��ôʹ���ظ����ַ�������ѭ����
            if(a[i]==-1)
            {
                continue;//ʹ���ظ����ַ��Լ��Ѵ�ӡ���ַ���������Կ�����ӡ�˾͸���������ѭ��
            }
            else
            {
                printf("%c:%d",a[i],i);//��ӡ��һ�����ֵ��ַ�(��Ϊ�������Ե�һ���ͺ����Ҫ�ֿ���)
                for(j=i+1; j<strlen(a); j++)
                {
                    if(a[j]==a[i])
                    {
                        printf(",%c:%d",a[j],j);//��ӡ����ͬǰ���ӡ���ַ���ͬ���ַ�
                        a[j]=-1;//����Ѵ�ӡ���ַ�
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}
