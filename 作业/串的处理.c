///�������ط���Ҫע��
//���������ڵ�һ��
//���ǿո��ڵ�һ��
//����Сд��ĸ�ı���֮���»��ߵ��ж�
#include<stdio.h>
#include<string.h>
void main()
{
    int i,j;
    char a[300];
    while(gets(a)!=NULL)
    {
        //printf(a);//����ַ���¼���
        int alen=strlen(a);
        for(i=0; i<alen; i++)
        {
            if(a[0]>='a'&&a[0]<='z')
                a[0]-=32;//��������ĸ
            //printf("%c",a[0]);//�������ĸ�ı����
            else if(a[i-1]==' '&&a[i]>='a'&&a[i]<='z')
            {
                a[i]-=32;//ÿ�����ʵ�һ����ĸ��д
            }
            else if(a[i]==' '&&a[i+1]==' ')
            {
                //����ĵط���ɾ������ո�
                a[i]='$';
            }

            else if(a[i]>='0'&&a[i]<='9'&&a[i-1]>='a'&&a[i-1]<='z'||a[i]>='0'&&a[i]<='9'&&a[i-1]>='A'&&a[i-1]<='Z')
            {
                for(j=0; j<alen-i; j++)
                    a[alen-j]=a[alen-1-j];
                alen+=1;
                a[i]='_';
            }
            else if(a[i]>='0'&&a[i]<='9'&&a[i+1]>='a'&&a[i+1]<='z'||a[i]>='0'&&a[i]<='9'&&a[i+1]>='A'&&a[i+1]<='Z')
            {
                for(j=0; j<alen-i; j++)
                    a[alen-j]=a[alen-1-j];
                alen+=1;
                a[i+1]='_';
            }
        }
        for(i=0; i<alen; i++)
        {
            if(a[i] == '$')
                continue;
            else
                printf("%c",a[i]);
        }
        printf("\n");
    }
}
