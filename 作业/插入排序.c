 #include<stdio.h>
int main()
{
    int i,j,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        if(a[i]<a[i-1])//����i��Ԫ�ش���i-1Ԫ����ֱ�Ӳ��룻
                      //��֮����Ҫ�ҵ��ʵ���λ���ٲ���
        {j=i-1;
        int x=a[i];
        while(j>=0&&x<a[j])//����˳����ҷ�ʽ�ҵ������λ��
        {                  //�ڲ��ҵ�ͬʱ���������е�Ԫ�ؽ�
            a[j+1]=a[j];   //�к��Ʋ�����������Ԫ���ڳ��ռ�
            j--;
        }
        a[j+1]=x;//���뵽��ȷλ��
        }
    }
    for(i=0;i<n;i++)
    {
    printf("%d ",a[i]);
    }
    return 0;
}
