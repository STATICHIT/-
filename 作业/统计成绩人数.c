#include<stdio.h>
int main(void)
{
    double scores;/*定义score这个函数*/
    /*x:优秀的学生人数，y:合格的学生人数，z:不及格的学生人数*/
    int x,y,z;
    x=0;
    y=0;
    z=0;
    printf("enter scores:");
    scanf("%lf",&scores);
    while(scores>0){/*循环遇到0或者负数结束*/
        if(scores>85){/*判断满足条件*/
            x=x+1;
        }
        else if((scores>=60)&&(scores<=84)){
            y=y+1;
        }
        else{
            z=z+1;
        }
        scanf("%lf",&scores);
    }
    printf(">=85:%d\n ",x);
    printf("60-84:%d \n",y);
    printf("<60:%d \n",z);
    return 0;

    }
