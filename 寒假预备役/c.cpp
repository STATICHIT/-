#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define size 10000
int flag1=1;
struct abc
{
	char data;
	struct abc *left,*right;
}*tree,*linshi,*t;
struct stack
{
	int base,top;
	char stack[size];//���������������ԭ����������һ��
}*s;
struct abc * create()//������չ����������н���������
{
	char k;   cin >> k;
	struct abc * tree1;
	if(k == '#')  tree1=NULL;//�ݹ������������
	else
	{
		tree1=new abc;//���ٽڵ�
		tree1->data=k;//������ֵ
		tree1->left=create();//����������
		tree1->right=create();//����������
	}
	return tree1;
}
void initstack(struct stack * &s)//��ʼ��ջ
{
	s=new stack;//���ݵ�sΪָ�����ͣ����Կ��ٿռ��ó�ʼָ��ռ�
    s->top=s->base=0;
}
bool stackempty(struct stack* &s)//�ж�ջ�Ƿ�Ϊ��
{
    if(s->base == s->top) return true;//ջ��
    else                  return false;//ջ����
}
bool stackfull(struct stack* &s)//�ж�ջ�Ƿ�����
{
    if(s->top - s->base == size) return true;//ջ��
    else                         return false;//ջ����
}
void export1(struct abc * tree,int flag)//�������(�ݹ�ʵ��)
{
	if(flag == 1)//�������
	{
		cout<<tree->data<<" ";
		if(tree->left != NULL)  export1(tree->left,1);
		if(tree->right != NULL) export1(tree->right,1);
	}
	if(flag == 2)//�������
	{
		if(tree->left != NULL)  export1(tree->left,2);
		cout<<tree->data<<" ";
		if(tree->right != NULL) export1(tree->right,2);
	}
	if(flag == 3)//�������
	{
		if(tree->left != NULL)  export1(tree->left,3);
		if(tree->right != NULL) export1(tree->right,3);
		cout<<tree->data<<" ";
	}
	return ;
}
void push(struct stack * &s,struct abc * tree)/*��ջ��������ԭ�ж�����Ϊ��׼���������������Լ�ָ����ȫ�����Ƶ�ջ�С�*/
{
	if(stackfull(s) == true) return ;//ջ���������ջ

	s->top++;//ջ��ָ�����
}
void push(struct abc * tree)
{
	if(!stackfull(s) || tree != NULL)//��ջδ����ǰ�����������ڵ㲻Ϊ�սڵ�
	{
		s->stack[s->top]=tree->data;//���ڵ�������ѹ��ջ��
		s->top++;//ջ��ָ�����
	}
}
void pop()
{
	if(!stackempty(s))//��ջ����
	{
		cout<<s->stack[s->top-1]<<" ";//��ӡջ��Ԫ��
		s->top--;//ջ��ָ��ǰ��
	}
}
void inorder(struct abc * tree,struct stack*& s)//��������ǵݹ��㷨
{
	initstack(s);struct abc *q,*p=tree;
	while(p || stackempty(s) == false)
	{
		if(p->left !=NULL &&(p->left->right == NULL || p->left->left == NULL)) linshi=p;//��ǰ���û��ݱ�ǣ�
		if(p != NULL )
		{
			push(p);
			if(p->left != NULL) p=p->left;
			else
			{
				pop();//��ʱ���ӽڵ�Ϊ�գ���ջ
				if(p->right != NULL) p=p->right;//ָ��ָ�����ӽڵ�
				else {pop();p=linshi->right;}//�����ӽڵ�Ϊ�գ�ָ����ݣ���������
			}
		}
		if(s->base == s->top) break;//ջ�ս���ѭ��
	}
}
int main()
{
	cout<<"������Ŀ�����������չ�������У��ԡ�#����ʾ��ָ�룩��"<<endl;
	struct abc *t;
	tree=create();t=tree;
	cout<<"�ݹ�ʵ�ֱ���������"<<endl;
	cout<<"���������"<<endl;
	export1(tree,1);cout<<endl;
	cout<<"���������"<<endl;
	export1(tree,2);cout<<endl;
	cout<<"���������"<<endl;
	export1(tree,3);cout<<endl;
	cout<<"�ǵݹ��㷨ʵ�֣�"<<endl;
	inorder(t,s);
	system("pause");
	return 0;
}
