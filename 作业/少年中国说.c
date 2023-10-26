#include<stdio.h>
#include<string.h>
int main()
{
    char s[50];///文字可以用字符串保存但是一个字占两个字节
    char x[18][50]={{"不在他人，而全在我少年。"},{"少年富则国富；"},{"少年独立则国独立；"},{"少年进步则国进步；"},{"少年雄于地球则国雄于地球。"},{"其道大光。"},{"一泻汪洋。"},{"鳞爪飞扬。"},{"百兽震惶。"},{"风尘吸张。"},{"矞矞皇皇。"},{"有作其芒。"},{"地履其黄。"},{"横有八荒。"},{"来日方长。"},{"我少年中国，与天不老！"},{"我中国少年，与国无疆！"}};///好坑的感叹号！！!!

    char y[18][50]={{"今日之责任，"},{"少年智则国智，"},{"少年强则国强，"},{"少年自由则国自由，"},{"少年胜于欧洲则国胜于欧洲，"},{"红日初升，"},{"河出伏流，"},{"潜龙腾渊，"},{"乳虎啸谷，"},{"鹰隼试翼，"},{"奇花初胎，"},{"干将发硎，"},{"天戴其苍，"},{"纵有千古，"},{"前途似海，"},{"美哉,"},{"壮哉,"}};
    while(~scanf("%s",s))
    {
        if(strcmp(s,y[0]) == 0)
        {
            printf(x[0]);
            printf("\n");
        }
        else if(strcmp(s,y[1]) == 0)
        {
            printf(x[1]);
            printf("\n");
        }
        else if(strcmp(s,y[2]) == 0)
        {
            printf(x[2]);
            printf("\n");
        }
        else if(strcmp(s,y[3]) == 0)
        {
            printf(x[3]);
            printf("\n");
        }
        else if(strcmp(s,y[4]) == 0)
        {
            printf(x[4]);
            printf("\n");
        }
        else if(strcmp(s,y[5]) == 0)
        {
            printf(x[5]);
            printf("\n");
        }
        else if(strcmp(s,y[6]) == 0)
        {
            printf(x[6]);
            printf("\n");
        }
        else if(strcmp(s,y[7]) == 0)
        {
            printf(x[7]);
            printf("\n");
        }
        else if(strcmp(s,y[8]) == 0)
        {
            printf(x[8]);
            printf("\n");
        }
        else if(strcmp(s,y[9]) == 0)
        {
            printf(x[9]);
            printf("\n");
        }
        else if(strcmp(s,y[10]) == 0)
        {
            printf(x[10]);
            printf("\n");
        }
        else if(strcmp(s,y[11]) == 0)
        {
            printf(x[11]);
            printf("\n");
        }
        else if(strcmp(s,y[12]) == 0)
        {
            printf(x[12]);
            printf("\n");
        }
        else if(strcmp(s,y[13]) == 0)
        {
            printf(x[13]);
            printf("\n");
        }
        else if(strcmp(s,y[14]) == 0)
        {
            printf(x[14]);
            printf("\n");
        }
        else if(strcmp(s,y[15]) == 0)
        {
            printf(x[15]);
            printf("\n");
        }
        else if(strcmp(s,y[16]) == 0)
        {
            printf(x[16]);
            printf("\n");
        }
        memset(s,0,20);
    }
    return 0;
}
