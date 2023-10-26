#include<stdio.h>
#include<string.h>
void main()
{
    char s[1000];
    gets(s);
    char q[1000];
    gets(q);
    int i,j,k;
    for(i=0; i<strlen(s); i++)
    {
        k=0;//没有给k初始化使得它的初值是个随机值而卡了很久这道题
        for(j=0; j<strlen(q); j++)
        {
            if(s[i]==q[j])
                k++;
            else
                continue;
        }
        if(k==0)
            printf("%c",s[i]);
        else
            continue;

    }
    printf("\n");

}
/*震惊了，一下午被这道题烦的要死，
还做不出来，都要给我整哭了，然后
晚课就在按照学长的方法理解另一道题，
正好下课把那道题搞定了，心情嘛就比
较好，回寝室之后又看了一下这道题，
一下子就找到了问题，然后改了一个地方
，就正确了妈呀，还直是，状态不好啥都
做不成，思绪乱心情一好状态，对，思绪
就很清晰!!!*/
