#include<stdio.h>
#include<Windows.h>
int main()
{
    //轰炸的消息次数
    int Message_Num;
    ///优化
    printf("￥￥￥提示：发送内容是你的粘贴板内容哦￥￥￥\n");
    printf("请输入你想要轰炸的次数\n");
    scanf("%d",&Message_Num);
    //第二步 寻找轰炸目标 -> qq窗口
    ///优化
    printf("请输入你想要轰炸的窗口(打开(单独)窗口，输入你给ta的备注)\n");
    char DuiXiang[1000];
    //窗口
    scanf("%s",&DuiXiang);
    HWND HongZhaChuangKou = FindWindow(NULL,DuiXiang);
    //第五步 实现第三步和第四步执行100次
    while(Message_Num>0)
    {
        //第三步 粘贴消息 WM-PASTE表示轰炸的消息是粘贴板上的消息
        SendMessage(HongZhaChuangKou,WM_PASTE,0,0);

        //第四步 发送消息:按下回车键
        SendMessage(HongZhaChuangKou,WM_KEYDOWN,VK_RETURN,0);
        Message_Num--;
    }
    return 0;
}

/*
Win32编程-->消息机制SendMessage
赋值消息
粘贴消息
发送消息
撤回消息
*/
