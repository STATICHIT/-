#include<stdio.h>
int n,a[100000];
void quicksort(int l,int r)
{
    int i,j,mid,t;
    mid=a[(l+r)/2];//�м���
    i=l;j=r;
    while(i<=j)//�м�����������ֵ
    {
        while(a[i]<mid) i++;//���������м�����ֵ���
        while(a[j]>mid) j--;//����С���м�����ֵ���
          if(i<=j)//����жϲ�����ʡ�ԣ���Ϊ�������while��i��j�����Ѿ�������i<=j�ˣ����Ǵ�ʱ����������whileѭ��
            {
            t=a[i];a[i]=a[j];a[j]=t;//����
            i++;j--;
            }
    }
    //����������˵����ʱi>j
    //����˳��Ϊl.....j.i.....r��j i l...r��l...r j i
    //�ݹ鴦��������������
    if(l<j) quicksort(l,j);
    if(i<r) quicksort(i,r);
}
int main()
{
    scanf("%d",&n);
    //��������
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    quicksort(1,n);//����
    //�������
    for(int i=1; i<=n; i++)
        printf("%d ",a[i]);
}

/*
#include<stdio.h>
int a[1000001],n;//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ��
void quicksort(int left,int right)
{
    int i,j,mid,t;
    mid=a[(left+right)/2];//temp�д�ľ���׼����
    i=left;
    j=right;
    while(i<=j)
    {
        while(a[j]>=mid&&i<j)
            j--;
        while(a[i]<=mid&&i<j)
            i++;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;j--;
    }
    //����������˵����ʱi>j
    //�ݹ鴦��������������
    if(left<j)quicksort(left,j);
    if(i<right)quicksort(i,right);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    quicksort(1,n);//���ÿ�������
    //������
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}
*/
/*
#include<stdio.h>
int a[100000],n;//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ��
void quicksort(int left,int right)
{
    int i,j,t;
    int mid=a[(left+right)/2];
    i=left;
    j=right;
    while(i<j)
    {
        //˳�����Ҫ��Ҫ�ȴ���������
        while(a[j]>mid)
            j--;
        while(a[i]<mid)
            i++;
        //�����������������е�λ��
        if(i<j)//���ڱ�i���ڱ�jû������ʱ
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;
            j--;
        }
    }

    //�ݹ鴦��������������
    if(left<j)quicksort(left,j);
    if(i<right)quicksort(i,right);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    quicksort(1,n);//���ÿ�������
    //������
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}
*/
/*
//�����㷨�ϵ�
#include<stdio.h>
int a[1000001],n;//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ��
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
    return 0;
}
*/
