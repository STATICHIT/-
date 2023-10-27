#include<stdio.h>
int a[100100];
int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m))
	{
		int i,j,min=0,max=0,mid=0;//这个min和max指最终需要输出的X的区间大小
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(min<a[i])//子序列和最小值应为序列中的最大值！！
			min=a[i];
		}
		for(i=0;i<n;i++)
		max+=a[i];////子序列和最大值应为整个序列所有数值之和！！
		mid=(max+min)/2;//本题需要找出最小的子序列之和,便令“最小的子序列之和”为二分查找的目的数值mid
		while(max>min)//进行二分查找循环
		{//二分查找循环内按题目要求编码寻找目的数值
			int s1=0,s2=1;
			for(i=0;i<n;i++)
			{
				if(s1+a[i]<=mid)
				s1+=a[i];//s1相当于一个子序列之和
				else//当s1加上a[i]将大于mid时说明此时的子序列之和已经超出要求，便将s1=a[i]，将其视作下一个子序列
				{
				s1=a[i];
				s2++;//s2表示子序列的个数
				}
			}
			if(s2<=m)
			max=mid;//当s2求出的子序列个数小于要求的个数时，表示此时mid大于目的数值，使得一些子序列中的元素多于目的子序列元素个数
			if(s2>m)
			min=mid+1;//当s2求出的子序列个数大于要求的个数时，表示此时mid小于目的数值，使得一些子序列中的元素少于目的子序列元素个数
			mid=(max+min)/2;//重新判定mid数值
		}//二分结束，结果为mid
		printf("%d\n",mid);
	}
	return 0;
}
