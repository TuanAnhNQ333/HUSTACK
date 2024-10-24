
// thuat toan : rut gon phan (n-k)! o mau so va thuc hien phep cnk = n*(n-1)*...*(n-k+1)/k!

/*
Viết chương trình nhập vào 2 số k và n, sau đó xuất ra số lượng tổ hợp chập k của n.
Ví dụ
Đầu vào:
3 5
Đầu ra:
10
*/
#include<stdio.h>

long long combination(int n, int k) {
    if (k > n - k) {
        k = n - k;  // C(k, n) = C(n-k, n), chọn k nhỏ hơn để tối ưu
    }
    long long result = 1;
    for (int i = 0; i < k; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

int main() {
    int n, k;
   
    scanf("%d %d", &k, &n);
    
    // Tính C(n, k)
    printf("%lld\n", combination(n, k));
    
    return 0;
}
