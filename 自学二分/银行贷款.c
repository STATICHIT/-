#include <bits/stdc++.h>//�������ÿ���±���Ϣ
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    //l��r�ֱ��ʾ���ʵ���Сֵ�����ֵ��Ҳ���ǳ�ʼ��Χ��
    double l = 0, r = 1000, mid = 0;
    //double�������ͣ����С��0.0001����ѭ����������ѭ��
    while (l < r - 0.0001) {
        mid = (l + r) / 2;//midΪ��Χ���м�ֵ��
        double w = a;//wΪδ������Ǯ����
        for (int i = 0; i < c; ++i)//ģ�⻹Ǯ���̡�
            w = w - b + w * (mid / 100);
        if (w > 0.0001)//��������������£��Ƿ�Ǯ���ꡣ
            r = mid;//Ǯδ���꣬����ƫ�󣬽���Χ���ֵ����Ϊ�м�ֵ��
        else l = mid;//Ǯ�����ˣ�����ƫС������Χ��Сֵ����Ϊ�м�ֵ��
    }
    printf("%0.1f\n", round(l * 10) / 10);
    return 0;
}
