//1.�Ӽ�������һЩ�ַ������������͵�������ȥ��ֱ���û�����һ����#��Ϊֹ��
//��fgetc�����Ӽ�����������ַ���Ȼ����fgetc����д�������ļ��ϼ��ɡ�
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char ch,filename[100];
    printf("���������õ��ļ�����");
    scanf("%s",filename);
    getchar();
    if((fp=fopen(filename,"w"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    printf("������һ��׼�����浽���̷��ַ�������#��������");

    ch=getchar();//���մӼ�������ĵ�һ���ַ�
    while(ch != '#')
    {
        fputc(ch,fp);
        putchar(ch);
        ch=getchar();//�ٽ��ܴӼ��������һ���ַ�
    }
    fclose(fp);
    putchar(10);//����Ļ���һ�����з�

    return 0;
}
*/

//2.��һ�������ļ��е���Ϣ���Ƶ���һ�������ļ��С���Ҫ������������file1.dat�ļ��е����ݸ��Ƶ���һ������filel.2.dat�С�

//��file1.dat�ļ�����������ַ���Ȼ����������filel.2.dat�С�
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *in,*out;
    char ch,infile[100],outfile[100];
    printf("����������ļ�����:");
    scanf("%s",infile);
    printf("����������ļ�����:");
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

/*3.�Ӽ��̶������ɸ��ַ����������ǰ���ĸ��С��˳������Ȼ����ź�����ַ����͵������ļ��б��档

�Ӽ��̶���n���ַ����������һ����ά�ַ������У�ÿ��һά������һ���ַ���
���ַ������е�n���ַ�������ĸ˳�������ź�����ַ����Է����ַ�������
���ַ������е��ַ���˳�����*/
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

    for(i=0;i<n-1;i++)//ѡ�����򷨶��ַ�������
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
    if((fp=fopen("E:\\string.txt","w"))==NULL)//ע��ת���ַ�
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

//��д���³��򣬿��Դ��ļ�string.txt�ж����ַ�����������Ļ����ʾ
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
4.�Ӽ�������10��ѧ�����й����ݣ�Ȼ�������ת�浽�����ļ���ȥ��

����һ����10��Ԫ�صĽṹ�����飬�������10��ѧ�������ݡ���main��������10��ѧ�������ݣ���save����ʵ����������ѧ�����ݡ���fwrite����һ�����һ��ѧ�������ݡ�
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

//���³�����Լ���Ƿ����׼ȷ

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
    }//��������ļ�����ʽ����ȷ��������
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
5.��һ�������ļ�������һЩ��Ϣ��Ҫ���һ�ν�����������ʾ����Ļ�ϣ��ڶ��ΰ������Ƶ���һ���ļ��ϡ�

����˼·���������ⶼ���ѣ����ǰ��������������ͻ�������⣬��Ϊ�ڵ�һ�ζ������ļ����ļ�λ�ñ��
��ָ���ļ���ĩβ������ٽ��Ŷ����ݣ��������ļ�������־EOF��feof������ֵ����1��Ϊ�棩���޷��ٶ������ݡ������ڳ�������rewind����ʹλ��ָ�뷵���ļ���ͷ��
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
6.�ڴ����ļ��ϴ���10��ѧ������Ϣ��Ҫ�󽫵�1��3��5��7��9��ѧ����������������������Ļ����ʾ������

˼·��

����������ֻ�����ķ�ʽ��ָ���Ĵ����ļ���׼���Ӵ����ļ��ж�ȡѧ��ѧϰ
���ļ�λ�ñ��ָ���ļ��Ŀ�ͷ��Ȼ��Ӵ����ļ���ȡһ��ѧ������Ϣ����������ʾ����Ļ��
�ٽ��ļ�λ�ñ��ָ���ļ��е�3��5��7��9��ѧ���������Ŀ�ͷ���Ӵ����ļ�������Ӧѧ������Ϣ����������ʾ����Ļ�ϡ�
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
    for(i=0;i<10;i=i+2)//��ĿҪ����ǵ�3��5��7��9��ѧ��������
    {
        fseek(fp,i*sizeof(struct Student_type),0);//�ƶ��ļ�Ϊλ�ñ��
        fread(&stud[i],sizeof(struct Student_type),1,fp);//��һ�����ݿ鵽�ṹ�����
        printf("%-10s %4d %4d %-10s\n",stud[i].name,stud[i].num,stud[i].age,stud[i].addr);//����Ļ���
    }
    fclose(fp);
    return 0;
}



//ʵ��txt�ļ��Ķ��벢��д������һ��txt�ļ���~
#include<fstream>  //ifstream
#include<iostream>
#include<string>     //����getline()
//#include<cmath>
using namespace std;

int main(){
    string s;
    ofstream outf;
    ifstream inf;
    inf.open("d://in.txt");          //�ر�ע�⣬�����ǣ�//  ��˫б���~~
    //������ļ�
    outf.open("d://out.txt");
    while (getline(inf, s))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
    {
        outf << s << '\n';
        cout << s << endl;
    }
    inf.close();
    outf.close();
    return 0;
}
