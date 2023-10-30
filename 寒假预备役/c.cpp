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
	char stack[size];//数组类型与二叉树原数据域类型一致
}*s;
struct abc * create()//根据扩展先序遍历序列建立二叉树
{
	char k;   cin >> k;
	struct abc * tree1;
	if(k == '#')  tree1=NULL;//递归结束，建空树
	else
	{
		tree1=new abc;//开辟节点
		tree1->data=k;//数据域赋值
		tree1->left=create();//建立左子树
		tree1->right=create();//建立右子树
	}
	return tree1;
}
void initstack(struct stack * &s)//初始化栈
{
	s=new stack;//传递的s为指针类型，所以开辟空间获得初始指向空间
    s->top=s->base=0;
}
bool stackempty(struct stack* &s)//判断栈是否为空
{
    if(s->base == s->top) return true;//栈空
    else                  return false;//栈不空
}
bool stackfull(struct stack* &s)//判断栈是否已满
{
    if(s->top - s->base == size) return true;//栈满
    else                         return false;//栈不满
}
void export1(struct abc * tree,int flag)//遍历输出(递归实现)
{
	if(flag == 1)//先序遍历
	{
		cout<<tree->data<<" ";
		if(tree->left != NULL)  export1(tree->left,1);
		if(tree->right != NULL) export1(tree->right,1);
	}
	if(flag == 2)//中序遍历
	{
		if(tree->left != NULL)  export1(tree->left,2);
		cout<<tree->data<<" ";
		if(tree->right != NULL) export1(tree->right,2);
	}
	if(flag == 3)//后序遍历
	{
		if(tree->left != NULL)  export1(tree->left,3);
		if(tree->right != NULL) export1(tree->right,3);
		cout<<tree->data<<" ";
	}
	return ;
}
void push(struct stack * &s,struct abc * tree)/*入栈操作。以原有二叉树为基准，将树的数据域以及指针域全部复制到栈中。*/
{
	if(stackfull(s) == true) return ;//栈满则放弃入栈

	s->top++;//栈顶指针后移
}
void push(struct abc * tree)
{
	if(!stackfull(s) || tree != NULL)//若栈未满或当前遍历到的树节点不为空节点
	{
		s->stack[s->top]=tree->data;//将节点数据域压入栈中
		s->top++;//栈顶指针后移
	}
}
void pop()
{
	if(!stackempty(s))//若栈不空
	{
		cout<<s->stack[s->top-1]<<" ";//打印栈顶元素
		s->top--;//栈顶指针前移
	}
}
void inorder(struct abc * tree,struct stack*& s)//中序遍历非递归算法
{
	initstack(s);struct abc *q,*p=tree;
	while(p || stackempty(s) == false)
	{
		if(p->left !=NULL &&(p->left->right == NULL || p->left->left == NULL)) linshi=p;//提前做好回溯标记！
		if(p != NULL )
		{
			push(p);
			if(p->left != NULL) p=p->left;
			else
			{
				pop();//此时左子节点为空，出栈
				if(p->right != NULL) p=p->right;//指针指向右子节点
				else {pop();p=linshi->right;}//若右子节点为空，指针回溯！！！！！
			}
		}
		if(s->base == s->top) break;//栈空结束循环
	}
}
int main()
{
	cout<<"请输入目标二叉树的扩展先序序列（以“#”表示空指针）："<<endl;
	struct abc *t;
	tree=create();t=tree;
	cout<<"递归实现遍历操作："<<endl;
	cout<<"先序输出："<<endl;
	export1(tree,1);cout<<endl;
	cout<<"中序输出："<<endl;
	export1(tree,2);cout<<endl;
	cout<<"后序输出："<<endl;
	export1(tree,3);cout<<endl;
	cout<<"非递归算法实现："<<endl;
	inorder(t,s);
	system("pause");
	return 0;
}
