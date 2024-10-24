#include <stdio.h>

void print_binary(int num, int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n); // Đọc giá trị n
    
    int total = 1 << n; // 2^n dãy nhị phân
    
    for (int i = 0; i < total; i++) {
        print_binary(i, n); // In dãy nhị phân tương ứng với số i
    }
    
    return 0;
}