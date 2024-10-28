#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    // Khởi tạo các biến để lưu tọa độ biên
    int min_x = INT_MAX;
    int max_x = INT_MIN;
    int min_y = INT_MAX;
    int max_y = INT_MIN;

    // Đọc từng hình chữ nhật và cập nhật tọa độ biên
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        // Cập nhật tọa độ biên
        if (x1 < min_x) min_x = x1;
        if (x2 < min_x) min_x = x2;
        if (x1 > max_x) max_x = x1;
        if (x2 > max_x) max_x = x2;

        if (y1 < min_y) min_y = y1;
        if (y2 < min_y) min_y = y2;
        if (y1 > max_y) max_y = y1;
        if (y2 > max_y) max_y = y2;
    }

    // Tính diện tích của hình chữ nhật bao quanh
    int area = (max_x - min_x) * (max_y - min_y);

    // In kết quả
    printf("%d\n", area);

    return 0;
}
