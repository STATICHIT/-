#include<stdio.h>
int a[101],n;//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ��
void quicksort(int left,int right)
{
    int i,j,temp,t;
    if(left>right)//�������
    return;
    temp=a[left];//temp�д�ľ���׼����
    i=left;
    j=right;
    while(i!=j)
    {
        //˳�����Ҫ��Ҫ�ȴ���������
        while(a[j]>=temp&&i<j)
            j--;
        while(a[i]<=temp&&i<j)
            i++;
        //�����������������е�λ��
        if(i<j)//���ڱ�i���ڱ�jû������ʱ
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    //���ս�׼������λ
    a[left]=a[i];
    a[i]=temp;

    //�ݹ鴦��������������
    quicksort(left,i-1);
    quicksort(i+1,right);
}
int main()
{
    int i,j,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    quicksort(1,n);//���ÿ�������
    //������
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    getchar();getchar();//������ͣ�����Ա�鿴���������

    return 0;
}


/*
#include<stdio.h>
long long int a[100001];
int n;
void quicksort(int left,int right)
{
    int i,j,t,temp;
    if(left>right)
        return;
    i=left;
    j=right;
    temp=a[left];

    while(i!=j)
    {
        while(a[j]>=temp&&i<j)
            j--;
        while(a[i]<=temp&&i<j)
            i++;
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[left]=a[i];
    a[i]=temp;

    quicksort(left,i-1);
    quicksort(i+1,right);
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    quicksort(1,n);
    for(i=1;i<n;i++)
        printf("%lld ",a[i]);
    printf("%lld\n",a[n]);
    return 0;
}
*/
