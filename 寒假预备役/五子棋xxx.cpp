
int gochess(int n)
{/*下棋(移动+确认)*/
	int i,k,w;
	while(k=_getch())
	{
		switch(k)
		{
		case 13:/*按回车键下子*/
			if(n==1)
			{
				put(n);
				A.p[c.X/4][c.Y/2]=1;
				return 1;
			}
			else
			{
				put(n);
				B.p[c.X/4][c.Y/2]=1;
			    return 1;
			}
	    case 224:
		    w=_getch();
			switch(w)
			{/*上下左右移动*/
			case 72:
				for(i=1;c.Y-2*i>=0;i++)
					if(!A.p[c.X/4][(c.Y-2*i)/2]&&!B.p[c.X/4][(c.Y-2*i)/2])
					    {c.Y-=2*i;break;}
				break;
			case 80:
				for(i=1;c.Y+2*i<=28;i++)
					if(!A.p[c.X/4][(c.Y+2*i)/2]&&!B.p[c.X/4][(c.Y+2*i)/2])
					    {c.Y+=2*i;break;}
				break;
			case 75:
				for(i=1;c.X-4*i>=0;i++)
					if(!A.p[(c.X-4*i)/4][c.Y/2]&&!B.p[(c.X-4*i)/4][c.Y/2])
					    {c.X-=4*i;break;}
				break;
			case 77:
				for(i=1;c.X+4*i<=56;i++)
					if(!A.p[(c.X+4*i)/4][c.Y/2]&&!B.p[(c.X+4*i)/4][c.Y/2])
					    {c.X+=4*i;break;}
				break;
			}
			gotoxy(c.X,c.Y);
		}
	}
}
