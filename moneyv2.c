#include <stdio.h>

int minimum_cut(int n, int X, int money_requests[]) {
    int total_money = 0;

    for (int i = 0; i < n; i++) {
        total_money += money_requests[i];
    }

    if (total_money <= X) {
        return 1; 
    }


    int money_to_cut = total_money - X;

    return money_to_cut; 
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
