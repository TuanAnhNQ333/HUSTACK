#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool check(int v, int r, int c)
{
    int x[r][c];
    for(int i = 0; i <= r - 1; i ++)
    {
        if(x[i][c] == v)
            return false;
    }
    for(int j = 0; j <= c - 1; j ++)
    {
        if(x[r][j] == v)
            return false;
    }
    int I = r/3;
    int J = c/3;
    int i = r - 3*I;
    int j = c - 3*J;
    for(int i1 = 0; i1 <= i - 1; i1 ++)
    {
        for(int j1 = 0; j1 <= 2; j1 ++)
        {
            if(x[3*I+i1][3*J+j1] == v)
                return false;
        }
    }
    for(int j1 = 0; j1 <= j - 1; j1++)
    {
        if(x[3*I+i][3*J+j1] == v)
        {
            return false;
        }
        return true;
    }
}
void printsolution(int v, int r, int c)
{
    check(v, r, c);
    int x[r][c];
    for(int i = 0; i <= v*r*c; i ++)
    {
        printf("%d", x[r][c]);
    }
}
void TRY(int r, int c)
{
    int x[r][c];
    for(int v = 1; v <= 9; v ++)
    {
        if(check(v,r,c) )
        {
            x[r][c] = v;
            if(r == 8 && c == 8)
            {
                printsolution(v, r, c);
            }
            else
            {
                if(c == 8) 
                    TRY(r + 1, 0);
                else
                    TRY(r, c + 1);
            }
        }
    }
}

void main()
{
    check(0,0,0);
    
}



