#include<bits/stdc++.h>
using namespace std;

struct msg
{
	double score;//分数
	char name[30];//学生姓名
}stu[100],mid[100],t;
int n;
void interface()//界面操作函数
{
	printf("\t\t*1.插入排序\n");
	printf("\t\t*2.冒泡排序\n");
	printf("\t\t*3.选择排序\n");
	printf("\t\t*4.快速排序\n");
	printf("\t\t*5.退出\n");
}
void copymsg()
{//信息复制到备用数组中，排序操作在备用数组中进行
	for(int i=1;i<=n;i++)
	{
		mid[i].score=stu[i].score;
		strcpy(mid[i].name,stu[i].name);
	}
}
void output()//输出检查
{
	for(int i=1;i<=n;i++)
	cout<<mid[i].name<<"\t"<<mid[i].score<<endl;
}
void swap(int a,int b)//将b的数据转移到a中
{
	mid[a].score=mid[b].score;
	strcpy(mid[a].name,mid[b].name);
}
void sort_insert()//插入排序
{
	int j;
	for(int i=2;i<=n;i++)
	{
		if(mid[i].score > mid[i-1].score)
		{
			swap(0,i);
			swap(i,i-1);
			for(j=i-2;mid[0].score > mid[j].score;j--)
			swap(j+1,j);
			swap(j+1,0);
		}
	}
}
void bubble_sort()//冒泡排序
{
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(mid[j].score < mid[j+1].score)
			{
				swap(0,j);
				swap(j,j+1);
				swap(j+1,0);
			}
		}
	}
}
void select_sort()//选择排序
{
	for(int i=1;i<n;i++)
	{
		int k=i;
		for(int j=i+1;j<=n;j++)
			if(mid[j].score > mid[k].score)k=j;//选出最大分数的数组元素下标
		if(k!=i){swap(0,k);swap(k,i);swap(i,0);}
	}
}
void fast_sort(int left,int right)//快速排序
{
	if(right<left)return;
	int i=left,j=right,temp=left;
	while (i < j)
	{
		while(mid[j].score < mid[temp].score && i < j)j--;//从右往左找，找到第一个大于基准分数的元素
		while(mid[i].score > mid[temp].score && i < j)i++;//从左往右找，找到第一个小于基准分数的元素
		if(i<j){swap(0,j);swap(j,i);swap(i,0);}
	}
	swap(0,i);swap(i,temp);swap(temp,0);
	fast_sort(left,i-1);
	fast_sort(i+1,right);
}
int main()
{
	int flag=0,stop=1;char k;
	cout<<"请输入将录入学生数据数量:";cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<"请分别输入第"<<i<<"个学生的姓名以及分数:"<<endl;
		cin>>stu[i].name>>stu[i].score;
	}
	cout<<"信息录入成功！"<<endl;
	k=getchar();
	interface();
	while(stop)
	{
		cout<<"-----------------------------------"<<endl;
		copymsg();
		cout<<"请选择需要进行的排序操作：";
		cin>>flag;
		switch (flag)
		{
		case 1:sort_insert();output();break;
		case 2:bubble_sort();output();break;
		case 3:select_sort();output();break;
		case 4:fast_sort(1,n);output();break;
		default:stop=0;break;
		}
		system("pause");
	}
	return 0;
}
