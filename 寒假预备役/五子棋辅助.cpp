//��AI��������
void judgeRobotValue (int robotNum, int empty, int 3x�� int sy)
{

    int cnt = 0;
//һ��
    if (robotNum == 0)
        cnt = 5;
//����4
    else if (robotNum == 1)
        cnt = 10;
//����
    else if (robotNum == 2)
    {
//����
        if (empty == 1)
            cnt = 25;
//����
        else if (empty == 2)
            cnt = 50;
//����
        else if (robotNum == 3)
        {
            //����
            if (empty == 1)
                cnt = 55;
            //����
            else if (empty == 2)
                cnt = 300;
//����
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
//�������������
void judgePersonvalue (int personNum, int empty,int sx,int sy)
{
    int cnt = 0;
//����
    if (personNum == 1)
    {
        cnt = 10;
    }
//����
    else if (personNum == 2)
    {
//����
        if (empty == 1)
            cnt = 30;
//����
        else if (empty == 2)
            cnt = 40;
    }
//����
    else if (personNum == 3)
    {
//����
        if (empty == 1)
            cnt = 60;
//����
        else if (empty == 2)
            cnt = 200;
    }
//����
    else if (personNum == 4)
        cnt = 20000;
    if (cnt > aiOperation.ans)
    {
        aiOperation.x = sx;
        aiOperation.y = sy;
        aiOperation.ans = cnt;
    }
}
//AI����
void aiEvent ()
{
    if (f==-1)
    {
        initAI() ;
        //AIѡ�����ʾ
        op.isShow = false;
        op.row = aioperation.x;
        op.co1 = aioperation.y;
        op.x = aiOperation.x * GRID_w + INTERVAL;
        op.y = aiOperation.y * GRID_W + INTERVAL;
//AI����
        if (Chess[op.row] [op.co1] == 0)
        {
            //����״̬���
            Chess[op.row] [op.co1] = 2;
            drawCheckerBoard() ;
            FlushBatchDraw() ;
            //�ж�Ӯ��
            if (judgeWinner (op. row, op.co1) )
            {
                MessageBox (GetHWnd()��"Win", "AI", MB_ OK) ;
                MessageBox (GetHWnd()��"���¿�ʼ"��" �����������"��MB_ OR) ;
                clearstack (white) ;
                clearStack (black) ;
                flushCheckerBoard() ;
            }
//����״̬ת��
            op.chessPlayer = Status::Black;
            f=1;
        }
        //��������
        if (judgeFullchess())
        {
            MessageBox (GetHWnd()��"����"�� "���¿�ʼ"�� MB_ OR) ;
            clearStack (white) ;
            clearStack (black) ;
            op.chessPlayer = Status::Black;
            f =1;
            flushCheckerBoard() ;
        }
    }

    else
    {
//����һ����Ϣ�ṹ�����
        ExMessage msg;
        //��ȡ�����Ϣ
        if (peekmessage (em3g��EM MOUSE))  //EM MoUsEֻ�� Ҫ�����Ϣ
        {
            if (msg.message == WM_ LBUTTONDowN)
            {
                if (msg.x >= 460 && mag.x <= 485 && mag.y >= 250 && mag.y < 280)
                {
//���������
                    clearStack (white) ;
                    clearStack (black) ;
                    MessageBox (GetHWnd()��"win"�� "AI"�� MB_ OK) ;
                    MessageBox (GetHWnd()��"���¿�ʼ"��"�����������"��MB_ OR);
//����״̬ת��
                    op.chessPlayer = Status::Black;
                    flushCheckerBoard() ;
                    return;
                }
                else if (msg.x >= 460 && mag.x <= 485 && mag.y >= 285 && msg.y < 315)
                {
//���������
                    clearStack (white) ;
                    clearstack (black) ;
                    MessageBox (GetHWnd()��"���¿�ʼ"��"ƽ��"�� MB_ OR) ;
                    MessageBox (GetHWnd(),��""�� "���ֺڷ�����"��MB_ OK);
//����״̬ת��
                    op.chessPlayer = Status::Black;
                    flushCheckerBoard() ;
                    return;
                }
                //����У׼(�Զ��۽���������ĳ���������)
                op. isShow=false;
                int intervalGridx = msg.x % GRID_ w;
                int intervalGridy = msg.y % GRID_ w;
                int gridx, gridy;
//У׼y����
                if (intervalGridy <= GRID_ w / 2)
                    gridy = (msg.y / GRID_ W) * GRID_ w;
                else
                    gridy = (msg.y / GRID_ W + 1)��GRID_ w;
//�ж��Ƿ�Խ������
                if (gridx < INTERVAL | | gridy < INTERVAL 11
                        gridx > INTERVAL + GRID_ W * 14 11 gridy > INTERVAL + GRID_ W * 14)
                    return;
                op.isShow = true;
                op.row = (gridx һINTERVAL) / GRID_ w;
                op.col = (gridyһINTERVAL) / GRID_ w;
                op.x = gridx;
                op.y = gridy;
//�������
                if (msg.message == WM_ LBUTTONDOWN && Chess[op.row] [op.co1] == 0)
                {
//����״̬���
                    Chess [op.row] [op.co1] = 1;
                    drawCheckerBoard() ;
                    ElushBatchDraw() ;
//�ж�Ӯ��
                    if (judgeWinner (op.row, op.co1))
                    {
                        MessageBox (GetHWnd()��"Win"�� "���"��MB_ 0K) ;
                        MessageBox (GetHWnd()��"���¿�ʼ"��" �����������"��MB_ OR) ;
                        clearStack (white) ;
                        clearStack (black) ;
op.chessPlayer = Status: :
                                         Black;
                        f =1;
                        flushCheckerBoard() ;
                        return;
                    }
//����״̬ת��
op.chessPlayer = status: :
                                     White;
                    f =-1;
                }
//��������
                if (judgeFullchess())
                {
                    MessageBox (GetHWnd()��"����"�� "���¿�ʼ"��MB_ OK) ;
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
