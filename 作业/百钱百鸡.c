//��Ǯ�ټ��� �й��Ŵ���ѧ�����������ġ��㾭���������������
//����Ǯ�ټ����⡱�����̣�cock��һ��ֵǮ�壻��ĸ��hen��һ��ֵǮ����
//����(chicken)����ֵǮһ�����ʵ�ְ�Ǯ��ټ������̡�ĸ���������Σ�
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
