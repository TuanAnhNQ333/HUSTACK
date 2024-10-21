/*
Input:
2 2
1 4

Output:
4

--------------------
Input:
0 2
Output:
0*/
#include <stdio.h>

int poison(int time[], int n, int duration) {
    if (n == 0) {
        return 0;
    }

    int total_time = 0;

    for (int i = 0; i < n - 1; i++) {
        total_time += (time[i + 1] - time[i] < duration) ? (time[i + 1] - time[i]) : duration;
    }

    total_time += duration;

    return total_time;
}

int main() {
    int n, duration;

    scanf("%d %d", &n, &duration);

    int time[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &time[i]);
    }

    int result = poison(time, n, duration);
    printf("%d\n", result);

    return 0;
}
