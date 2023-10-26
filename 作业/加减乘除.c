#include<stdio.h>
int main()
{
    float date1,date2,s;
    char op;
    scanf("%f,%f",&date1,&date2);
    getchar();
    scanf("%c",&op);
    switch(op)
    {
    case'+':
        printf("%f+%f=%f",date1,date2,date1+date2);
        break;
    case'-':
        printf("%f-%f=%f",date1,date2,date1-date2);
        break;
    case'*':
        printf("%f*%f=%f",date1,date2,date1*date2);
        break;
    case'/':
        printf("%f/%f=%f",date1,date2,date1/date2);
        break;
    default:
        printf("error");
    }
    return 0;
}
