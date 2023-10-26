#include<stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))
    {

    switch(n)
    {
        case(0):printf("\"八部金刚功\"\n");break;
        case(1):printf("双手插顶利三焦\n");break;
        case(2):printf("手足前后固肾腰\n");break;
        case(3):printf("调理脾肤须单举\n");break;
        case(4):printf("左肝右肺似射雕\n");break;
        case(5):printf("回头望足去心疾\n");break;
        case(6):printf("五劳七伤往后瞧\n");break;
        case(7):printf("凤凰展翅周身力\n");break;
        case(8):printf("两足顿顿饮嗜消\n");break;
        default:printf("学长你报错数了吧\n");
    }}

    return 0;
}
