#include<Windows.h>              //��ʵ��graphics.hͷ�ļ��Ļ�������Բ�д���һ���д�˷�������
#include"game.h"                 //�Զ����ͷ�ļ�����ҳ��Ȼ�ڶ����ͷ�ļ��ڵĺ����������������Ҳ�õ������еĺ���������ҲҪд�ϣ�
                                 //ע�⣺�Զ����ͷ�ļ�������<>������Ҫ��" ".
#include<map>
map<string,int>has;
//ʵ��txt�ļ��Ķ�д
#include<fstream>  //ifstream
#include<string>   //����getline()

FILE* fp;
int style;        //1 ���˶�ս  2 �˻���ս
int n = 0;      //�˻���սʱ��������
int step = 0;     //��ʾ�������
int board[25][25];//0��ʾ�õ�������״̬��1������壬2�������
int view[25][25];//�˻���ֱ�
int lasta = -1, lastb = -1;
int lastx = -1, lasty = -1;//��ȫ�ֱ�����¼��һ����������Ϣ�����ڻ������
int robx = -1, roby = -1;//��¼������һ����������Ϣ
int X = 10 * 25 + 25, Y = 10 * 25 + 25, a = 10, b = 10;//�����ʼλ��

struct SCORE
{
	char name[1000];
	int sco;
}score[1000000];//�����Դ���1000000����������
bool cmp(SCORE a, SCORE b)
{
	return a.sco < b.sco;
}
void cursor()//ָ���ƶ����
{
	setlinecolor(RED);
	circle(X, Y, 12);
}
char* itoa_my(int value, char* string, int radix)//����������ת��Ϊ�ַ���
{
	char zm[37] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char aa[100] = { 0 };
	int sum = value;
	char* cp = string;
	int i = 0;
	while (sum > 0)
	{
		aa[i++] = zm[sum % radix];
		sum /= radix;
	}
	for (int j = i - 1; j >= 0; j--)
	{
		*cp++ = aa[j];
	}
	*cp = '\0';
	return string;
}
void botton(int x, int y, int w, int h, const char* text)//ģ�ⰴť
{
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	settextstyle(30, 0, "����");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;//����
	outtextxy(tx, ty, text);
}

//���ܺ�����
//��������
void BGM()
{
	//�����֣��������� alias ȡ���� reprat �ظ�����
	mciSendString("open cute.mp3", NULL, 0, NULL);
	mciSendString("play cute.mp3 repeat", NULL, 0, NULL);
}
//��Ϸ��ҳ
void INITGAME()//��ʼ����Ϸ
{
	style = -1;//δѡģʽ
	initgraph(630, 550);    //�����Զ��崰��
	//initgraph(630, 550, SHOWCONSOLE);    //������
	BGM();
	HWND hnd = GetHWnd();//��ȡ���ھ��
	SetWindowText(hnd, "������");//������������
	loadimage(NULL, "��Ϸ��ڷ���.jpg", 630, 550);//���ñ���
	settextstyle(0, 0, "����");
	settextcolor(RGB(243, 71, 78));    //���õ�ǰ������ɫ
	setbkmode(TRANSPARENT);//���ñ���ģʽ��TRANSPARENT��͸������˼�������屳��͸��������ʹ��������ʾ�ڱ���֮��
	outtextxy(165, 160, "��������ӭ������Ϸ�����壡����");//outtextxy�������������ָ��λ������ַ���������1�Ͳ���2Ϊ�����ʼ��λ�õ�����
	outtextxy(155, 400, "˵����������Ϊ���壬����������ʤ");
	outtextxy(215, 450, "MADING FOR STARTICHIT");
	botton(215, 230, 200, 30, "��ʼ��Ϸ");
	botton(215, 290, 200, 30, "���а�");
	botton(215, 350, 200, 30, "�˳���Ϸ");

	ExMessage m;
	while (1)
	{
		if (peekmessage(&m, EM_MOUSE))//����������ڻ�ȡһ����Ϣ���������ء������ȡ������Ϣ ���� true����֮���� flase��
		{
			switch (m.message)
			{
			case WM_LBUTTONDOWN:
				if (m.x >= 215 && m.x <= 215 + 200 && m.y >= 230 && m.y <= 230 + 30)
				{
					//printf("�ұ�����");
					cleardevice();//�����Ϸ����
					choosestyle();//ѡ����Ϸģʽ
				}
				else if (m.x >= 215 && m.x <= 215 + 200 && m.y >= 290 && m.y <= 290 + 30)
				{
					cleardevice();
					numborad();//���а���
				}
				else if (m.x >= 215 && m.x <= 215 + 200 && m.y >= 350 && m.y <= 350 + 30)
				{
					//printf("��Ҳ������");
					EXITGAME();
				}
				break;
			}
		}
	}
}
//������
void GAMEING()
{
	MOUSEMSG m;//���������Ϣ
	int x = 0, y = 0;//x��yΪ����
	int a = 0, b = 0;//a��bΪ����
	//����������
	while (1)
	{
		m = GetMouseMsg();//get�����Ϣ
		if (m.uMsg == WM_LBUTTONDOWN)//���幦��
		{
			//����������
			if (m.x >= 528 && m.x <= 528 + 100 && m.y >= 50 && m.y <= 50 + 30)
			{
				if (lasta != -1 && lastb != -1)
				{
					board[lasta][lastb] = 0;//�õ��Ϊ����
					//������ɫ���Ӳ�������ģ�⻹ԭ�õ㴦����
					setfillcolor(RGB(207, 243, 243));  //���õ�ǰ��ɫΪ����ɫRGB(246, 230, 181)
					solidcircle(lastx, lasty, 10);
					line(lastx, lasty - 10, lastx, lasty + 10);
					line(lastx - 10, lasty, lastx + 10, lasty);

					step--;//�ص���һ��������������ɫ��֮�ı�
					GAMEING();//����������Ϸ
				}

			}
		}
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			//ö��ÿ������ȶԵõ���������������������Ϣ
			for (int i = 1; i < 20; i++)
			{
				for (int j = 1; j < 20; j++)
				{
					if (abs(m.x - i * 25 - 25) < 12 && abs(m.y - j * 25 - 25) < 12)//һ������Ϊ25*25�����ӵ�һ��Ϊ12.5������õ�����������ľ���ֵ������С��12��˵������õ����
					{
						x = i * 25 + 25, y = j * 25 + 25;//������������
						a = i, b = j;
					}
				}
			}
			lastx = x, lasty = y;
			lasta = a, lastb = b;//��ȫ�ֱ�����ס��һ�����ӵ���Ϣ
			//printf("lastx=%d,lasty=%d,lasta=%d,lastb=%d\n", lastx, lasty, lasta, lastb);//����λ�õ�

			//��������ظ�����һ��λ����
			if (board[a][b] != 0 || a == 0 || b == 0)
				continue;
			//�жϺڰ���
			if (step % 2 == 0)//ż����������Ϊ����
			{
				setfillcolor(BLACK);  //���õ�ǰ��ɫΪ��ɫ
				solidcircle(x, y, 10);//����ɫ�ޱ߿�Բ�δ������1������
				board[a][b] = 1;      //1��Ǵ˴����к�����
			}  //tip��borad[i][j]=0ʱ����˴�������
			else {
				setfillcolor(WHITE);  //���õ�ǰ��ɫΪ��ɫ
				solidcircle(x, y, 10);//����ɫ�ޱ߿�Բ�δ������2������
				board[a][b] = 2;      //2��Ǵ˴����а�����
			}
			step++;
		}
		if (judge(a, b) == 1)//���ĳһ��������������gameover
		{
			GAMEOVER();
		}
	}
}
//�Ʒֺ���
void remember()
{
	BeginBatchDraw();//��ʼ������ͼ
	int u = 0, k = 0;//��ʼ������
	char str1[10], str2[10];
	//std::string str3, str4;
	cleardevice();
	MAP2();

	if (step % 2 == 0)
	{
		u = step / 2;
		k = step / 2;
	}
	else
	{
		u = step / 2 + 1;
		k = step / 2;
	}
	itoa_my(u, str1, 100);
	itoa_my(k, str2, 100);
	//	cout << "str1=" << str1 << " " << "str2=" << str2 << endl;

		/*
		char str1[10], str2[10];
		itoa_my(u, str1, 10);
		outtextxy(200, 5, str1);
		itoa_my(k, str2, 10);
		outtextxy(350, 5, str2);
		*/
		//	printf("u=%s,k=%s\n", str1, str2);
	outtextxy(200, 5, str1);
	outtextxy(350, 5, str2);
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			if (board[i][j] == 1) { setfillcolor(BLACK); fillcircle(i * 25 + 25, j * 25 + 25, 10); }
			if (board[i][j] == 2) { setfillcolor(WHITE); fillcircle(i * 25 + 25, j * 25 + 25, 10); }
		}
	}
	EndBatchDraw();
}
//���̲���
void keyGAMEING()
{
	int flag = 0;
	cursor();
	while (1)
	{
		BeginBatchDraw();//��ʼ������ͼ
		if (_kbhit())//����м�����Ϣ
		{
			char key = _getch();
			printf("key=%c,=%d\n", key, key);
			if (X > 25 && X < 525 && Y>25 && Y < 525)
			{
				switch (key)
				{
				case 72://�����ƶ����
				case 'W':
				case 'w':
					if (Y >= 75)
					{
						b--;
						Y -= 25;
					} break;
				case 80://�����ƶ����
				case 'S':
				case 's':if (Y <= 550 - 75)
				{
					b++;
					Y += 25;
				} break;
				case 75://�����ƶ����
				case 'A':
				case 'a':if (X >= 75)
				{
					a--;
					X -= 25;
				} break;
				case 77://�����ƶ����
				case 'D':
				case 'd':if (X <= 500 - 50)
				{
					a++;
					X += 25;
				} break;
				case 13:flag = 1;/*�س���ո�����*/
					break;
				case 32:flag = 2;/*����*/
					break;
				}
			}
		}
		if (flag == 0)//�ƶ���꣨���»���ȫ�����̼����ӣ�
		{
			cleardevice();
			MAP2();
			for (int i = 1; i <= 19; i++)
			{
				for (int j = 1; j <= 19; j++)
				{
					if (board[i][j] == 1) { setfillcolor(BLACK); fillcircle(i * 25 + 25, j * 25 + 25, 10); }
					if (board[i][j] == 2) { setfillcolor(WHITE); fillcircle(i * 25 + 25, j * 25 + 25, 10); }
				}
			}
			cursor();
		}
		if (flag == 1 && board[a][b] == 0)/*����*/
		{
			if (step % 2 == 0)
			{
				board[a][b] = 1;
				setfillcolor(BLACK);
				fillcircle(X, Y, 10);
			}
			if (step % 2 == 1)
			{
				board[a][b] = 2;
				setfillcolor(WHITE);
				fillcircle(X, Y, 10);
			}
			step++;
			printf("step=%d\n", step);
			remember();
			if (judge(a, b) == 1)//���ĳһ��������������gameover
			{
				if (step % 2 == 0)
				{
					HWND hnd = GetHWnd();//��ȡ���ھ��
					MessageBox(hnd, "��ϲplayer2ʤ��", "STA������", MB_OK);
					memset(board, 0, sizeof(board));
					step = 0;
					INITGAME();
				}
				else
				{
					HWND hnd = GetHWnd();//��ȡ���ھ��
					MessageBox(hnd, "��ϲplayer1ʤ��", "STA������", MB_OK);
					memset(board, 0, sizeof(board));
					step = 0;
					INITGAME();
				}
			}
			lasta = a, lastb = b;
			lastx = X, lasty = Y;
			flag = 0;
		}
		if (flag == 1 && board[a][b] != 0)
		{
			continue;
			flag = 0;
		}
		if (flag == 2)/*����*/
		{
			if (lasta != -1 && lastb != -1)
			{
				board[lasta][lastb] = 0;//�õ��Ϊ����
				//������ɫ���Ӳ�������ģ�⻹ԭ�õ㴦����
				setfillcolor(RGB(207, 243, 243));  //���õ�ǰ��ɫΪ����ɫRGB(246, 230, 181)
				solidcircle(lastx, lasty, 10);
				line(lastx, lasty - 10, lastx, lasty + 10);
				line(lastx - 10, lasty, lastx + 10, lasty);

				step--;//�ص���һ��������������ɫ��֮�ı�
				keyGAMEING();//����������Ϸ
			}
		}
		EndBatchDraw();
	}
	FlushBatchDraw();
}
//�˻���Ϸ����
void ROBOTGAMING()
{
	MOUSEMSG m;//���������Ϣ
	int x = 0, y = 0;//x��yΪ����
	int a = 0, b = 0;//a��bΪ����

	while (1)
	{
		m = GetMouseMsg();//get�����Ϣ

		if (m.uMsg == WM_LBUTTONDOWN)//���幦��
		{
			//����������
			if (m.x >= 528 && m.x <= 528 + 100 && m.y >= 50 && m.y <= 50 + 30)
			{
				if (lasta != -1 && lastb != -1 && robx != -1 && roby != -1)
				{
					board[lasta][lastb] = 0;//�õ��Ϊ����
					board[robx][roby] = 0;
					//������ɫ���Ӳ�������ģ�⻹ԭ�õ㴦����
					setfillcolor(RGB(207, 243, 243));  //���õ�ǰ��ɫΪ����ɫRGB(246, 230, 181)
					solidcircle(lastx, lasty, 10);
					solidcircle(robx * 25 + 25, roby * 25 + 25, 10);
					line(lastx, lasty - 10, lastx, lasty + 10);
					line(lastx - 10, lasty, lastx + 10, lasty);
					line(robx * 25 + 25, roby * 25 + 25 - 10, robx * 25 + 25, roby * 25 + 25 + 10);
					line(robx * 25 + 25 - 10, roby * 25 + 25, robx * 25 + 25 + 10, roby * 25 + 25);

					step-=2;//������һ
					ROBOTGAMING();//����������Ϸ
				}

			}
		}
		lastx = x, lasty = y;
		lasta = a, lastb = b;//��ȫ�ֱ�����ס��һ�����ӵ���Ϣ
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			//ö��ÿ������ȶԵõ���������������������Ϣ
			for (int i = 1; i < 20; i++)
			{
				for (int j = 1; j < 20; j++)
				{
					if (abs(m.x - i * 25 - 25) < 12 && abs(m.y - j * 25 - 25) < 12)//һ������Ϊ25*25�����ӵ�һ��Ϊ12.5������õ�����������ľ���ֵ������С��12��˵������õ����
					{
						x = i * 25 + 25, y = j * 25 + 25;//������������
						a = i, b = j;
					}
				}
			}
			lastx = x, lasty = y;
			lasta = a, lastb = b;//��ȫ�ֱ�����ס��һ�����ӵ���Ϣ

			//��������ظ�����һ��λ����
			if (board[a][b] != 0)
				continue;
			if (step % 2 == 0)
			{
				setfillcolor(BLACK);  //���õ�ǰ��ɫΪ��ɫ
				solidcircle(x, y, 10);//����ɫ�ޱ߿�Բ�δ������1������
				board[a][b] = 1;      //1��Ǵ˴����к�����
				n++;
				step++;
				if (judge(a, b) == 1)//���ĳһ��������������gameover
				{
					GAMEOVER();
					n = 0;
				}
			}
				ROBOT();
		}
	}
}
//AI����
void aichess(int x, int y)
{
	setfillcolor(WHITE);
	solidcircle(x * 25 + 25, y * 25 + 25, 10);
	board[x][y] = 2;
}
//���Ѵ��
int dfs(int A, int B)
{
	string str = "x";
	//���������帳Ȩ��
	has["x1"] = 10;
	has["x11"] = 100;
	has["x111"] = 5000;//������������һ��Ҫ����
	has["x1111"] = 8000;//û�����ˣ������Լ���Ӯ��
	has["x12"] = 5;
	has["x112"] = 80;
	has["x1112"] = 1000;//��3
	has["x11112"] = 12000;//�����ģ����¾����ˣ��ڶ���
	has["x21"] = 11;
	has["x211"] = 110;
	has["x2111"] = 800;
	has["x21111"] = 1100;
	has["x2"] = 20;
	has["x22"] = 200;//����
	has["x222"] = 5000;//����
	has["x2222"] = 14000;//�¾�Ӯ��
	has["x221"] = 100;
	has["x2221"] = 3000;
	has["x22221"] = 12000;//�¾�Ӯ�ˣ���߷�
	has["x122"] = 5;
	has["x1222"] = 100;

    //��������
 	board[A][B] = 2;
	if (judge(A, B) == 1)
	{
		board[A][B] = 0;
		return 99999999;//��������°����Ӯ�������ֱ���¾�Ӯ��
	}
	board[A][B] = 1;
	if (judge(A, B) == 1)
	{
		board[A][B] = 0;
		return 99999998;//��������º����ӻ�Ӯ�������һ��Ҫ������
	}
	board[A][B] = 0;
	int ans = 0;
	int next[9][2] = { {0,0},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1} };
	for (int k = 0; k < 9; k++)//�����õ㼴��˸�����
	{
		int AA = A, BB = B, times = 1;
		str="x";
		while (AA < 20 && AA>0 && BB < 20 && BB>0 && times <= 5)
		{
			AA += next[k][0];
			BB += next[k][1];
			if (board[AA][BB] == 1)
			{
				str.push_back('1');
				times++;
			}
			else if (board[AA][BB] == 2)
			{
				str.push_back('2');
				times++;
			}
			else if (board[AA][BB] == 0)break;//�������˾ͳ�while
		}
		cout << "��ȷ���ַ�������������" << str << endl;
		if (has.count(str) == 1)//��map��keyֵ����
			ans += has[str];
	}
	return ans;
}
//����˼������
void ROBOT()//�������庯��
{
	int book[20][20];//��Ǹõ��Ƿ�������
	memset(book, 0, sizeof(book));
	int i, j, a = 8, b = 8, A, B;
	int next[8][2] = { {0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1} };

	//���Ա���Ƿ���ȷ
	for (i = 1; i <= 19; i++)
	{
		for (j = 1; j <= 19; j++)
		{
			cout << board[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//��ÿ����λ���
	for (i = 1; i <= 19; i++)
	{
		for (j = 1; j <= 19; j++)
		{
			if (board[j][i] == 1 || board[j][i] == 2)//�Եз�����Ϊ����
			{
				for (int k = 0; k < 8; k++)//�˸��������
				{
					A = j + next[k][0];
					B = i + next[k][1];
					//cout << "A=" << A << " B=" << B << endl;
					if (board[A][B] == 0 && book[A][B] == 0 && A > 0 && A < 20 && B>0 && B < 20)//����û���������Ŀ�λ
					{
						book[A][B] = 1;
						view[A][B] = dfs(A, B);//ͨ������Ϊ��λ�ô��
						printf("�Ҵ����������view[%d][%d]=%d\n", A, B, view[A][B]);//����
					}
				}
			}
		}
	}

	for (i = 1; i <= 19; i++)
	{
		for (j = 1; j <= 19; j++)
		{
			cout << view[j][i] << " ";
		}
		cout << endl;
	}
	//Ѱ�����Ȩֵλ��
	int max = 0;
	for (i = 1; i <= 19; i++)
	{
		for (j = 1; j <= 19; j++)
		{
			if (view[j][i] != 0)//�ж��Ƿ�������
			{
				if (view[j][i] > max)
				{
					max = view[j][i];
					a = j, b = i;
				}
			}
			else continue;
		}
	}
	cout << max <<" "<<a<<" "<<b<< endl;
	robx = a, roby = b;
	aichess(a, b);//�����°���
	step++;
	if (judge(a, b) == 1)//���ĳһ��������������gameover
	{
		GAMEOVER();
	}
	memset(view, 0, sizeof(view));//���ô�ֱ�
}
//�ж��Ƿ���������
int judge(int a, int b)
{
	int i, j;
	int t = step % 2;//����˵�����жϺ����Ƿ��ʤ
	if (t == 0)// ż��˵�����жϰ����Ƿ��ʤ��Ҫ��0���ֿ�������Ϊboard=0ʱ���������ӣ�
	{
		t = 2;//ż��ʱ��t=2������board[i][j]�ȶ�
    }
	//�����жϣ��ӵ�ǰ����ߵ��ĸ�λ�ÿ�ʼÿ��λ���жϰ�����ǰλ�������ұ�����λ�õ�������ɫ��
	for (i = a - 4, j = b; i <= a; i++)//�����겻��
	{
		if (i > 0 && i < 16 && t == board[i][j] && t == board[i + 1][j] && t == board[i + 2][j] && t == board[i + 3][j] && t == board[i + 4][j])
			return 1;
	}
	//�����жϣ��ӵ�ǰ���µ��ĸ�λ�ÿ�ʼÿ��λ���жϰ�����ǰλ��������������λ�õ�������ɫ��
	for (i = a, j = b-4; j<=b; j++)//�����겻��
	{
		if (j > 0 && j < 16 && t == board[i][j] && t == board[i][j+1] && t == board[i][j+2] && t == board[i][j+3] && t == board[i][j+4])
			return 1;
	}
	//�ҶԽ����жϣ��ӵ�ǰ�����ϵ��ĸ�λ�ÿ�ʼÿ��λ���жϰ�����ǰλ��������������λ�õ�������ɫ��
	for (i = a - 4, j = b - 4; i <= a && j <= b; i++, j++)
	{
		if (i > 0 && i < 16 && j>0 && j < 16 && t == board[i][j] && t == board[i + 1][j + 1] && t == board[i + 2][j + 2] && t == board[i + 3][j + 3] && t == board[i + 4][j + 4])
			return 1;
	}
	//��Խ����жϣ��ӵ�ǰ�����µ��ĸ�λ�ÿ�ʼÿ��λ���жϰ�����ǰλ��������������λ�õ�������ɫ��
	for (i = a - 4, j = b + 4; i <= a && j >= b; i++, j--)
	{
		if (i > 0 && i < 16 && j>0 && j < 16 && t == board[i][j] && t == board[i + 1][j - 1] && t == board[i + 2][j - 2] && t == board[i + 3][j - 3] && t == board[i + 4][j - 4])
			return 1;
	}
	int signn = 0;
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			if (board[i][j] == 0)
				signn = 1;
		}
	}
	if (signn == 0)//��������
	{
		MessageBox(NULL, "��������", "STA������", MB_OK);
		INITGAME();
	}
	return 0;
}
//��Ϸ����
void GAMEOVER()
{
	if (style == 1)//����ģʽ
	{
		HWND hnd = GetHWnd();//��ȡ���ھ��
		if (step % 2 == 0)//ż��ʱ��������˵���ǰ����ʤ
		{
			//MessageBox�����������ǵ���һ����ʾ��
			MessageBox(hnd, "��ϲplayer2ʤ��", "STA������", MB_OK);
			INITGAME();
		}
		else//����ʱ��������˵���Ǻ����ʤ
		{
			MessageBox(hnd, "��ϲplayer1ʤ��", "STA������", MB_OK);
			INITGAME();
		}
	}
	if (style == 2)//�˻�ģʽ
	{
		HWND hnd = GetHWnd();//��ȡ���ھ��
		if (step % 2 == 0)//ż��ʱ��������˵���ǵ��Ի�ʤ
		{
			//MessageBox�����������ǵ���һ����ʾ��
			MessageBox(hnd, "��սʧ��", "STA������", MB_OK);
			INITGAME();
		}
		else//����ʱ��������˵�����û���ʤ
		{
			MessageBox(hnd, "��ϲ���ɹ���������", "STA������", MB_OK);
			//�����û����벢׷�Ӵ��������ļ�
			char s[1000];
			InputBox(s, 1000, "�����������û���");
			ofstream newfile("num.txt", ios::app);//׷��
			newfile << s << " " << n << endl;//����û����Ͳ�����num�ļ��к���
			newfile.close();
			fstream num;
			int k = 0;
			num.open("num.txt", ios::in);//����
			while (!num.eof())
			{
				k++;
				num >> score[k].name >> score[k].sco;
				//cout << score[k].name << score[k].sco << endl;
			}
			sort(score + 1, score + k, cmp);
			//printf("һ����%d��\n", k - 1);
			/*for (int i = 1; i <= k - 1; i++)
			{
				printf("%s %d\n", score[i].name, score[i].sco);
			}*/
			ofstream file_writer("num.txt", ios_base::out);//����ļ���
			num.close();
			num.open("num.txt", ios::out);//����
			for (int i = 1; i <= k - 1; i++)//���������������´���txt�ļ�
			{
				num << score[i].name << " " << score[i].sco << endl;
			}
			numborad();//��ʾ���а�
			//����ص���ҳ
			INITGAME();
		}
	}
}
//����������
void MAP()
{
	loadimage(NULL, "����.png", 630, 550);//���ñ���

	//��ʼ������
	//���̴�СΪ500*500��ÿ��25���ظ�,ÿ�����Ӱ뾶Ϊ10���ظ�������������֮������5���ظ����
	setlinecolor(BLACK);
	for (int i = 25; i <= 525; i += 25)
	{
		line(25, i, 525, i);
		line(i, 25, i, 525);
	}
	line(526, 25, 526, 525);
	setfillcolor(BLACK);
	//��λ��
	solidcircle(5 * 25 + 25, 5 * 25 + 25, 4);
	solidcircle(5 * 25 + 25, 15 * 25 + 25, 4);
	solidcircle(15 * 25 + 25, 5 * 25 + 25, 4);
	solidcircle(15 * 25 + 25, 15 * 25 + 25, 4);
	solidcircle(10 * 25 + 25, 10 * 25 + 25, 4);

	settextcolor(RGB(45, 45, 45));
	botton(528, 50, 100, 30, "����");
	//botton(528, 450, 100, 30, "����");
	settextcolor(RGB(45, 45, 45));
	settextstyle(17, 0, "����");
	if (style == 1)
	{
		outtextxy(528, 100, "play1������");
		outtextxy(528, 150, "play2������");
	}
	else if (style == 2)
	{
		outtextxy(528, 100, "�û�������");
		outtextxy(528, 150, "���ԣ�����");
		outtextxy(528, 180, "���û����֣�");
	}
	outtextxy(528, 320, "�緢��BUG");
	outtextxy(528, 340, "����������");
	outtextxy(528, 370, "��ӭָ��");
	outtextxy(528, 410, "΢��");
	outtextxy(528, 430, "SWAY2307");
}
//���̲�������
void MAP2()
{
	loadimage(NULL, "����.png", 630, 550);//���ñ���

	//��ʼ������
	//���̴�СΪ500*500��ÿ��25���ظ�,ÿ�����Ӱ뾶Ϊ10���ظ�������������֮������5���ظ����
	setlinecolor(BLACK);
	for (int i = 25; i <= 525; i += 25)
	{
		line(25, i, 525, i);
		line(i, 25, i, 525);
	}
	line(526, 25, 526, 525);
	setfillcolor(BLACK);
	//��λ��
	solidcircle(5 * 25 + 25, 5 * 25 + 25, 4);
	solidcircle(5 * 25 + 25, 15 * 25 + 25, 4);
	solidcircle(15 * 25 + 25, 5 * 25 + 25, 4);
	solidcircle(15 * 25 + 25, 15 * 25 + 25, 4);
	solidcircle(10 * 25 + 25, 10 * 25 + 25, 4);
	settextcolor(RGB(45, 45, 45));

	if (style == 1)
	{
		outtextxy(528, 100, "play1������");
		outtextxy(528, 150, "play2������");
	}
	else if (style == 2)
	{
		outtextxy(528, 100, "�û�������");
		outtextxy(528, 150, "���ԣ�����");
		outtextxy(528, 180, "���û����֣�");
	}
	outtextxy(528, 320, "�緢��BUG");
	outtextxy(528, 340, "����������");
	outtextxy(528, 370, "��ӭָ��");
	outtextxy(528, 410, "΢��");
	outtextxy(528, 430, "SWAY2307");
	//botton(528, 50, 100, 30, "����");
	settextcolor(RED);
	settextstyle(17, 0, "����");
	outtextxy(528, 200, "���س�����");
	outtextxy(528, 230, "���ո����");
	outtextxy(100, 5, "����������");
	outtextxy(250, 5, "����������");
}
//�˳���Ϸ
void EXITGAME()
{
	closegraph();//�رմ���
}
//���а���
void numborad()
{
	loadimage(NULL, "���а񱳾�.jpg", 630, 550);//���ñ���
	botton(30, 30, 100, 30, "����");
	setfillcolor(RGB(207, 243, 243));
	fillroundrect(200, 150, 430, 400,10,10);
	settextcolor(RGB(250,50,70));
	settextstyle(20,0,"����");
	outtextxy(201, 151, "  �û���        ����");
	settextcolor(RGB(250, 100, 110));

	int k = 0;
	fstream num;
	num.open("num.txt", ios::in);//����
	while (!num.eof())
	{
		k++;
		num >> score[k].name >> score[k].sco;
		//cout << score[k].name <<" "<< score[k].sco << endl;
		if (k == 10)
			break;
	}
	for (int i = 1; i <= k; i++)
	{
		char number[10000];
		if (score[i].sco == 0)
			outtextxy(370, 160 + 20 * i, "0");
		else
		{
			itoa_my(score[i].sco, number, 10);//itoa����������תΪ�ַ���
			outtextxy(370, 160 + 20 * i, number);
		}
		outtextxy(210, 160+20*i, score[i].name);
	}

	ExMessage m;
	while (1)
	{
		if (peekmessage(&m, EM_MOUSE))
		{
			switch (m.message)
			{
			case WM_LBUTTONDOWN:
				if (m.x >= 30 && m.x <= 30 + 100 && m.y >= 30 && m.y <= 30 + 30)
				{
					INITGAME();
				}
				break;
			}
		}
	}
}
//ѡ����Ϸģʽ
void choosestyle()
{
	loadimage(NULL, "�ٱ�Сӣ.jpg", 630, 550);//���ñ���
	botton(30, 30, 100, 30, "����");
	botton(215, 230, 200, 30, "˫�˶�սģʽ");
	botton(215, 290, 200, 30, "�˻���սģʽ");
	//botton(550, 25, 70, 27, "����");
	ExMessage m;
	while (1)
	{
		if (peekmessage(&m, EM_MOUSE))//����������ڻ�ȡһ����Ϣ���������ء������ȡ������Ϣ ���� true����֮���� flase��
		{
			switch (m.message)
			{
			case WM_LBUTTONDOWN:
				if (m.x >= 30 && m.x <= 30 + 100 && m.y >= 30 && m.y <= 30 + 30)
				{
					INITGAME();
				}
				else if (m.x >= 215 && m.x <= 215 + 200 && m.y >= 230 && m.y <= 230 + 30)
				{
					style = 1;
					memset(board, 0, sizeof(board));
					int flag = 0;
					flag = chosework();
					if (flag == 1)//������
					{
						cleardevice();
						MAP();
						GAMEING();
					}
					else if (flag == 2)
					{
						cleardevice();
						MAP();
						keyGAMEING();
					}

				}
				else if (m.x >= 215 && m.x <= 215 + 200 && m.y >= 290 && m.y <= 290 + 30)
				{
					step = 0;
					style = 2;
					memset(board, 0, sizeof(board));
					cleardevice();
					MAP();
					ROBOTGAMING();
				}
				break;
			}
		}
	}
}
//ѡ�����ģʽ
int chosework()
{
	loadimage(NULL, "�ٱ�Сӣ.jpg", 630, 550);//���ñ���
	botton(30, 30, 100, 30, "����");
	botton(215, 230, 200, 30, "������ģʽ");
	botton(215, 290, 200, 30, "���̲���ģʽ");
	ExMessage m;
	while (1)
	{
		if (peekmessage(&m, EM_MOUSE))
		{
			switch (m.message)
			{
			case WM_LBUTTONDOWN:
				if (m.x >= 30 && m.x <= 30 + 100 && m.y >= 30 && m.y <= 30 + 30)choosestyle();
				else if (m.x >= 215 && m.x <= 215 + 200 && m.y >= 230 && m.y <= 230 + 30)return 1;
				else if (m.x >= 215 && m.x <= 215 + 200 && m.y >= 290 && m.y <= 290 + 30)return 2;
				break;
			}
		}
	}

}
