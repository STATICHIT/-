#include<stdio.h>
#include<math.h>
int a[100010],b[100010];//�����������飬�ֱ𴢴�ÿ��ѧУ�ķ����ߣ���ÿ��ͬѧ�Ĺ���
int min(int x,int y)
{
    return(x>y?y:x);
}
void sort(int * arr,int n)
{
    int i,j,t;
    for(j=0;j<n-1;j++)
        for(i=j;i<n-j-1;i++)
        if(arr[i]>arr[i+1])
          {
            t=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=t;
          }
}
int main()
{
	int n,m;//n��ѧУ����m��ѧ����
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	for(int i=0; i<m; i++)
		scanf("%d",&b[i]);
	sort(a,n);//��ÿ��ѧУ�ķ����ߴ�С��������
	int ans=0;
	for(int i=0; i<m; i++)//��ÿ���˽����ж�
	{
		int left=0,right=n-1;
		while(left<=right)
		{
			int mid=(left+right)/2;//ȡ���ҷ�Χ���м�ֵ
			if(b[i]>=a[mid])//���¼ȡ�����������еĵ�mid��Ԫ��С�ڻ������λͬѧ�ķ���
				left=mid+1;//��߽��������
			else
				right=mid-1;//�ұ߽��������
		}
		if(b[i]<=a[0])//���������ѧ����������ͷ�ѧϰ¼ȡ��������
		{
			ans=ans+a[0]-b[i];//�����¼ȡ������ȥ��ѧ������
		}
		else
		{
			ans=ans+min(abs(a[left-1]-b[i]),abs(a[left]-b[i]));///������������ֵ����С
		}
	}
	printf("%d",ans);
	return 0;
}
