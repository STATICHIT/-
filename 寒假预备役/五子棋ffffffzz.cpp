#include<iostream>
#include<graphics.h>
#include<cstdio>
#include<algorithm>
#include<conio.h>
#include<mmsystem.h>
#pragma comment (lib,"winmm.lib")
#define inf1 999999999;
using namespace std;/*��������*/

/*��������ѡ�񼰲���*/
void bgm()
{
	mciSendString("open ./������.mp3", NULL, 0, NULL);
	mciSendString("play ./������.mp3", NULL, 0, NULL);
}

struct abc
{
	int x, y;/*que[1]Ϊ���ӵ��������У�que[2]Ϊ���ӵ���������*/
}que[3][10000],loc[3];/*loc[1]�洢���һ�����ӵ�λ�ã�loc[2]�洢���һ�����ӵ�λ�ã����������ж��Ƿ�ʤ��*/


int book[1000][1000],book2[1000][1000],mrk1x[1000]={0}, mrk1y[1000]={0}, mrk2x[1000]={0}, mrk2y[1000]={0};
/*book[][]��¼����,book2[][]�������̲������̵��޸ģ�����ʧ��*/
/*mrkx[],mrky[]�ֱ��¼���ӡ����ӵ�x��y���꣬����������ջ*/

int x1 = 22, x2 = 38, x3 = 30, ys1 = 15, ys2 = 25, yx1 = 45, yx2 = 35;
/*x1��x2��x3�ֱ�洢�����δ������ҵ���������ĺ����꣨������������ͬ����ys��yx�ֱ�洢�ϡ��������ε�������*/

int flag = 1/*��־������ɫ��1Ϊ���ӣ�2Ϊ����*/, flag1 = 1/*��־����ģʽ.10Ϊ��꣬20Ϊ����*/;
int  Flag = 0, flag3 = 0, step1 = 0, step2 = 0, k = 0;
/*Flag�ж��ķ���ʤ��flag3�ж��Ƿ�ʤ����fflag����Ƿ��Ѿ���������,k���ڷ�ֹ��λ���*/

//int next[8][2] = { {-30,0},{30,0},{0,-30},{0,30},{-30,-30},{-30,30},{30,30},{30,-30} };
///*�����������飺�ֱ�Ϊ���ҡ��ϡ��¡����ϡ����¡����¡�����*/

/*ѡ�����ģʽ*/
void modern1()/*���ò���ģʽ*/
{
	IMAGE img1;
	loadimage(&img1, "./ģʽ2.png", 516, 756);
	putimage(0, 0, &img1);
	while (1)
	{
		if (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			/*���������Ϣ*/
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				//printf("x=%d y=%d\n", msg.x, msg.y);
				if (msg.x >= 0 && msg.x <= 510 && msg.y >= 272 && msg.y <= 440) flag1 = 10;
				if (msg.x >= 0 && msg.x <= 510 && msg.y >= 470 && msg.y <= 640) flag1 = 20;
				break;
			}
		}
		if (flag1 != 1)  break;
	}
}

/*��ͼ����*/
void chess_mouse(int x, int y, int flag1)/*����.flag=1ʱ�º��壬flag=2ʱ�°��塣*/
{
	if (flag1 == 1) { setbkmode(TRANSPARENT); setfillcolor(BLACK); fillcircle(x, y, 12); }
	if (flag1 == 2) { setbkmode(TRANSPARENT); setfillcolor(WHITE); fillcircle(x, y, 12); }
}

/*���̲�����ָʾ��꺯��*/
void cursor()
{
	setlinecolor(RED);
	setlinestyle(PS_SOLID, 3);
	/*������*/
	line(x1, ys1,x2, ys1);
	line(x1, ys1,x3, ys2);
	line(x2, ys1,x3, ys2);
	/*������*/
	line(x1, yx1,x2, yx1);
	line(x1, yx1,x3, yx2);
	line(x2, yx1,x3, yx2);
}

/*��������*/
void map1()
{
	IMAGE imag;
	loadimage(&imag, "./��Ϸ����1.png", 850, 600);
	putimage(0, 0, &imag);
	/*������*/
	setfillcolor(RGB(6, 128, 215));
	fillroundrect(610, 40, 830, 300, 10, 10);
	/*�����*/
	setfillcolor(RGB(6, 128, 215));
	fillroundrect(578, 380, 830, 500, 10, 10);
	setbkmode(TRANSPARENT);
	settextstyle(0, 20, "����");
	settextcolor(BLACK);
	outtextxy(660, 415, "����");
	settextstyle(0, 10, "��������");
	settextcolor(WHITE);
	outtextxy(580, 440, "(���̲��������¡�=�����壩");
	/*����һ�� 18*18������*/
	for (int i = 2; i < 600; i += 2)
	{
		if (i % 30 == 0)
		{
			setlinecolor(BLACK);
			setlinestyle(PS_SOLID, 2);
			line(30, i, 570, i);/*����*/
			line(i, 30, i, 570);/*����*/
		}
	}
}

/*����ҳ��*/
void end_()
{
	initgraph(500, 725);
	IMAGE img[2];
	loadimage(&img[0], "./��ʤ2��.png", 500, 725);
	if(Flag == 1)putimage(0, 0, &img[0]);
	loadimage(&img[1], "./��ʤ2��.png", 500, 725);
	if(Flag == 2)putimage(0, 0, &img[1]);
	Sleep(3000);
	closegraph();
}

/*�������*/
void retract()
{
	for (int i = 30; i <= 570; i += 30)
	{
		for (int j = 30; j <= 570; j += 30)
		{
			if (book[j][i] == 10 || book[j][i] == 11) { setfillcolor(BLACK); fillcircle(j, i, 12); }
			if (book[j][i] == 20 || book[j][i] == 21) { setfillcolor(WHITE); fillcircle(j, i, 12); }
		}
	}
}

/*�����ж��Ƿ�ʤ��*/
int bfs(int a)
{
	cout << "a" << endl;
	int next[8][2] = { {-30,0},{30,0},{0,-30},{0,30},{-30,-30},{-30,30},{30,30},{30,-30} };
	/*�����������飺�ֱ�Ϊ���ҡ��ϡ��¡����ϡ����¡����¡�����*/
	int head[3] = { 1,1,1 }, tail[3] = { 1,1,1 }, sum = 1;/*sum����Ƿ��Ѿ���������*/
	int fflag = 0;
	que[a][tail[a]].x = loc[a].x; que[a][tail[a]].y = loc[a].y; tail[a]++;
	if (a == 1)book2[que[a][head[a]].x][que[a][head[a]].y] = 11;
	if (a == 2)book2[que[a][head[a]].x][que[a][head[a]].y] = 21;
	while (head[a] < tail[a])
	{
		cout << "b" << endl;
		for (int k = 0; k <= 7; k++)
		{
			cout << "c" << endl;
			sum = 1;
			int tx = que[a][head[a]].x + next[k][0], ty = que[a][head[a]].y + next[k][1];
			if (tx < 30 || tx> 570 || ty < 30 || ty> 570) continue;
			if (a == 1)
			{
				if (book2[tx][ty] == 10 || book2[tx][ty] == 11)
				{
					sum++;
					if (book2[tx][ty] == 10)
					{
						que[a][tail[a]].x = tx; que[a][tail[a]].y = ty;
						book2[tx][ty] = 11;
						tail[a]++;
					}
					printf("A  sum=%d\n", sum);
					for (int i = 0; i < 3; i++)
					{
						tx += next[k][0]; ty += next[k][1];
						if (tx < 30 || tx > 570 || ty < 30 || ty > 570) break;
						if (book2[tx][ty] == 10 || book2[tx][ty] == 11)sum++;
						printf("B sum=%d\n", sum);
					}
				}
			}
			if (a == 2)
			{
				if (book2[tx][ty] == 20 || book2[tx][ty] == 21)
				{
					sum++;
					if (book2[tx][ty] == 20)
					{
						que[a][tail[a]].x = tx; que[a][tail[a]].y = ty;
						book2[tx][ty] = 21;
						tail[a]++;
					}
					printf("A  sum=%d\n", sum);
					for (int i = 0; i < 3; i++)
					{
						tx += next[k][0]; ty += next[k][1];
						if (tx < 30 || tx > 570 || ty < 30 || ty > 570) break;
						if (book2[tx][ty] == 20 || book2[tx][ty] == 21)sum++;
						printf("B sum=%d\n", sum);
					}
				}
			}
			if (sum == 5) { fflag = 1; if (a == 1)Flag = 1; if (a == 2)Flag = 2; break; }
		}
		if (fflag == 1) break;
		head[a]++;
	}
	for (int i = 0; i <= 600; i += 30)
		for (int j = 0; j <= 600; j += 30)
		{
			if (book2[i][j] == 11)book2[i][j] = 10;
			if (book2[i][j] == 21)book2[i][j] = 20;
		}
	cout << "fflag=" << fflag << endl;
	if (fflag == 1)return 9;
	else return -1;
}

/*���塢�����ж�ִ��������*/
void play(int tx1,int ty1)
{
	printf("A  B  x=%d y=%d\n", tx1, ty1);
	if (tx1 >= 30 && tx1 <= 570 && ty1 >= 30 && ty1 <= 570)
	{
		if (flag == 1 && book2[tx1][ty1] == 1)/*��flag=1����ʾ��ǰ����Ϊ����*/
		{
			book2[tx1][ty1] = 10;
			/*step1��¼������mark1�������ڽ�������ջ*/
			step1 += 1;
			mrk1x[step1] = tx1; mrk1y[step1] = ty1;
			chess_mouse(tx1, ty1, flag);
			/*ȷ�������������*/
			loc[flag].x = tx1; loc[flag].y = ty1;
			/*�����ж��Ƿ��Ѿ���������*/
			int ans = bfs(flag);
			if (ans == 9) { flag3 = 1; }
			/*����flag=2��ʹ�¸�����Ϊ����*/
			flag = 2;
		}
		else
		{
			if (flag == 2 && book2[tx1][ty1] == 1)/*��flag=2����ʾ��ǰ����Ϊ����*/
			{
				book2[tx1][ty1] = 20;
				/*step2��¼������mark2�������ڽ�������ջ*/
				step2 += 1;
				mrk2x[step2] = tx1; mrk2y[step2] = ty1;
				chess_mouse(tx1, ty1, flag);
				/*ȷ�������������*/
				loc[flag].x = tx1; loc[flag].y = ty1;
				/*�����ж��Ƿ��Ѿ���������*/
				int ans = bfs(flag);
				if (ans == 9) { flag3 = 1; }
				/*����flag=2��ʹ�¸�����Ϊ����*/
				flag = 1;
			}
		}
		k = 1;
	}
	/*���¡����塱��*/
	printf("cc\n");
	printf("tx1=%d ty1=%d k=%d\n", tx1, ty1,k);
	if (tx1 >= 580 && tx1 <= 830 && ty1 >= 380 && ty1 <= 500 && k == 1&& (step1>=3 || step2 >= 3))
	{
		printf("bb\n");
		if (flag == 2 && step1 > 0)
		{
			flag = 1;
			book2[mrk1x[step1]][mrk1y[step1]] = 1;
			for (int i = 30; i <= 570; i += 30)
				for (int j = 30; j <= 570; j += 30)
					book[j][i] = book2[j][i];
			step1 -= 1;
			cleardevice();
			map1();
			retract();
		}
		else
		{
			if (flag == 1 && step2 > 0)
			{
				flag = 2;
				book2[mrk2x[step2]][mrk2y[step2]] = 1;
				for (int i = 30; i <= 570; i += 30)
					for (int j = 30; j <= 570; j += 30)
						book[j][i] = book2[j][i];
				step2 -= 1;
				cleardevice();
				map1();
				retract();
			}
		}
		k = 0;
	}
	if (flag3 == 1)
	{
		closegraph();
		end_();
		return ;
	}
}

/*���������������*/
void chess_key()
{
	int flagg = 0;
	cursor();
	while (1)
	{
		BeginBatchDraw();
		if (_kbhit())
		{
			char key = _getch();
			printf("key=%c,=%d\n", key, key);
			switch (key)
			{
			case 72:/*��*/
			case 'W':
			case 'w':
				if (ys1 - 30 >= 10)
				{
					ys1 -= 30; ys2 -= 30; yx2 -= 30; yx1 -= 30;
				} break;
			case 80:/*��*/
			case 'S':
			case 's':if (yx1 + 30 <= 590)
			{
				yx1 += 30; ys1 += 30; ys2 += 30; yx2 += 30;
			} break;
			case 75:/*��*/
			case 'A':
			case 'a':if (x1 - 30 >= 10)
			{
				x1 -= 30; x2 -= 30; x3 -= 30;
			} break;
			case 77:/*��*/
			case 'D':
			case 'd':if (x2 + 30 <= 590)
			{
				x2 += 30; x1 += 30; x3 += 30;
			} break;
			case 13:
			case 32:flagg = 1;/*����*/
				break;
			case '=':flagg = 2;/*����*/
				break;
			}
		}
		if (flagg == 0)/*�ƶ����*/
		{
			cleardevice();
			map1();
			for (int i = 30; i <= 570; i += 30)
			{
				for (int j = 30; j <= 570; j += 30)
				{
					if (book2[j][i] == 10 || book2[j][i] == 11) { setfillcolor(BLACK); fillcircle(j, i, 12); }
					if (book2[j][i] == 20 || book2[j][i] == 21) { setfillcolor(WHITE); fillcircle(j, i, 12); }
				}
			}
			cursor();
		}
		if (flagg == 1)/*����*/
		{
			play(x3, ys2 + 5);
			for (int i = 30; i <= 570; i += 30)
			{
				for (int j = 30; j <= 570; j += 30)
				{
					if (book2[j][i] == 10 || book2[j][i] == 11) { setfillcolor(BLACK); fillcircle(j, i, 12); }
					if (book2[j][i] == 20 || book2[j][i] == 21) { setfillcolor(WHITE); fillcircle(j, i, 12); }
				}
			}
			flagg = 0;
		}
		if (flagg == 2)/*����*/
		{
			play(630, 420);
			retract();
			flagg = 0;
		}
		EndBatchDraw();
	}
	FlushBatchDraw();
}

/*��������������*/
void start_1()
{
	int w1=0, w2=0, b1=0, b2=0;
	cout << "A" << endl;
	while (1)
	{
		if (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			/*��λ���ӵ�λ��*/
			int tx1 = msg.x % 30, ty1 = msg.y % 30;
			if (tx1 >= 15)tx1 = 30 - tx1 + msg.x;
			else          tx1 = msg.x - tx1;
			if (ty1 >= 15)ty1 = 30 - ty1 + msg.y;
			else          ty1 = msg.y - ty1;
			/*���������Ϣ*/
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				printf("x=%d y=%d\n", tx1, ty1);
				play(tx1, ty1);
			}
		}
	}
}

/*��Ϸ˵��ҳ��*/
void show_()
{
	int Flag = 0;
	while (1)
{
		BeginBatchDraw();
		IMAGE imgg0;
		loadimage(&imgg0, "./��Ϸ˵��.png", 535, 755);
		putimage(0, 0, &imgg0);
		setfillcolor(RGB(6, 128, 215));
		fillroundrect(320, 700, 445, 735, 15, 15);
		setbkmode(TRANSPARENT);
		settextstyle(0, 15, "����");
		outtextxy(341, 705, "֪����");
	if (MouseHit())
	{
		MOUSEMSG msg = GetMouseMsg();
		/*��λ���ӵ�λ��*/
		int tx1 = msg.x , ty1 = msg.y;
		/*���������Ϣ*/
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			printf("x=%d y=%d\n", tx1, ty1);
			if (tx1 >= 320 && tx1 <= 445 && ty1 >= 700 && ty1 <= 735)
				Flag = 1;
		}
	}
	EndBatchDraw();
	if (Flag == 1)
		break;
}
}

/*�ܺ�������*/
int main()
{
	int FFLAG = 0;
	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
		{
			if (i % 30 == 0 && j % 30 == 0)
			{book[i][j] = 1; book2[i][j] = 1;}
			else
			{book[i][j] = inf1;book2[i][j] = inf1;}
		}
	initgraph(515, 768, SHOWCONSOLE);/*�������ڣ�ȷ�����ڴ�С*/
	/*���ز����ͼƬ����ʼҳ��*/
	ExMessage msg;
	while (1)
	{
		IMAGE img;
		loadimage(&img, "./��ʼ2.png", 516, 769);
		putimage(0, 0, &img);
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 177 && msg.x <= 347 && msg.y >= 303 && msg.y <= 475)
				{
					bgm();
					cleardevice();
					modern1();
					closegraph();
					initgraph(850, 590, SHOWCONSOLE);
					map1();
					if (flag1 == 10) { start_1(); }
					if (flag1 == 20) { chess_key(); }
				}
				else {
					if (msg.x >= 177 && msg.x <= 350 && msg.y >= 556 && msg.y <= 720)
					{
						cleardevice();
						outtextxy(130, 130, "��Ϸ���а����£�");
					}
					else {
						if (msg.x >= 0 && msg.x <= 170 && msg.y >= 547 && msg.y <= 718)
						{
							cleardevice();
							closegraph();
							initgraph(535, 755, SHOWCONSOLE);
							show_();
						}
						else {
							if (msg.x >= 353 && msg.x <= 512 && msg.y >= 549 && msg.y <= 717)
							{
								cleardevice();
								outtextxy(140, 140, "��Ϸ���˳���");
								FFLAG = 10;
							}
						}
					}
				}; break;
			}
		}
		if (FFLAG == 10)break;
	}
	closegraph();
	system("pause");
	return 0;
}
