//1.从键盘输入一些字符，并把它们送到磁盘上去，直到用户输入一个“#“为止。
//用fgetc函数从键盘逐个输入字符，然后用fgetc函数写到磁盘文件上即可。
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char ch,filename[100];
    printf("请输入所用的文件名：");
    scanf("%s",filename);
    getchar();
    if((fp=fopen(filename,"w"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    printf("请输入一个准备储存到磁盘发字符串（以#结束）：");

    ch=getchar();//接收从键盘输入的第一个字符
    while(ch != '#')
    {
        fputc(ch,fp);
        putchar(ch);
        ch=getchar();//再接受从键盘输入的一个字符
    }
    fclose(fp);
    putchar(10);//向屏幕输出一个换行符

    return 0;
}
*/

//2.将一个磁盘文件中的信息复制到另一个磁盘文件中。今要求将上例建立的file1.dat文件中的内容复制到另一个磁盘filel.2.dat中。

//从file1.dat文件中逐个读入字符，然后逐个输出到filel.2.dat中。
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *in,*out;
    char ch,infile[100],outfile[100];
    printf("请输入读入文件名字:");
    scanf("%s",infile);
    printf("请输入读出文件名字:");
    scanf("%s",outfile);
    if((in=fopen(infile,"r"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    if((out=fopen(outfile,"w"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    ch=fgetc(in);
    while(!feof(in))
    {
        fputc(ch,out);
        putchar(ch);
        ch=fgetc(in);
    }
    putchar(10);
    fclose(in);
    fclose(out);
    return 0;
}
*/

/*3.从键盘读入若干个字符串，对它们按字母大小的顺序排序，然后把排好序的字符串送到磁盘文件中保存。

从键盘读入n个字符串，存放在一个二维字符数组中，每个一维数组存放一个字符串
对字符数组中的n个字符串按字母顺序排序，排好序的字符串仍放在字符数组中
将字符数组中的字符串顺序输出*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fp;

    int i,j,k,n=3;
    char str[n][10],temp[10];
    printf("Enter strings:\n");
    for(i=0;i<n;i++)
        gets(str[i]);

    for(i=0;i<n-1;i++)//选择排序法对字符串排序
    {
        k=i;
        for(j=i+1;j<n;j++)
            if(strcmp(str[k],str[j])>0)k=j;
        if(k!=i)
        {
            strcpy(temp,str[i]);
            strcpy(str[i],str[k]);
            strcpy(str[k],temp);
        }
    }
    if((fp=fopen("E:\\string.txt","w"))==NULL)//注意转义字符
    {
        printf("cannot open file\n");
        exit(0);
    }
    printf("\nThe new sequence:\n");
    for(i=0;i<n;i++)
    {
        fputs(str[i],fp);
        fputs("\n",fp);
        printf("%s\n",str[i]);
    }
    return 0;
}
*/

//编写以下程序，可以从文件string.txt中读回字符串，并在屏幕上显示
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
   FILE *fp;
   char str[3][10];
   int i=0;
   if((fp=fopen("E:\\string.txt","r"))==NULL)
   {
       printf("cannot open file\n");
       exit(0);
   }
   while(fgets(str[i],10,fp)!=NULL)
   {
       printf("%s",str[i]);
       i++;
   }
   fclose(fp);
   return 0;
}
*/

/*
4.从键盘输入10个学生的有关数据，然后把它们转存到磁盘文件上去。

定义一个有10个元素的结构体数组，用来存放10个学生的数据。从main函数输入10个学生的数据，用save函数实现向磁盘输出学生数据。用fwrite函数一次输出一个学生的数据。
*/
/*
#include<stdio.h>
#define SIZE 10

struct Student_type
{
    char name[10];
    int num;
    int age;
    char addr[15];
}stud[SIZE];

void save()
{
    FILE * fp;
    int i;
    if((fp=fopen("stu.dat","wb"))==NULL)
    {
        printf("cannot open file\n");
        return;
    }
    for(i=0;i<SIZE;i++)
        if(fwrite(&stud[i],sizeof(struct Student_type),1,fp)!=1)
            printf("file write error\n");
    fclose(fp);
}

int main()
{
    int i;
    printf("Please enter data of students :\n");
    for(i=0;i<SIZE;i++)
    scanf("%s%d%d%s",stud[i].name,&stud[i].num,&stud[i].age,stud[i].addr);
    save();
    return 0;
}
*/

//以下程序可以检查是否读入准确

/*
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct Student_type
{
    char name[10];
    int num;
    int age;
    char addr[15];
}stud[SIZE];

int main()
{
    int i;
    FILE * fp;
    if((fp=fopen("stu.dat","rb"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }//当输入的文件名格式不正确就用上啦
    for(i=0;i<SIZE;i++)
    {
        fread(&stud[i],sizeof(struct Student_type),1,fp);
        printf("%-10s %4d %4d %-15s\n",stud[i].name,stud[i].num,stud[i].age,stud[i].addr);
    }
    fclose(fp);
    return 0;
}
*/

/*
5.有一个磁盘文件，内有一些信息。要求第一次将它的内容显示在屏幕上，第二次把它复制到另一个文件上。

解题思路：两个问题都不难，但是把两者连续做，就会出现问题，因为在第一次读入完文件后，文件位置标记
已指到文件的末尾，如果再接着读数据，就遇到文件结束标志EOF，feof函数的值等于1（为真），无法再读入数据。必须在程序中用rewind函数使位置指针返回文件开头。
*/
/*
#include<stdio.h>
int main()
{
    FILE *fp1,*fp2;
    char ch;
    if((fp1=fopen("file1.dat","r"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    if((fp2=fopen("file2.dat","w"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    ch=fgetc(fp1);
    while(!feof(fp1))
    {
        putchar(ch);
        ch=fgetc(fp1);
    }
    putchar(10);
    rewind(fp1);
    ch=fgetc(fp1);
    while(!feof(fp1))
    {
        fputc(ch,fp2);
        ch=fgetc(fp1);
    }
    fclose(fp1);fclose(fp2);
    return 0;
}
*/

/*
6.在磁盘文件上存有10个学生的信息，要求将第1，3，5，7，9个学生数据输入计算机，并在屏幕上显示出来。

思路：

按“二进制只读”的方式打开指定的磁盘文件，准备从磁盘文件中读取学生学习
将文件位置标记指向文件的开头，然后从磁盘文件读取一个学生的信息，并把它显示在屏幕上
再将文件位置标记指向文件中第3，5，7，9个学生数据区的开头，从磁盘文件读入相应学生的信息，并把它显示在屏幕上。
*/


#include<stdio.h>
#include<stdlib.h>

struct Student_type
{
    char name[10];
    int num;
    int age;
    char addr[15];
}stud[10];

int main()
{
    int i;
    FILE *fp;
    if((fp=fopen("stu.dat","rb"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    for(i=0;i<10;i=i+2)//题目要求的是第3，5，7，9个学生的数据
    {
        fseek(fp,i*sizeof(struct Student_type),0);//移动文件为位置标记
        fread(&stud[i],sizeof(struct Student_type),1,fp);//读一个数据块到结构体变量
        printf("%-10s %4d %4d %-10s\n",stud[i].name,stud[i].num,stud[i].age,stud[i].addr);//在屏幕输出
    }
    fclose(fp);
    return 0;
}



//实现txt文件的读入并重写入另外一个txt文件中~
#include<fstream>  //ifstream
#include<iostream>
#include<string>     //包含getline()
//#include<cmath>
using namespace std;

int main(){
    string s;
    ofstream outf;
    ifstream inf;
    inf.open("d://in.txt");          //特别注意，这里是：//  是双斜杠喔~~
    //打开输出文件
    outf.open("d://out.txt");
    while (getline(inf, s))      //getline(inf,s)是逐行读取inf中的文件信息
    {
        outf << s << '\n';
        cout << s << endl;
    }
    inf.close();
    outf.close();
    return 0;
}
