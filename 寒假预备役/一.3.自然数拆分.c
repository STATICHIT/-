#include<stdio.h>
int n,l,a[10];//n<=8
void dfs(int sum,int data)//sum��ʾ��ǰ�ܺͣ�data��ʾ���ε��ú���sum���data����
{
    int i;
    if(sum == n)
    {
       for(i=0;i<l-1;i++)
        printf("%d+",a[i]);
       printf("%d\n",a[i]);//���һ��������û�мӺ�
       return;//�Ѿ��õ�һ��𰸣����ݵ���һ��
    }
    if(sum > n)
        return;//�����ˣ������ʣ��ص���һ��
    if(sum < n)
    {
        for(i=data; i<n; i++)//�ӵ�����1��ʼ����
        {
            a[l++]=i;
            dfs(sum+i,i);
            a[--l]=0;//����
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    dfs(0,1);//sum�����0���Ӽ�1��ʼ
    return 0;
}
