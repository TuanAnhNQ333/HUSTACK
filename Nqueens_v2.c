#include <stdio.h>
#include <stdbool.h>

int N;

// Hàm in ra giải pháp
void printSolution(int row[]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (row[i] == j) {
                printf("Q ");  // In quân hậu
            } else {
                printf(". ");  // In ô trống
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Hàm giải quyết bài toán quân hậu
void solve(int col, int left_diagonal, int right_diagonal, int row[]) {
    if (col == (1 << N) - 1) {  // Kiểm tra nếu đã đặt quân hậu trên tất cả các cột
        printSolution(row);  // In ra một giải pháp
        return;
    }

    int safe_spots = ((1 << N) - 1) & ~(col | left_diagonal | right_diagonal);
    while (safe_spots) {
        int current_spot = safe_spots & -safe_spots;  // Lấy vị trí quân hậu hiện tại
        safe_spots -= current_spot;  // Xóa vị trí hiện tại khỏi safe_spots

        // Tìm hàng để đặt quân hậu
        int row_position = __builtin_ctz(current_spot);
        row[row_position] = row_position;  // Cập nhật vị trí quân hậu

        // Gọi đệ quy để tìm quân hậu tiếp theo
        solve(col | current_spot, 
              (left_diagonal | current_spot) << 1, 
              (right_diagonal | current_spot) >> 1, 
              row);
    }
}

int main() {
    printf("Enter the size of the chessboard (N): ");
    scanf("%d", &N);
    
    if (N < 1 || N > 20) {
        printf("N must be between 1 and 20.\n");
        return 1;
    }

    int row[N];  // Mảng lưu vị trí của quân hậu
    for (int i = 0; i < N; i++) {
        row[i] = -1;  // Khởi tạo tất cả giá trị là -1
    }

    solve(0, 0, 0, row); // Bắt đầu với các vị trí còn trống
    return 0;
}
