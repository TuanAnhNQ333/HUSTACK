/*
Given a 0-1 matrix of size n (n rows and n columns). 
Compute the number Q of columns of the given matrix in which
 all the element of the column are 1.
Line 1: contains a positive integer n (1 <= n <= 1000)
Line i+1 (i = 1,...,n): contains the ith row of the given matrix

*/
#include<stdio.h>

void matrix(int a[1000][1000], int n)
{
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}
int count(int a[1000][1000], int n)
{
    int count = 0;
    for(int j = 0; j < n; j ++)
    {
        int allones = 1;
        for(int i = 0; i < n; i ++)
        {
            if(a[i][j] == 0)
            {
                allones = 0;
                break;
            }
        }
        if(allones)
        {
            count ++;
        }
    }
    return count ;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[1000][1000];
    matrix(a, n);
    int result = count(a, n);
    printf("%d", result);
    return 0;
}
/*
Input
5
1 1 1 1 1 
1 1 1 1 0 
1 0 1 1 1 
1 1 1 1 1 
1 0 1 1 0 

Output 
3
*/