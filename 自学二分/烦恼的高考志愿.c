#include<stdio.h>
#include<math.h>
int a[100010],b[100010];//定义两个数组，分别储存每个学校的分数线，和每个同学的估分
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
	int n,m;//n是学校数，m是学生数
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	for(int i=0; i<m; i++)
		scanf("%d",&b[i]);
	sort(a,n);//把每个学校的分数线从小到大排序
	int ans=0;
	for(int i=0; i<m; i++)//对每个人进行判断
	{
		int left=0,right=n-1;
		while(left<=right)
		{
			int mid=(left+right)/2;//取查找范围的中间值
			if(b[i]>=a[mid])//如果录取分数线数组中的第mid个元素小于或等于那位同学的分数
				left=mid+1;//左边界就往右移
			else
				right=mid-1;//右边界就往左移
		}
		if(b[i]<=a[0])//特殊情况：学生分数比最低分学习录取分数还低
		{
			ans=ans+a[0]-b[i];//用最低录取分数减去该学生分数
		}
		else
		{
			ans=ans+min(abs(a[left-1]-b[i]),abs(a[left]-b[i]));///加上两个绝对值中最小
		}
	}
	printf("%d",ans);
	return 0;
}
