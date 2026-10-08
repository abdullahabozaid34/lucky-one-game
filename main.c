#include <stdio.h>

#define SIZE 6

void initializeBoard(char board[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            board[i][j] = '.';
        }
    }
}

void displayBoard(char board[SIZE][SIZE])
{
    int i, j;
    printf("\n   ");
    for (i = 0; i < SIZE; i++)
    {
        printf("  %d ", i);
    }
    printf("\n");
    for (i = 0; i < SIZE; i++)
    {
        printf(" %d  ", i);
        for (j = 0; j < SIZE; j++)
        {
            printf("  %c ", board[i][j]);
        }
        printf("\n");
        printf("\n");
    }
}
void firstPlacement(char board[SIZE][SIZE])
{
    board[1][1] = 'O';
    board[4][4] = 'X';
}
int hasAdjacentOwnSymbol(char board[SIZE][SIZE], int row, int col, char symbol)
{
    int i, j;
    int newRow, newCol;
    for (i = -1; i <= 1; i++)
    {
        for (j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            newRow = row + i;
            newCol = col + j;
            if (newRow >= 0 && newRow < SIZE &&
                newCol >= 0 && newCol < SIZE)
            {
                if (board[newRow][newCol] == symbol)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int isValidMove(char board[SIZE][SIZE], int row, int col, char symbol)
{
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
    {
        return 0;
    }
    if (board[row][col] != '.')
    {
        return 0;
    }
    if (!hasAdjacentOwnSymbol(board, row, col, symbol))
    {
        return 0;
    }
    return 1;
}

void placeMark(char *cell, char symbol)
{
    *cell = symbol;
}

int isBoardFull(char board[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == '.')
            {
                return 0;
            }
        }
    }
    return 1;
}
int checkDirection(char board[SIZE][SIZE], int row, int col,
                   int rowDir, int colDir, char symbol)
{
    int count = 0;
    int i;
    int newRow, newCol;
    for (i = 0; i < SIZE; i++)
    {
        newRow = row + (i * rowDir);
        newCol = col + (i * colDir);
        if (newRow >= 0 && newRow < SIZE &&
            newCol >= 0 && newCol < SIZE)
        {
            if (board[newRow][newCol] == symbol)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
    if (count == 6)
    {
        return 1;
    }
    return 0;
}
int checkWin(char board[SIZE][SIZE], char symbol)
{
    int row, col;
    for (row = 0; row < SIZE; row++)
    {
        for (col = 0; col < SIZE; col++)
        {
            if (board[row][col] == symbol)
            {
                if (checkDirection(board, row, col, 0, 1, symbol))
                {
                    return 1;
                }
                if (checkDirection(board, row, col, 1, 0, symbol))
                {
                    return 1;
                }
                if (checkDirection(board, row, col, 1, 1, symbol))
                {
                    return 1;
                }
                if (checkDirection(board, row, col, 1, -1, symbol))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    char board[SIZE][SIZE];
    char player1Symbol = 'O';
    char player2Symbol = 'X';
    int row, col;
    int currentPlayer = 1;
    char currentSymbol;
    initializeBoard(board);
    firstPlacement(board);
    printf("     Lucky One Game     \n");
    printf(" Player 1 : O\n");
    printf(" Player 2 : X\n");
    while (1)
    {
        displayBoard(board);
        if (currentPlayer == 1)
        {
            currentSymbol = player1Symbol;
            printf("\nPlayer 1 Turn (O)\n");
        }
        else
        {
            currentSymbol = player2Symbol;
            printf("\nPlayer 2 Turn (X)\n");
        }
        while (1)
        {
            printf("Enter row (0-5): ");
            scanf("%d", &row);
            printf("Enter column (0-5): ");
            scanf("%d", &col);
            if (isValidMove(board, row, col, currentSymbol))
            {
                break;
            }
            printf("Invalid move! Try again.\n");
        }
        placeMark(&board[row][col], currentSymbol);
        if (checkWin(board, currentSymbol))
        {
            displayBoard(board);
            if (currentPlayer == 1)
            {
                printf("\nPlayer 1 Wins!\n");
            }
            else
            {
                printf("\nPlayer 2 Wins!\n");
            }
            break;
        }
        if (isBoardFull(board))
        {
            displayBoard(board);
            printf("\nGame Draw!\n");
            break;
        }
        if (currentPlayer == 1)
        {
            currentPlayer = 2;
        }
        else
        {
            currentPlayer = 1;
        }
    }
    return 0;
}