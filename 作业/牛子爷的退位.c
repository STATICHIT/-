#include<stdio.h>
//�Զ��������������Ԫ�صĺ���
int maxa(int a[],int size)//�����±��ڲ�Ҫд��Χ
{
    int i,max;
    max=a[0];
    for(i=0; i<size; i++)
    {
        if(max<a[i])
        {
            max=a[i]; ///�����ɻ�Ϊʲô���ϵ�
                      ///�Զ��������������β����±�
        }
    }
    return max;

}
//�Զ����ж�������ĳ�����Ƿ�Ψһ
int weiyi(int a[3],int n)//�����±��ڲ�Ҫд��Χ
{
    int k,t=1;
    for(k=0;k<3;k++)
    {
        if(n==k)
            {continue;}
        else
            if(a[n]==a[k])
            {t=0;
            break;}
    }
    return(t);
}
void main()
{
    int maxa(int a[],int size);
    int weiyi(int a[3],int i);
    int t,i,j,n;
    int a[3],b[3];
    scanf("%d",&n);
    for(j=0; j<n; j++)
    {
        for(i=0; i<3; i++)
        {
            scanf("%d",&a[i]);
        }
        //printf("max=%d\n",maxa(a,3));//���maxa�Զ��庯������
        /*int o=0;
        printf("weiyi=%d\n",weiyi(a,o));*///���weiyi�Զ��庯������
        for(i=0;i<3;i++)
        {
            if(a[i]==maxa(a,3)&&weiyi(a,i)==1)//���ú���ʱֻд������
            {
                b[i]=0;
            }
            if(a[i]==maxa(a,3)&&weiyi(a,i)==0)
            {
                b[i]=1;
            }
            if(a[i]<maxa(a,3))
            {
            b[i]=maxa(a,3)-a[i]+1;
            }
        }
        for(i=0;i<3;i++)
        {
            printf("%d ",b[i]);
        }
        printf("\n");
    }
}
