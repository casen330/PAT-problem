#include<iostream>
#include<time.h>
#include<iomanip>

#define X 8
#define Y 8

using namespace std;

int chess[X][Y];

int nextxy(int *x, int *y, int count)
{
	switch (count)
	{
	case 0:
		if ((*x)-2>=0  && (*y)-1>=0 && chess[*x-2][*y-1]==0)
		{
			*x -= 2;
			*y -= 1;
			return 1;
		}
		break;
	case 1:
		if ((*x) - 2 >= 0 && (*y) + 1 <= Y - 1 && chess[*x - 2][*y + 1] == 0)
		{
			*x -= 2;
			*y += 1;
			return 1;
		}
		break;
	case 2:
		if ((*x) - 1 >= 0 && (*y) + 2 <= Y - 1 && chess[*x - 1][*y + 2] == 0)
		{
			*x -= 1;
			*y += 2;
			return 1;
		}
		break;
	case 3:
		if ((*x) + 1 <= X - 1 && (*y) + 2 <= Y - 1 && chess[*x + 1][*y + 2] == 0)
		{
			*x += 1;
			*y += 2;
			return 1;
		}
		break;
	case 4:
		if ((*x) + 2 <= X - 1 && (*y) + 1 <= Y - 1 && chess[*x + 2][*y + 1] == 0)
		{
			*x += 2;
			*y += 1;
			return 1;
		}
		break;
	case 5:
		if ((*x) + 2 <= X - 1 && (*y) - 1 >= 0 && chess[*x + 2][*y - 1] == 0)
		{
			*x += 2;
			*y -= 1;
			return 1;
		}
		break;
	case 6:
		if ((*x) + 1 <= X - 1 && (*y) - 2 >= 0 && chess[*x + 1][*y - 2] == 0)
		{
			*x += 1;
			*y -= 2;
			return 1;
		}
		break;
	case 7:
		if ((*x) -1>=0 && (*y) - 1 >= 0 && chess[*x -1][*y - 1] == 0)
		{
			*x -= 1;
			*y -= 1;
			return 1;
		}
		break;
	default:
		break;
	}
	return 0;
}


void print()
{
	int i, j;
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			cout << setw(4) << chess[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}


//遍历棋盘 
//x,y为起始位置
//tag为标记变量，每走一步，tag加1
int TravelChessBoard(int x, int y, int tag)
{
	int x1 = x, y1 = y, flag = 0, count = 0;
	chess[x][y] = tag;
	if (tag==X*Y)
	{
		print();
		return 1;
	}
	//找到马的下一个可走的坐标（x1,y1)，如果找到，flag=1,否则为0
	flag = nextxy(&x1, &y1, count);
	while (flag==0 && count<7)
	{
		count++;
		flag = nextxy(&x1, &y1, count);
	}


	while (flag)
	{
		if (TravelChessBoard(x1, y1, tag + 1))   
		{
			return 1;
		}
		//找到马的下一个可走的坐标（x1,y1)，如果找到，flag=1,否则为0
		x1 = x;
		y1 = y;
		count++;
		flag = nextxy(&x1, &y1, count);
	}
	if (0==flag)
	{
		chess[x][y] = 0;
	}

	return 0;
}

int main()
{
	clock_t start, finish;
	start = clock();

	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			chess[i][j] = 0;
		}
	}
	if (!TravelChessBoard(5,8,1))
	{
		cout << "Error!" << endl;
	}	
	finish = clock();
	cout << "Time is :" << (double)(finish - start)/CLOCKS_PER_SEC << endl;
	return 0;
}