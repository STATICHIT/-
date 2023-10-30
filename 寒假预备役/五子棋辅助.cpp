//对AI落子评分
void judgeRobotValue (int robotNum, int empty, int 3x， int sy)
{

    int cnt = 0;
//一连
    if (robotNum == 0)
        cnt = 5;
//二连4
    else if (robotNum == 1)
        cnt = 10;
//三连
    else if (robotNum == 2)
    {
//死三
        if (empty == 1)
            cnt = 25;
//活三
        else if (empty == 2)
            cnt = 50;
//连四
        else if (robotNum == 3)
        {
            //死四
            if (empty == 1)
                cnt = 55;
            //活四
            else if (empty == 2)
                cnt = 300;
//连五
            else if (robotNun == 4)
                cnt = 30000;
            if (cnt > aioperation.ans)
            {
                aiOperation.x = sx;
                aiOperation.y = sy;
                aiOperation.ans = cnt;
            }
        }
    }
}
//对玩家落子评分
void judgePersonvalue (int personNum, int empty,int sx,int sy)
{
    int cnt = 0;
//连二
    if (personNum == 1)
    {
        cnt = 10;
    }
//连三
    else if (personNum == 2)
    {
//死三
        if (empty == 1)
            cnt = 30;
//活三
        else if (empty == 2)
            cnt = 40;
    }
//连四
    else if (personNum == 3)
    {
//死四
        if (empty == 1)
            cnt = 60;
//活四
        else if (empty == 2)
            cnt = 200;
    }
//连五
    else if (personNum == 4)
        cnt = 20000;
    if (cnt > aiOperation.ans)
    {
        aiOperation.x = sx;
        aiOperation.y = sy;
        aiOperation.ans = cnt;
    }
}
//AI操作
void aiEvent ()
{
    if (f==-1)
    {
        initAI() ;
        //AI选择框不显示
        op.isShow = false;
        op.row = aioperation.x;
        op.co1 = aioperation.y;
        op.x = aiOperation.x * GRID_w + INTERVAL;
        op.y = aiOperation.y * GRID_W + INTERVAL;
//AI下棋
        if (Chess[op.row] [op.co1] == 0)
        {
            //棋盘状态标记
            Chess[op.row] [op.co1] = 2;
            drawCheckerBoard() ;
            FlushBatchDraw() ;
            //判断赢棋
            if (judgeWinner (op. row, op.co1) )
            {
                MessageBox (GetHWnd()，"Win", "AI", MB_ OK) ;
                MessageBox (GetHWnd()，"重新开始"，" 下轮玩家先手"，MB_ OR) ;
                clearstack (white) ;
                clearStack (black) ;
                flushCheckerBoard() ;
            }
//棋手状态转换
            op.chessPlayer = Status::Black;
            f=1;
        }
        //满棋的情况
        if (judgeFullchess())
        {
            MessageBox (GetHWnd()，"和棋"， "重新开始"， MB_ OR) ;
            clearStack (white) ;
            clearStack (black) ;
            op.chessPlayer = Status::Black;
            f =1;
            flushCheckerBoard() ;
        }
    }

    else
    {
//定义一个消息结构体变量
        ExMessage msg;
        //获取鼠标消息
        if (peekmessage (em3g，EM MOUSE))  //EM MoUsE只需 要鼠标消息
        {
            if (msg.message == WM_ LBUTTONDowN)
            {
                if (msg.x >= 460 && mag.x <= 485 && mag.y >= 250 && mag.y < 280)
                {
//清空棋子区
                    clearStack (white) ;
                    clearStack (black) ;
                    MessageBox (GetHWnd()，"win"， "AI"， MB_ OK) ;
                    MessageBox (GetHWnd()，"重新开始"，"下轮玩家先手"，MB_ OR);
//棋手状态转换
                    op.chessPlayer = Status::Black;
                    flushCheckerBoard() ;
                    return;
                }
                else if (msg.x >= 460 && mag.x <= 485 && mag.y >= 285 && msg.y < 315)
                {
//清空棋子区
                    clearStack (white) ;
                    clearstack (black) ;
                    MessageBox (GetHWnd()，"重新开始"，"平局"， MB_ OR) ;
                    MessageBox (GetHWnd(),”""， "下轮黑方先手"，MB_ OK);
//棋手状态转换
                    op.chessPlayer = Status::Black;
                    flushCheckerBoard() ;
                    return;
                }
                //坐标校准(自动聚焦到棋盘上某个点的中心)
                op. isShow=false;
                int intervalGridx = msg.x % GRID_ w;
                int intervalGridy = msg.y % GRID_ w;
                int gridx, gridy;
//校准y坐标
                if (intervalGridy <= GRID_ w / 2)
                    gridy = (msg.y / GRID_ W) * GRID_ w;
                else
                    gridy = (msg.y / GRID_ W + 1)“GRID_ w;
//判断是否越出棋盘
                if (gridx < INTERVAL | | gridy < INTERVAL 11
                        gridx > INTERVAL + GRID_ W * 14 11 gridy > INTERVAL + GRID_ W * 14)
                    return;
                op.isShow = true;
                op.row = (gridx 一INTERVAL) / GRID_ w;
                op.col = (gridy一INTERVAL) / GRID_ w;
                op.x = gridx;
                op.y = gridy;
//左击下棋
                if (msg.message == WM_ LBUTTONDOWN && Chess[op.row] [op.co1] == 0)
                {
//棋盘状态标记
                    Chess [op.row] [op.co1] = 1;
                    drawCheckerBoard() ;
                    ElushBatchDraw() ;
//判断赢棋
                    if (judgeWinner (op.row, op.co1))
                    {
                        MessageBox (GetHWnd()，"Win"， "玩家"，MB_ 0K) ;
                        MessageBox (GetHWnd()，"重新开始"，" 下轮玩家先手"，MB_ OR) ;
                        clearStack (white) ;
                        clearStack (black) ;
op.chessPlayer = Status: :
                                         Black;
                        f =1;
                        flushCheckerBoard() ;
                        return;
                    }
//棋手状态转换
op.chessPlayer = status: :
                                     White;
                    f =-1;
                }
//满棋的情况
                if (judgeFullchess())
                {
                    MessageBox (GetHWnd()，"和棋"， "重新开始"，MB_ OK) ;
                    clearStack (white) ;
                    clearStack (black) ;
                    op. chessPlayer = Status::Black;
                    f=1;
                    flushCheckerBoard() ;
                }
            }
        }

    }
}
