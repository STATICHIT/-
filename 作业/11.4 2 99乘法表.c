//��Ŀ����д�������9*9�˷��ھ���
#include<stdio.h>
void main()
{
    int i,j;//iΪ�У�jΪ��
        for(i=1;i<=9;i++)
        {
            for(j=1;j<=i;j++)//ÿһ�е�ʽ�Ӹ���Ϊ����
            {
                printf("%d*%d=%d\t",j,i,j*i);
                if(i==j)
                    printf("\n");
            }
        }

}
