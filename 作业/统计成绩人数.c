#include<stdio.h>
int main(void)
{
    double scores;/*����score�������*/
    /*x:�����ѧ��������y:�ϸ��ѧ��������z:�������ѧ������*/
    int x,y,z;
    x=0;
    y=0;
    z=0;
    printf("enter scores:");
    scanf("%lf",&scores);
    while(scores>0){/*ѭ������0���߸�������*/
        if(scores>85){/*�ж���������*/
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
