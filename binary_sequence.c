/*
Description
- Given an integer n, write a program that generates
 all the binary sequences of length n in a 
 lexicographic order.
Input
- Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic ordder,
 each sequence in a line
*/
#include<stdio.h>
void print_binary(int num, int n)
{
    // mang luu tru tung bit
    char binary[n+1];
    binary[n] = '\0'; // ky tu NULL o cuoi chuoi
    for(int i = n - 1; i >= 0; i --)
    {
        // lay bit va luu vao mang
        binary[i] = (num & 1) ? '1' : '0';
        num >>= 1; // dich phai de lay bit tiep theo
    }
    printf("%s\n", binary);
}
int main()
{
    int n;
    scanf("%d", &n);
    int total = 1 << n; // 2^n day nhi phan
    for(int i = 0; i < total; i ++)
    {
        print_binary(i, n);
    }
    return 0;
}
//
/*
Example
Input
3
Output
000
001
010
011
100
101
110
111
*/