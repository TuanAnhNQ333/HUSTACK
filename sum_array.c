#include<stdio.h>
#include<string.h>
void reversestring(char x[]) // lat nguoc chuoi
{
    int l = 0, r = strlen(x) - 1;
    while(l < r)
    {
        char tmp = x[l];
        x[l] = x[r];
        x[r] = tmp;
        l++, r --;

    }
}
void maxswap(char a[], char b[]) // chuyen xau lon nhat thanh xau a
{
    char c[1001];
    if(strlen(b)>strlen(a))
    {
        strcpy(c, a);
        strcpy(a, b);
        strcpy(b, c);
    }
}

void reverseint(int sum[], int n) // lat nguoc mang nguyen
{
    int l = 0, r = n - 1;
    while(l<r)
    {
        int tmp = sum[l];
        sum[l] = sum[r];
        sum[r] = tmp;
        l++, r--;
    }
}
int main()
{
    char b[1001], a[1001];
    scanf("%s%s", a, b);
    maxswap(a, b);
    reversestring(a);
    reversestring(b);
    int aI[strlen(a)];
    int bI[strlen(b)];
    int sum[2002] = {0}, carry = 0, n = strlen(a);
    for(int i = 0; i < strlen(a); i ++)
    {
        aI[i] = a[i] - 48;
        if(i < strlen(b))
            bI[i] = b[i] - 48;
    }
    for(int i = 0; i < strlen(a); i ++)
    {
        sum[i] = (aI[i] + bI[i] + carry)%10;
        carry = (aI[i] + bI[i] + carry)/10;
    }
    if(carry > 0)
    {
        sum[strlen(a)] = carry;
        n = strlen(a) + 1;
    }
    reverseint(sum, n);
    for(int i = 0; i < n; i++)
    {
        printf("%d", sum[i]);
    }
    return 0;
}



















