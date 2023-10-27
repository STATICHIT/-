#include<bits/stdc++.h>
using namespace std;

struct msg
{
	double score;//����
	char name[30];//ѧ������
}stu[100],mid[100],t;
int n;
void interface()//�����������
{
	printf("\t\t*1.��������\n");
	printf("\t\t*2.ð������\n");
	printf("\t\t*3.ѡ������\n");
	printf("\t\t*4.��������\n");
	printf("\t\t*5.�˳�\n");
}
void copymsg()
{//��Ϣ���Ƶ����������У���������ڱ��������н���
	for(int i=1;i<=n;i++)
	{
		mid[i].score=stu[i].score;
		strcpy(mid[i].name,stu[i].name);
	}
}
void output()//������
{
	for(int i=1;i<=n;i++)
	cout<<mid[i].name<<"\t"<<mid[i].score<<endl;
}
void swap(int a,int b)//��b������ת�Ƶ�a��
{
	mid[a].score=mid[b].score;
	strcpy(mid[a].name,mid[b].name);
}
void sort_insert()//��������
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
void bubble_sort()//ð������
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
void select_sort()//ѡ������
{
	for(int i=1;i<n;i++)
	{
		int k=i;
		for(int j=i+1;j<=n;j++)
			if(mid[j].score > mid[k].score)k=j;//ѡ��������������Ԫ���±�
		if(k!=i){swap(0,k);swap(k,i);swap(i,0);}
	}
}
void fast_sort(int left,int right)//��������
{
	if(right<left)return;
	int i=left,j=right,temp=left;
	while (i < j)
	{
		while(mid[j].score < mid[temp].score && i < j)j--;//���������ң��ҵ���һ�����ڻ�׼������Ԫ��
		while(mid[i].score > mid[temp].score && i < j)i++;//���������ң��ҵ���һ��С�ڻ�׼������Ԫ��
		if(i<j){swap(0,j);swap(j,i);swap(i,0);}
	}
	swap(0,i);swap(i,temp);swap(temp,0);
	fast_sort(left,i-1);
	fast_sort(i+1,right);
}
int main()
{
	int flag=0,stop=1;char k;
	cout<<"�����뽫¼��ѧ����������:";cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<"��ֱ������"<<i<<"��ѧ���������Լ�����:"<<endl;
		cin>>stu[i].name>>stu[i].score;
	}
	cout<<"��Ϣ¼��ɹ���"<<endl;
	k=getchar();
	interface();
	while(stop)
	{
		cout<<"-----------------------------------"<<endl;
		copymsg();
		cout<<"��ѡ����Ҫ���е����������";
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
