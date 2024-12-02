#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char board[3][3];
char currentPlayer;
char playerName[20];
void Board();
int Winner();
int Draw();
void switchPlayer();
void computerMove();
void Board() 
{
    for(int i=0;i<3;i++) 
    {
        for(int j=0;j<3;j++) 
        {
            board[i][j]=' ';
        }
    }
    currentPlayer='O';
}

void printBoard() 
{
    printf("\n");
    for(int i=0;i<3;i++) 
    {
        for(int j=0;j<3;j++) 
        {
            printf(" %c ",board[i][j]);
            if (j<2) 
			printf("|");
        }
        printf("\n");
        if(i < 2) 
		printf("---|---|---\n");
    }
    printf("\n");
}

int Winner() 
{
    for(int i=0;i<3;i++) 
    {
        if(board[i][0]==currentPlayer&&board[i][1]==currentPlayer&&board[i][2]==currentPlayer)
        {
        	return 1;
		}
        if(board[0][i]==currentPlayer&&board[1][i]==currentPlayer&&board[2][i]==currentPlayer)
        {
        	return 1;
		}
    }
    if(board[0][0]==currentPlayer&&board[1][1]==currentPlayer&&board[2][2]==currentPlayer) 
	{
		return 1;
	}
    if(board[0][2]==currentPlayer&&board[1][1]==currentPlayer&&board[2][0]==currentPlayer) 
	{
		return 1;
	}
    return 0;
}

int Draw() 
{
    for(int i=0;i<3;i++) 
	{
        for(int j=0;j<3;j++) 
		{
            if(board[i][j]==' ') 
			return 0;
        }
    }
    return 1;
}

void switchPlayer() 
{
    if(currentPlayer=='X')
    currentPlayer='O';
    else 
    currentPlayer='X';
}

void computerMove() 
{
    
    char opponent='X';
    for(int i=0;i<3;i++) 
	{
        for(int j=0;j<3;j++) 
		{
            if(board[i][j]==' ') 
			{
                board[i][j]=opponent;
                if(Winner()==1) 
				{
                    board[i][j]=currentPlayer;
                    printf("Computer (Player O) chose: %d %d\n",i+1,j+1);
                    return;
                }
                board[i][j]=' ';
            }
        }
    }

    for(int i=0;i<3;i++) 
	{
        for(int j=0;j<3;j++) 
		{
            if(board[i][j]==' ') 
			{
                board[i][j]=currentPlayer;
                if(Winner()==1) 
				{
                    printf("Computer (Player O) chose: %d %d\n",i+1,j+1);
                    return;
                }
                board[i][j]=' ';
            }
        }
    }

    if(board[1][1]==' ') 
	{
        board[1][1]=currentPlayer;
        printf("Computer (Player O) chose: 2 2\n");
        return;
    }

    int sides[4][2] = {{0, 1},{1, 0},{1, 2},{2, 1}};
    for(int i=0;i<4;i++) 
	{
        int row = sides[i][0];
        int col = sides[i][1];
        if (board[row][col] == ' ') 
		{
            board[row][col]=currentPlayer;
            printf("Computer (Player O) chose: %d %d\n",row+1,col+1);
            return;
        }
    }
    
    int corners[4][2]={{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    for (int i=0;i<4;i++) 
	{
        int row=corners[i][0];
        int col=corners[i][1];
        if(board[row][col]==' ') 
		{
            board[row][col]=currentPlayer;
            printf("Computer (Player O) chose: %d %d\n", row + 1, col + 1);
            return;
        }
    }
}

int main() 
{
    int row, col;
    printf("Enter your First name (Player X): ");
    scanf("%s", playerName);
    Board();
    computerMove();
    switchPlayer();
    int p=1;
    while(p==1) 
    {
    	printBoard();
        if(currentPlayer=='X') 
		{
            printf("%s (Player %c), enter your move (row): ",playerName,currentPlayer);
            scanf("%d",&row);
            printf("%s (Player %c), enter your move (column): ",playerName,currentPlayer);
            scanf("%d",&col);
            if (row<1||row>3||col<1||col>3||board[row-1][col-1]!=' ') 
            {
                printf("Invalid move\n");
                continue;
            }

            board[row-1][col-1]=currentPlayer;
        } else 
		{
            computerMove();
        }
        system("cls");
        if(Winner()==1) 
        {
            printBoard();
            if(currentPlayer == 'X') 
			{
                printf("%s (Player %c) wins!\n\n\n", playerName, currentPlayer);
            } 
			else 
			{
                printf("Computer (Player %c) wins!\n\n\n", currentPlayer);
            }
            break;
        }
        if (Draw()==1) 
        {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        switchPlayer();
    }
    return 0;
}

