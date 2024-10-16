#include<stdio.h>
void printbinary(int num, int n)
{
    // mang luu tru tung bit
    char binary[n + 1];
    binary [n] = '\0';
    for(int i = n - 1; i >= 0; i --)
    {
        // tao bit va luu vao mang
        binary [i] = (num & 1) ? '1' : '0';
        num >>= 1; // dich phai de lay bit tiep theo
    }
    printf("%s\n", binary );
}
int main()
{
    int n;
    scanf("%d", &n);
    int total = 1 << n;
    for(int i = 0; i < total; i ++)
    {
        printbinary(i, n);
    }
    return 0;
}