/*
#include<stdio.h>
void search(float (*p)[4],int n)
{
    int i,j,flag;
    for(j=0;j<n;j++)
    {
        flag=0;
        for(i=0;i<n;i++)
        {
            if(*(*(p+j)+i)<60)flag=1;
        }
        if(flag==1)
        {
            printf("No.%dfails,his scores are:\n",j+1);
            for(i=0;i<4;i++)
            {
                printf("%5.1f",*(*(p+j)+i));
            }
            printf("\n");
        }
    }
}
int main()
{
    float score[3][4]={{65,57,70,60},{58,87,90,81},{90,99,100,98}};
    search(score,3);
    return 0;
}
*/

/*
#include<stdio.h>
#include<math.h>
float integral(float(*p)(float),float a,float b,int n)
{int i;
 float x,h,s;
 h=(b-a)/n;
 x=a;
 s=0;
 for(i=1;i<=n;i++)
  {x=x+h;
   s=s+(*p)(x)*h;
  }
  return(s);
}
  float fsin(float x)
    {
        return sin(x);
    }
  float fcos(float x)
    {
        return cos(x);
    }
  float fexp(float x)
    {
        return exp(x);
    }
int main()
{
float a=0,b=1,c,(*p)(float);
int n=20;
p=fsin;
c=integral(p,a,b,n);
printf("The integral of sin(x) is:%f\n",c);

p=fcos;
c=integral(p,a,b,n);
printf("The integral of cos(x) is:%f\n",c);

p=fexp;
c=integral(p,a,b,n);
printf("The integral of exp(x) is:%f\n",c);

return 0;
}
*/

/*
#include<stdio.h>
void search(int *pa,int n,int *pmax,int *pflag)
{
    int i;
    *pmax=pa[0];
    for(i=0;i<n;i++)
    {
        if(pa[i]>*pmax)
        {
            *pmax=pa[i];
            *pflag=i;
        }
    }
}
int main()
{
    int a[10];
    for(int i=0;i<10;i++)
        scanf("%d",&a[i]);
    int max,flag;
    search(a,10,&max,&flag);
    printf("max=%d 其下标为%d\n",max,flag);
    return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
char* change(int x,int r)
{
	int len1,len2,i,t;
	char *y1,*y2;
	len1=2+(int)log((double)x)/log((double)r);
	y1=(char*)malloc(len1*sizeof(char));
	for(i=0;x!=0;i++)
	{
		t=x%r;
		if(t<10)
		*(y1+i)=(char)(t+48);
		else *(y1+i)=(char)(t+87);
		x=(int)x/r;
	}
	*(y1+i)='\0';
	len2=strlen(y1);
	y2=(char*)malloc(len2*sizeof(char));
	for(i=0;i<len2;i++)
	{
		*(y2+i)=*(y1+len2-i-1);
	}
	*(y2+i)='\0';
	return(y2);
}
int main()
{
	int x,r;
	char *y;
	scanf("%d,%d",&x,&r);
	y=change(x,r);
	printf(y);
	return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>
void sort(char (*s)[6])//排序
{
    int i,j;
    char temp[6],*t=temp;
    for (i=0; i<9; i++) //字符串正序排列操作
    {//冒泡排序
        for (j=0; j<9-i; j++)
        {
            if (strcmp(s[j],s[j+1])>0)
            {
                strcpy(t,s[j]);
                strcpy(s[j],s[+j+1]);
                strcpy(s[j+1],t);
            }
        }
    }
}
int main()
{
    char str[10][6];//用二维数组保存10个等长的字符串
    char (*p)[6];
    for (int i=0; i<10; i++)
        scanf("%s",str[i]);//一行一行地输入
    p=str;
    sort(p);

    for (int i=0; i<10; i++)
        printf("%s\n",str[i]);//一行一行地输出
    return 0;
}
*/

/*
#include<stdio.h>
float *search(float(*pointer)[4])
{
    float *pt;
    pt=NULL;
    for(int i=0;i<4;i++)
        if(*(*pointer+i)<60)pt=*pointer;
    return (pt);
}
int main()
{
    float score[][4]={{60,70,80,90},{56,89,67,88},{34,78,90,66}};
    float *p;
    int i,j;
    for(i=0;i<3;i++)
    {
        p=search(score+i);//调用search函数，如有不及格返回score[i][0]的地址，否则返回NULL
        if(p == *(score+i))
        {
            printf("No.%d不及格，他的分数是：\n",i);
            for(j=0;j<4;j++)
                printf("%5.2f ",*(p+j));//输出score[i][0]~score[i][3]的值
            printf("\n");//别忘了这里是%5.2f而不是%5.2d哦！
        }
    }
    return 0;
}
*/
#include<stdio.h>
float * search(float (*pointer)[4])
{
    float *pt;
    pt=NULL;
    for(int i=0;i<4;i++)
        if(*(* pointer+i)<60)pt=* pointer;
    return pt;
}
int main()
{
    float score[][4]={{90,80,70,60},{58,67,88,90},{34,45,67,77}};
    float *p;
    int i,j;
    for(i=0;i<3;i++)
    {
        p=search(score+i);
        if(p == score+i)
        {
            for(j=0;j<4;j++)
                printf("%5.2f ",*(p+j));
            printf("\n");
        }
    }
    return 0;
}
