//��Ŀ������ K: ����
//����
//����ͬѧ�Ƕ�����Ŀ�Ѿ�����Ϥ�ˣ��Ͳ������ˣ����������ĿҪ�ú�����Ŷ��
//�涨Ҫ�õ�
//int isLeap(int year){
//����һ���������� }
//�����ʹ�����Ϻ��������ֱ�����󣡣�
//
//��ʽ
//�����ʽ
//����һ�����   �����ж���
//�����ʽ
//�����������yes���������no
#include<stdio.h>
void main()
{
    int N;
    int isLeap(int N);//һ��Ҫ�ǵ�д����ʹ�õĺ�������
    while(~scanf("%d",&N))
      {if(isLeap(N)==1)
        {printf("yes\n");}
        if(isLeap(N)==0)//���ú���ʱ���ô����������ͷ���
                        //��дisLeap(N),������int isLeap(N)
            {printf("no\n");}

}}
int isLeap(int N)
{
    if(N%4!=0)
        return(0);
    else
        if(N%4==0&&N%100!=0)//if�в������ǣ�=�����ǣ�==
        return(1);
    else
        if(N%400==0)
        return(1);
    else
        return(0);

}
