#include<stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))
    {

    switch(n)
    {
        case(0):printf("\"�˲���չ�\"\n");break;
        case(1):printf("˫�ֲ嶥������\n");break;
        case(2):printf("����ǰ�������\n");break;
        case(3):printf("����Ƣ���뵥��\n");break;
        case(4):printf("����ҷ������\n");break;
        case(5):printf("��ͷ����ȥ�ļ�\n");break;
        case(6):printf("��������������\n");break;
        case(7):printf("���չ��������\n");break;
        case(8):printf("����ٶ�������\n");break;
        default:printf("ѧ���㱨�����˰�\n");
    }}

    return 0;
}
