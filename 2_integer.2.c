#include <stdio.h>

int max_subsequence_weight(int n, int a[]) {
    int max_current = a[0];
    int max_global = a[0];
    
    for (int i = 1; i < n; i++) {
        max_current = (a[i] > max_current + a[i]) ? a[i] : max_current + a[i];
        if (max_current > max_global) {
            max_global = max_current;
        }
    }
    
    return max_global;
}

int main() {
    int n;
    scanf("%d", &n); // Đọc số lượng phần tử
    int a[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Đọc từng phần tử
    }

    int result = max_subsequence_weight(n, a);
    printf("%d\n", result); // In ra trọng số lớn nhất

    return 0;
}
