#include<Windows.h>              //其实有graphics.h头文件的话这个可以不写但我还是写了方便理解吧
#include"game.h"                 //自定义的头文件（本页虽然在定义改头文件内的函数，但定义过程中也用到了其中的函数，所以也要写上）
                                 //注意：自定义的头文件不能用<>包括，要用" ".
#include<map>
map<string,int>has;
//实现txt文件的读写
#include<fstream>  //ifstream
#include<string>   //包含getline()

FILE* fp;
int style;        //1 人人对战  2 人机对战
int n = 0;      //人机对战时人下棋数
int step = 0;     //表示下棋次数
int board[25][25];//0表示该点无棋子状态，1代表黑棋，2代表白棋
int view[25][25];//人机打分表
int lasta = -1, lastb = -1;
int lastx = -1, lasty = -1;//用全局变量记录上一步的棋子信息，便于悔棋操作
int robx = -1, roby = -1;//记录电脑上一步的棋子信息
int X = 10 * 25 + 25, Y = 10 * 25 + 25, a = 10, b = 10;//光标起始位置

struct SCORE
{
	char name[1000];
	int sco;
}score[1000000];//最多可以储存1000000个排行数据
bool cmp(SCORE a, SCORE b)
{
	return a.sco < b.sco;
}
void cursor()//指定移动光标
{
	setlinecolor(RED);
	circle(X, Y, 12);
}
char* itoa_my(int value, char* string, int radix)//把整形数字转化为字符串
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
void botton(int x, int y, int w, int h, const char* text)//模拟按钮
{
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	settextstyle(30, 0, "黑体");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;//居中
	outtextxy(tx, ty, text);
}

//功能函数们
//背景音乐
void BGM()
{
	//打开音乐，播放音乐 alias 取别名 reprat 重复播放
	mciSendString("open cute.mp3", NULL, 0, NULL);
	mciSendString("play cute.mp3 repeat", NULL, 0, NULL);
}
//游戏首页
void INITGAME()//初始化游戏
{
	style = -1;//未选模式
	initgraph(630, 550);    //创建自定义窗口
	//initgraph(630, 550, SHOWCONSOLE);    //测试用
	BGM();
	HWND hnd = GetHWnd();//获取窗口句柄
	SetWindowText(hnd, "五子棋");//给窗口命个名
	loadimage(NULL, "游戏入口封面.jpg", 630, 550);//设置背景
	settextstyle(0, 0, "黑体");
	settextcolor(RGB(243, 71, 78));    //设置当前文字颜色
	setbkmode(TRANSPARENT);//设置背景模式，TRANSPARENT是透明的意思，让字体背景透明，才能使得字体显示在背景之上
	outtextxy(165, 160, "！！！欢迎来到游戏五子棋！！！");//outtextxy这个函数用于在指定位置输出字符串，参数1和参数2为输出起始点位置的坐标
	outtextxy(155, 400, "说明：先下者为黑棋，五子连珠者胜");
	outtextxy(215, 450, "MADING FOR STARTICHIT");
	botton(215, 230, 200, 30, "开始游戏");
	botton(215, 290, 200, 30, "排行榜");
	botton(215, 350, 200, 30, "退出游戏");

	ExMessage m;
	while (1)
	{
		if (peekmessage(&m, EM_MOUSE))//这个函数用于获取一个消息并立即返回。如果获取到了消息 返回 true，反之返回 flase。
		{
			switch (m.message)
			{
			case WM_LBUTTONDOWN:
				if (m.x >= 215 && m.x <= 215 + 200 && m.y >= 230 && m.y <= 230 + 30)
				{
					//printf("我被按了");
					cleardevice();//清除游戏封面
					choosestyle();//选择游戏模式
				}
				else if (m.x >= 215 && m.x <= 215 + 200 && m.y >= 290 && m.y <= 290 + 30)
				{
					cleardevice();
					numborad();//排行榜功能
				}
				else if (m.x >= 215 && m.x <= 215 + 200 && m.y >= 350 && m.y <= 350 + 30)
				{
					//printf("我也被按了");
					EXITGAME();
				}
				break;
			}
		}
	}
}
//鼠标操作
void GAMEING()
{
	MOUSEMSG m;//保存鼠标信息
	int x = 0, y = 0;//x，y为坐标
	int a = 0, b = 0;//a，b为行列
	//鼠标持续下棋
	while (1)
	{
		m = GetMouseMsg();//get鼠标信息
		if (m.uMsg == WM_LBUTTONDOWN)//悔棋功能
		{
			//如果按悔棋键
			if (m.x >= 528 && m.x <= 528 + 100 && m.y >= 50 && m.y <= 50 + 30)
			{
				if (lasta != -1 && lastb != -1)
				{
					board[lasta][lastb] = 0;//该点变为无子
					//画棋盘色棋子并补线来模拟还原该点处棋盘
					setfillcolor(RGB(207, 243, 243));  //设置当前颜色为棋盘色RGB(246, 230, 181)
					solidcircle(lastx, lasty, 10);
					line(lastx, lasty - 10, lastx, lasty + 10);
					line(lastx - 10, lasty, lastx + 10, lasty);

					step--;//回到上一步，待下棋子颜色随之改变
					GAMEING();//继续进行游戏
				}

			}
		}
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			//枚举每个交点比对得到鼠标最近的下棋点的坐标信息
			for (int i = 1; i < 20; i++)
			{
				for (int j = 1; j < 20; j++)
				{
					if (abs(m.x - i * 25 - 25) < 12 && abs(m.y - j * 25 - 25) < 12)//一个格子为25*25，格子的一半为12.5，如果该点离下棋点距离的绝对值横竖都小于12，说明距离该点最近
					{
						x = i * 25 + 25, y = j * 25 + 25;//下棋点横纵坐标
						a = i, b = j;
					}
				}
			}
			lastx = x, lasty = y;
			lasta = a, lastb = b;//用全局变量记住上一个棋子的信息
			//printf("lastx=%d,lasty=%d,lasta=%d,lastb=%d\n", lastx, lasty, lasta, lastb);//测试位置点

			//如果棋子重复下在一个位置上
			if (board[a][b] != 0 || a == 0 || b == 0)
				continue;
			//判断黑白子
			if (step % 2 == 0)//偶数操作次数为黑棋
			{
				setfillcolor(BLACK);  //设置当前颜色为黑色
				solidcircle(x, y, 10);//画黑色无边框圆形代表玩家1黑棋子
				board[a][b] = 1;      //1标记此处已有黑棋子
			}  //tip：borad[i][j]=0时代表此处无棋子
			else {
				setfillcolor(WHITE);  //设置当前颜色为白色
				solidcircle(x, y, 10);//画白色无边框圆形代表玩家2白棋子
				board[a][b] = 2;      //2标记此处已有白棋子
			}
			step++;
		}
		if (judge(a, b) == 1)//如果某一方达成五子连珠才gameover
		{
			GAMEOVER();
		}
	}
}
//计分函数
void remember()
{
	BeginBatchDraw();//开始批量绘图
	int u = 0, k = 0;//初始棋子数
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
//键盘操作
void keyGAMEING()
{
	int flag = 0;
	cursor();
	while (1)
	{
		BeginBatchDraw();//开始批量绘图
		if (_kbhit())//如果有键盘信息
		{
			char key = _getch();
			printf("key=%c,=%d\n", key, key);
			if (X > 25 && X < 525 && Y>25 && Y < 525)
			{
				switch (key)
				{
				case 72://向上移动光标
				case 'W':
				case 'w':
					if (Y >= 75)
					{
						b--;
						Y -= 25;
					} break;
				case 80://向下移动光标
				case 'S':
				case 's':if (Y <= 550 - 75)
				{
					b++;
					Y += 25;
				} break;
				case 75://向左移动光标
				case 'A':
				case 'a':if (X >= 75)
				{
					a--;
					X -= 25;
				} break;
				case 77://向右移动光标
				case 'D':
				case 'd':if (X <= 500 - 50)
				{
					a++;
					X += 25;
				} break;
				case 13:flag = 1;/*回车或空格下棋*/
					break;
				case 32:flag = 2;/*悔棋*/
					break;
				}
			}
		}
		if (flag == 0)//移动光标（重新绘制全部棋盘及棋子）
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
		if (flag == 1 && board[a][b] == 0)/*下棋*/
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
			if (judge(a, b) == 1)//如果某一方达成五子连珠才gameover
			{
				if (step % 2 == 0)
				{
					HWND hnd = GetHWnd();//获取窗口句柄
					MessageBox(hnd, "恭喜player2胜利", "STA五子棋", MB_OK);
					memset(board, 0, sizeof(board));
					step = 0;
					INITGAME();
				}
				else
				{
					HWND hnd = GetHWnd();//获取窗口句柄
					MessageBox(hnd, "恭喜player1胜利", "STA五子棋", MB_OK);
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
		if (flag == 2)/*悔棋*/
		{
			if (lasta != -1 && lastb != -1)
			{
				board[lasta][lastb] = 0;//该点变为无子
				//画棋盘色棋子并补线来模拟还原该点处棋盘
				setfillcolor(RGB(207, 243, 243));  //设置当前颜色为棋盘色RGB(246, 230, 181)
				solidcircle(lastx, lasty, 10);
				line(lastx, lasty - 10, lastx, lasty + 10);
				line(lastx - 10, lasty, lastx + 10, lasty);

				step--;//回到上一步，待下棋子颜色随之改变
				keyGAMEING();//继续进行游戏
			}
		}
		EndBatchDraw();
	}
	FlushBatchDraw();
}
//人机游戏过程
void ROBOTGAMING()
{
	MOUSEMSG m;//保存鼠标信息
	int x = 0, y = 0;//x，y为坐标
	int a = 0, b = 0;//a，b为行列

	while (1)
	{
		m = GetMouseMsg();//get鼠标信息

		if (m.uMsg == WM_LBUTTONDOWN)//悔棋功能
		{
			//如果按悔棋键
			if (m.x >= 528 && m.x <= 528 + 100 && m.y >= 50 && m.y <= 50 + 30)
			{
				if (lasta != -1 && lastb != -1 && robx != -1 && roby != -1)
				{
					board[lasta][lastb] = 0;//该点变为无子
					board[robx][roby] = 0;
					//画棋盘色棋子并补线来模拟还原该点处棋盘
					setfillcolor(RGB(207, 243, 243));  //设置当前颜色为棋盘色RGB(246, 230, 181)
					solidcircle(lastx, lasty, 10);
					solidcircle(robx * 25 + 25, roby * 25 + 25, 10);
					line(lastx, lasty - 10, lastx, lasty + 10);
					line(lastx - 10, lasty, lastx + 10, lasty);
					line(robx * 25 + 25, roby * 25 + 25 - 10, robx * 25 + 25, roby * 25 + 25 + 10);
					line(robx * 25 + 25 - 10, roby * 25 + 25, robx * 25 + 25 + 10, roby * 25 + 25);

					step-=2;//步数减一
					ROBOTGAMING();//继续进行游戏
				}

			}
		}
		lastx = x, lasty = y;
		lasta = a, lastb = b;//用全局变量记住上一个棋子的信息
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			//枚举每个交点比对得到鼠标最近的下棋点的坐标信息
			for (int i = 1; i < 20; i++)
			{
				for (int j = 1; j < 20; j++)
				{
					if (abs(m.x - i * 25 - 25) < 12 && abs(m.y - j * 25 - 25) < 12)//一个格子为25*25，格子的一半为12.5，如果该点离下棋点距离的绝对值横竖都小于12，说明距离该点最近
					{
						x = i * 25 + 25, y = j * 25 + 25;//下棋点横纵坐标
						a = i, b = j;
					}
				}
			}
			lastx = x, lasty = y;
			lasta = a, lastb = b;//用全局变量记住上一个棋子的信息

			//如果棋子重复下在一个位置上
			if (board[a][b] != 0)
				continue;
			if (step % 2 == 0)
			{
				setfillcolor(BLACK);  //设置当前颜色为黑色
				solidcircle(x, y, 10);//画黑色无边框圆形代表玩家1黑棋子
				board[a][b] = 1;      //1标记此处已有黑棋子
				n++;
				step++;
				if (judge(a, b) == 1)//如果某一方达成五子连珠才gameover
				{
					GAMEOVER();
					n = 0;
				}
			}
				ROBOT();
		}
	}
}
//AI下棋
void aichess(int x, int y)
{
	setfillcolor(WHITE);
	solidcircle(x * 25 + 25, y * 25 + 25, 10);
	board[x][y] = 2;
}
//深搜打分
int dfs(int A, int B)
{
	string str = "x";
	//建立五子棋赋权表
	has["x1"] = 10;
	has["x11"] = 100;
	has["x111"] = 5000;//堵三（几乎）一定要堵了
	has["x1111"] = 8000;//没法堵了，看看自己能赢不
	has["x12"] = 5;
	has["x112"] = 80;
	has["x1112"] = 1000;//堵3
	has["x11112"] = 12000;//（堵四）不下就输了，第二大
	has["x21"] = 11;
	has["x211"] = 110;
	has["x2111"] = 800;
	has["x21111"] = 1100;
	has["x2"] = 20;
	has["x22"] = 200;//冲三
	has["x222"] = 5000;//活四
	has["x2222"] = 14000;//下就赢啦
	has["x221"] = 100;
	has["x2221"] = 3000;
	has["x22221"] = 12000;//下就赢了，最高分
	has["x122"] = 5;
	has["x1222"] = 100;

    //特判两下
 	board[A][B] = 2;
	if (judge(A, B) == 1)
	{
		board[A][B] = 0;
		return 99999999;//如果这里下白棋会赢，则电脑直接下就赢了
	}
	board[A][B] = 1;
	if (judge(A, B) == 1)
	{
		board[A][B] = 0;
		return 99999998;//如果这里下黑棋子会赢，则电脑一定要在这下
	}
	board[A][B] = 0;
	int ans = 0;
	int next[9][2] = { {0,0},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1} };
	for (int k = 0; k < 9; k++)//遍历该点即其八个方向
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
			else if (board[AA][BB] == 0)break;//不连贯了就出while
		}
		cout << "我确定字符串啦！！我是" << str << endl;
		if (has.count(str) == 1)//若map中key值存在
			ans += has[str];
	}
	return ans;
}
//机器思考下棋
void ROBOT()//机器下棋函数
{
	int book[20][20];//标记该点是否被搜索过
	memset(book, 0, sizeof(book));
	int i, j, a = 8, b = 8, A, B;
	int next[8][2] = { {0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1} };

	//测试标点是否正确
	for (i = 1; i <= 19; i++)
	{
		for (j = 1; j <= 19; j++)
		{
			cout << board[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//给每个空位打分
	for (i = 1; i <= 19; i++)
	{
		for (j = 1; j <= 19; j++)
		{
			if (board[j][i] == 1 || board[j][i] == 2)//以敌方黑子为中心
			{
				for (int k = 0; k < 8; k++)//八个方向遍历
				{
					A = j + next[k][0];
					B = i + next[k][1];
					//cout << "A=" << A << " B=" << B << endl;
					if (board[A][B] == 0 && book[A][B] == 0 && A > 0 && A < 20 && B>0 && B < 20)//搜索没被搜索过的空位
					{
						book[A][B] = 1;
						view[A][B] = dfs(A, B);//通过搜索为该位置打分
						printf("我打分啦！！！view[%d][%d]=%d\n", A, B, view[A][B]);//测试
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
	//寻找最大权值位置
	int max = 0;
	for (i = 1; i <= 19; i++)
	{
		for (j = 1; j <= 19; j++)
		{
			if (view[j][i] != 0)//判断是否有棋子
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
	aichess(a, b);//电脑下白棋
	step++;
	if (judge(a, b) == 1)//如果某一方达成五子连珠才gameover
	{
		GAMEOVER();
	}
	memset(view, 0, sizeof(view));//重置打分表
}
//判断是否五子连珠
int judge(int a, int b)
{
	int i, j;
	int t = step % 2;//奇数说明是判断黑棋是否获胜
	if (t == 0)// 偶数说明是判断白旗是否获胜（要与0区分开来，因为board=0时代表无棋子）
	{
		t = 2;//偶数时令t=2便于与board[i][j]比对
    }
	//横向判断（从当前往左边第四个位置开始每个位置判断包括当前位置与其右边三个位置的棋子颜色）
	for (i = a - 4, j = b; i <= a; i++)//纵坐标不变
	{
		if (i > 0 && i < 16 && t == board[i][j] && t == board[i + 1][j] && t == board[i + 2][j] && t == board[i + 3][j] && t == board[i + 4][j])
			return 1;
	}
	//纵向判断（从当前往下第四个位置开始每个位置判断包括当前位置与其上面三个位置的棋子颜色）
	for (i = a, j = b-4; j<=b; j++)//横坐标不变
	{
		if (j > 0 && j < 16 && t == board[i][j] && t == board[i][j+1] && t == board[i][j+2] && t == board[i][j+3] && t == board[i][j+4])
			return 1;
	}
	//右对角线判断（从当前往左上第四个位置开始每个位置判断包括当前位置与其右下三个位置的棋子颜色）
	for (i = a - 4, j = b - 4; i <= a && j <= b; i++, j++)
	{
		if (i > 0 && i < 16 && j>0 && j < 16 && t == board[i][j] && t == board[i + 1][j + 1] && t == board[i + 2][j + 2] && t == board[i + 3][j + 3] && t == board[i + 4][j + 4])
			return 1;
	}
	//左对角线判断（从当前往左下第四个位置开始每个位置判断包括当前位置与其右上三个位置的棋子颜色）
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
	if (signn == 0)//棋盘满了
	{
		MessageBox(NULL, "棋盘已满", "STA五子棋", MB_OK);
		INITGAME();
	}
	return 0;
}
//游戏结束
void GAMEOVER()
{
	if (style == 1)//人人模式
	{
		HWND hnd = GetHWnd();//获取窗口句柄
		if (step % 2 == 0)//偶数时五子连珠说明是白旗获胜
		{
			//MessageBox函数的作用是弹出一个提示框
			MessageBox(hnd, "恭喜player2胜利", "STA五子棋", MB_OK);
			INITGAME();
		}
		else//奇数时五子连珠说明是黑旗获胜
		{
			MessageBox(hnd, "恭喜player1胜利", "STA五子棋", MB_OK);
			INITGAME();
		}
	}
	if (style == 2)//人机模式
	{
		HWND hnd = GetHWnd();//获取窗口句柄
		if (step % 2 == 0)//偶数时五子连珠说明是电脑获胜
		{
			//MessageBox函数的作用是弹出一个提示框
			MessageBox(hnd, "挑战失败", "STA五子棋", MB_OK);
			INITGAME();
		}
		else//奇数时五子连珠说明是用户获胜
		{
			MessageBox(hnd, "恭喜您成功五子连珠", "STA五子棋", MB_OK);
			//接收用户输入并追加存入数据文件
			char s[1000];
			InputBox(s, 1000, "请输入您的用户名");
			ofstream newfile("num.txt", ios::app);//追加
			newfile << s << " " << n << endl;//输出用户名和步数到num文件中后换行
			newfile.close();
			fstream num;
			int k = 0;
			num.open("num.txt", ios::in);//读流
			while (!num.eof())
			{
				k++;
				num >> score[k].name >> score[k].sco;
				//cout << score[k].name << score[k].sco << endl;
			}
			sort(score + 1, score + k, cmp);
			//printf("一共有%d行\n", k - 1);
			/*for (int i = 1; i <= k - 1; i++)
			{
				printf("%s %d\n", score[i].name, score[i].sco);
			}*/
			ofstream file_writer("num.txt", ios_base::out);//清空文件夹
			num.close();
			num.open("num.txt", ios::out);//入流
			for (int i = 1; i <= k - 1; i++)//把排序后的数据重新存入txt文件
			{
				num << score[i].name << " " << score[i].sco << endl;
			}
			numborad();//显示排行榜
			//否则回到主页
			INITGAME();
		}
	}
}
//鼠标操作棋盘
void MAP()
{
	loadimage(NULL, "棋盘.png", 630, 550);//设置背景

	//初始化棋盘
	//棋盘大小为500*500，每格25像素格,每个棋子半径为10像素格，两个相邻棋子之间留有5像素格距离
	setlinecolor(BLACK);
	for (int i = 25; i <= 525; i += 25)
	{
		line(25, i, 525, i);
		line(i, 25, i, 525);
	}
	line(526, 25, 526, 525);
	setfillcolor(BLACK);
	//定位点
	solidcircle(5 * 25 + 25, 5 * 25 + 25, 4);
	solidcircle(5 * 25 + 25, 15 * 25 + 25, 4);
	solidcircle(15 * 25 + 25, 5 * 25 + 25, 4);
	solidcircle(15 * 25 + 25, 15 * 25 + 25, 4);
	solidcircle(10 * 25 + 25, 10 * 25 + 25, 4);

	settextcolor(RGB(45, 45, 45));
	botton(528, 50, 100, 30, "悔棋");
	//botton(528, 450, 100, 30, "返回");
	settextcolor(RGB(45, 45, 45));
	settextstyle(17, 0, "黑体");
	if (style == 1)
	{
		outtextxy(528, 100, "play1：黑棋");
		outtextxy(528, 150, "play2：白棋");
	}
	else if (style == 2)
	{
		outtextxy(528, 100, "用户：黑棋");
		outtextxy(528, 150, "电脑：白棋");
		outtextxy(528, 180, "（用户先手）");
	}
	outtextxy(528, 320, "如发现BUG");
	outtextxy(528, 340, "或有所建议");
	outtextxy(528, 370, "欢迎指正");
	outtextxy(528, 410, "微信");
	outtextxy(528, 430, "SWAY2307");
}
//键盘操作棋盘
void MAP2()
{
	loadimage(NULL, "棋盘.png", 630, 550);//设置背景

	//初始化棋盘
	//棋盘大小为500*500，每格25像素格,每个棋子半径为10像素格，两个相邻棋子之间留有5像素格距离
	setlinecolor(BLACK);
	for (int i = 25; i <= 525; i += 25)
	{
		line(25, i, 525, i);
		line(i, 25, i, 525);
	}
	line(526, 25, 526, 525);
	setfillcolor(BLACK);
	//定位点
	solidcircle(5 * 25 + 25, 5 * 25 + 25, 4);
	solidcircle(5 * 25 + 25, 15 * 25 + 25, 4);
	solidcircle(15 * 25 + 25, 5 * 25 + 25, 4);
	solidcircle(15 * 25 + 25, 15 * 25 + 25, 4);
	solidcircle(10 * 25 + 25, 10 * 25 + 25, 4);
	settextcolor(RGB(45, 45, 45));

	if (style == 1)
	{
		outtextxy(528, 100, "play1：黑棋");
		outtextxy(528, 150, "play2：白棋");
	}
	else if (style == 2)
	{
		outtextxy(528, 100, "用户：黑棋");
		outtextxy(528, 150, "电脑：白棋");
		outtextxy(528, 180, "（用户先手）");
	}
	outtextxy(528, 320, "如发现BUG");
	outtextxy(528, 340, "或有所建议");
	outtextxy(528, 370, "欢迎指正");
	outtextxy(528, 410, "微信");
	outtextxy(528, 430, "SWAY2307");
	//botton(528, 50, 100, 30, "返回");
	settextcolor(RED);
	settextstyle(17, 0, "黑体");
	outtextxy(528, 200, "按回车下棋");
	outtextxy(528, 230, "按空格悔棋");
	outtextxy(100, 5, "黑子下棋数");
	outtextxy(250, 5, "白子下棋数");
}
//退出游戏
void EXITGAME()
{
	closegraph();//关闭窗口
}
//排行榜功能
void numborad()
{
	loadimage(NULL, "排行榜背景.jpg", 630, 550);//设置背景
	botton(30, 30, 100, 30, "返回");
	setfillcolor(RGB(207, 243, 243));
	fillroundrect(200, 150, 430, 400,10,10);
	settextcolor(RGB(250,50,70));
	settextstyle(20,0,"黑体");
	outtextxy(201, 151, "  用户名        步数");
	settextcolor(RGB(250, 100, 110));

	int k = 0;
	fstream num;
	num.open("num.txt", ios::in);//读流
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
			itoa_my(score[i].sco, number, 10);//itoa函数把整数转为字符串
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
//选择游戏模式
void choosestyle()
{
	loadimage(NULL, "百变小樱.jpg", 630, 550);//设置背景
	botton(30, 30, 100, 30, "返回");
	botton(215, 230, 200, 30, "双人对战模式");
	botton(215, 290, 200, 30, "人机对战模式");
	//botton(550, 25, 70, 27, "设置");
	ExMessage m;
	while (1)
	{
		if (peekmessage(&m, EM_MOUSE))//这个函数用于获取一个消息并立即返回。如果获取到了消息 返回 true，反之返回 flase。
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
					if (flag == 1)//鼠标操作
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
//选择操作模式
int chosework()
{
	loadimage(NULL, "百变小樱.jpg", 630, 550);//设置背景
	botton(30, 30, 100, 30, "返回");
	botton(215, 230, 200, 30, "鼠标操作模式");
	botton(215, 290, 200, 30, "键盘操作模式");
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
