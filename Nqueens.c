#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int N;
void solution(int board[N][N])
{
    for(int j = 0; j < N; j ++)
    {
        for(int i = 0; i < N; i ++)
        {
            if(board[i][j] == 1)
            {
                printf("%d ", i + 1);
                break;
            }
        }
    }
    printf("\n");
}
bool issafe(int board[N][N], int row, int col)
{
    for(int i = 0; i < col; i ++)
    {
        if(board[row][i])
        {
            return false;
        }
    }
    for(int i = row, j = col; i >= 0 && j >= 0; i --, j --)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    for(int i = row, j = col; i < N && j >= 0; i ++, j --)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    return true;
}
bool solvequeenuntil(int board[N][N], int col)
{
    if(col >= N)
    {
        solution(board);
        return true;
    }
    for(int i = 0; i < N; i ++)
    {
        if(issafe(board, i, col))
        {
            board[i][col] = 1;
            if(solvequeenuntil(board, col + 1))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}
bool solvequeen()
{
    int board[N][N];
    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < N; j ++)
        {
            board[i][j] = 0;
        }
    }
    for(int i = 0; i < N; i ++)
    {
        board[i][0] = 1;
        if(solvequeenuntil(board, 1))
        {
            return true;
        }
        board[i][0] = 0;
    }
    return false ;
}
int main()
{
    scanf("%d", &N);
    printf("%d\n", N);
    solvequeen();
    return 0;
}