#include<stdio.h>
int a[1010][1010];//a���鷶ΧΪ1010*1010������Ҫ��������������
int main()
{
    int i,j,m,n,b=0,k[1010]={0};
    scanf("%d %d",&m,&n);
    for(i=0; i<m; i++) //�����ά����
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    for(i=0; i<m; i++)
    {
        int min=a[i][0],c=0;
        for(j=0; j<n; j++)//�ҳ�������С
        {
            if(min>a[i][j])
            {
                min=a[i][j];
                c=j;
            }
        }
        int d=1;//�к������׸㷴������ע���飡��������
        for(j=0; j<m; j++)//�ж�����С�ǲ�������С
        {
            if(min>a[j][c])
            {
                d=0;
                break;
            }
        }
        if(d == 1)
            k[b++]=a[i][c];
            //printf("XX%d ",a[z][c]);//���k���鸳ֵ���
    }
    //printf("b==%d\n",b);//���b�Ĵ�С
    for(j=0; j<b-1; j++)//���򰰵�
        for(i=0; i<b-1-j; i++)
            if(k[i]>k[i+1])//ð������������Ԫ��֮��Ƚ�Ŷ����Ҫ������
            {
                int t=k[i];
                k[i]=k[i+1];
                k[i+1]=t;
            }
    for(i=0; i<b; i++)
        printf("%d ",k[i]);
    printf("\n");
    return 0;
}
