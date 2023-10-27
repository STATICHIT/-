#include<stdio.h>
int main()
{
    int year,month,day,num,no;
    int leap;
    num=0;
    printf("请输入年,月,日\n");
    scanf("%d,%d,%d",&year,&month,&day);
    if(month==1)
      {
        printf("%d\n",day);
      }
    else
    {
        int i;
    for(i=1; i<month; i++)
        switch(i)
        {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        num=num+31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        num=num+30;
        break;
    case 2:
        num=num+28;
        break;
        }

    }
    if((year%4==0&&year%100!=0&&month>2)||(year%400==0&&month>2))
    {
        num=num+1;
    }
    no=num+day;
    printf("%d年%d月%d日是这一年的第%d天\n",year,month,day,no);

    return 0;
}
