#include<stdio.h>
#include<Windows.h>
int main()
{
    //��ը����Ϣ����
    int Message_Num;
    ///�Ż�
    printf("��������ʾ���������������ճ��������Ŷ������\n");
    printf("����������Ҫ��ը�Ĵ���\n");
    scanf("%d",&Message_Num);
    //�ڶ��� Ѱ�Һ�ըĿ�� -> qq����
    ///�Ż�
    printf("����������Ҫ��ը�Ĵ���(��(����)���ڣ��������ta�ı�ע)\n");
    char DuiXiang[1000];
    //����
    scanf("%s",&DuiXiang);
    HWND HongZhaChuangKou = FindWindow(NULL,DuiXiang);
    //���岽 ʵ�ֵ������͵��Ĳ�ִ��100��
    while(Message_Num>0)
    {
        //������ ճ����Ϣ WM-PASTE��ʾ��ը����Ϣ��ճ�����ϵ���Ϣ
        SendMessage(HongZhaChuangKou,WM_PASTE,0,0);

        //���Ĳ� ������Ϣ:���»س���
        SendMessage(HongZhaChuangKou,WM_KEYDOWN,VK_RETURN,0);
        Message_Num--;
    }
    return 0;
}

/*
Win32���-->��Ϣ����SendMessage
��ֵ��Ϣ
ճ����Ϣ
������Ϣ
������Ϣ
*/
