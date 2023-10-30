#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int space,num,flag=0,low=0,front1=0;
int book[1000]={0};
char queue[1000]={'0'};
struct abc
{
	char data;
	struct abc *next;
}list[1000];
int loc(char a)
{
	for(int i=0;i<space;i++)
	{
		if(list[i].data == a)
		return i;
	}   return -1;
}
struct abc *front(char a,int k)
{
	struct abc * p;
	p=list[k].next;
	while(p->next != NULL)
	{p=p->next;}
	return p;
}
void output()
{
    cout<<"邻接表输出检查："<<endl;
	for(int i=0;i<space;i++)
	{
		struct abc p,*p1;p=list[i];
		if(p.next == NULL)
		cout<<p.data<<" ";
		else
		{
		p1=p.next;cout<<p.data<<" ";
		while (1)
		  {
			cout<<p1->data<<" ";
			if (p1->next != NULL)
			p1=p1->next;
			else break;
		  }
		} cout<<endl;
	}
}
void dfs(int k)
{
	if( flag >= space ) return;
	if(book[k] == 0)
	{
		flag++;
		cout<<list[k].data<<" ";
		book[k] = 1;
		struct abc *p = list[k].next;
		do
		{
			if (p != NULL)
			{
				if (book[loc(p->data)] == 0)
				{
					dfs(loc(p->data));
					if(p->next != NULL) {p = p->next;}
				}
				else
					if(p->next != NULL) {p = p->next;}
			}
			if(flag >= space ) break;
		}while(book[loc(p->data)] == 0);
	}
}
void bfs(char k)
{
	if(low > front1)     return;
	if(flag == 1)cout<<list[loc(k)].data<<" ";
	if(book[loc(k)] == 0)
	{
		book[loc(k)]=1;queue[front1++]=k;
	}
		struct abc *p=list[loc(k)].next;
		do
		{
			if(book[loc(p->data)] == 0){book[loc(p->data)]=1;queue[front1++]=p->data;}
			if(p->next != NULL) p=p->next;
		}while(book[loc(p->data)] == 0);
		flag=1;;bfs(queue[low++]);
}
int main()
{
	char a='A';
	cout<<"请输入顶点个数：";
	cin>>space;
	cout<<"生成的顶点分别为";
	for(int i=0;i<space;i++)
	{
		list[i].data=a+i;
		list[i].next=NULL;
		printf("%c ",list[i].data);
	}
	cout<<endl<<"请输入边数：";cin>>num;
    cout<<"请分别输入每边的左、右顶点代号:"<<endl;
	for(int i=0;i<num;i++)
	{
		char a,b;cin>>a>>b;
		struct abc *p,*q1,*q2;
		q1=new abc;q2=new abc;
		q1->data=b;q2->data=a;
		q1->next=q2->next=NULL;
		int k1=loc(a),k2=loc(b);
		p=list[k1].next;
		if (p == NULL) list[k1].next=q1;
		else
		{ p=front(a,k1);
          p->next=q1;   }
		p=list[k2].next;
		if (p == NULL) list[k2].next=q2;
		else
		{ p=front(a,k2);
          p->next=q2;  }
	}
	output();
	printf("深度优先遍历得到序列为：");
	dfs(0);cout<<endl;
	for(int i=0;i<=space;i++) book[i]=0;flag=0;
	printf("广度优先遍历得到序列为：");
	bfs('A');
	system("pause");
	return 0;
}
