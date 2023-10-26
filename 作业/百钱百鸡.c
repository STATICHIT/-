//百钱百鸡： 中国古代数学家张丘建在他的《算经》中提出了著名的
//“百钱百鸡问题”：鸡翁（cock）一，值钱五；鸡母（hen）一，值钱三；
//鸡雏(chicken)三，值钱一；编程实现百钱买百鸡，求翁、母、雏各几何？
#include<stdio.h>
int main()
{
    int cock,hen,chicken;
    for(cock=0; cock<=20; cock++)
    {
        for(hen=0; hen<=33; hen++)
        {
            chicken=100-cock-hen;
            if(cock*5+hen*3+chicken/3==100&&chicken>0&&chicken<=100&&chicken%3==0)
                printf("%d,%d,%d\n",cock,hen,chicken);
        }

    }
    return 0;
}
