#include <iostream>

using namespace std;

int board[8][8];
int piecesNum = 1;

void capture(int x, int y);
void uncapture(int x, int y);
void putPiece(int x, int y);
void init(int x = 0, int y = 0);


int main()
{
        // we place 1st rook at (0,1)
        //init(0,1);
        init(2,3);
	return 0;
}

void init(int x, int y)
{
	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			board[i][j] = 0;
		}
	}
	board[x][y] = 9;
	capture(x,y);
	putPiece(0,0);
}

void capture(int x, int y)
{
	for(int i = 0; i < 8; i++)
	{
		board[x][i] += 1;
		board[i][y] += 1;
	}
	board[x][y] = 9;
}

void uncapture(int x, int y)
{
	for(int i = 0; i < 8; i++)
	{
		board[x][i] -= 1;
		board[i][y] -= 1;
	}
	board[x][y] = 0;
}

void putPiece(int x, int y)
{
	if(piecesNum < 8)
	{
		for(int i = 0; i<8; i++)
		{
			for(int j = 0; j<8; j++)
			{
				if(board[i][j] == 0)
				{
					// putting a piece on (i,j)
					piecesNum++;
					capture(i,j);
					putPiece(i,j);
					uncapture(x,y);

					return;
				}
			}
		}

	}
	else
	{
		for(int i = 0; i<8; i++)
		{
			for(int j = 0; j<8; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		return;
	}
}
