#include <stdio.h>

int minimum_cut(int n, int X, int money_requests[]) {
    int total_money = 0;

    for (int i = 0; i < n; i++) 
    {
        total_money += money_requests[i];
    }

    if (total_money <= X) 
    {
        return 1; 
    } 

    int money_to_cut = total_money - X;

    int min_cut = money_to_cut / n;

    if (money_to_cut % n != 0) 
    {
        min_cut++;
    }

    return min_cut;
}

int main() {
    int n, X;

    scanf("%d %d", &n, &X);

    int money_requests[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &money_requests[i]);
    }

    int result = minimum_cut(n, X, money_requests);
    printf("%d\n", result);

    return 0;
}
/*
Input:
2 100
30 70
Output: 
1

-------------

Input:
3 100
10 20 50
Output:
10*/
