#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

// Hướng di chuyển: lên, xuống, trái, phải
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Tạo cấu trúc cho điểm với hàng, cột và số bước
typedef struct {
    int x, y, steps;
} Point;

// Hàng đợi cho BFS
Point queue[MAX * MAX];
int front = 0, rear = 0;

// Hàm thêm phần tử vào hàng đợi
void enqueue(Point p) {
    queue[rear++] = p;
}

// Hàm lấy phần tử từ hàng đợi
Point dequeue() {
    return queue[front++];
}

// Kiểm tra hàng đợi rỗng
bool isQueueEmpty() {
    return front == rear;
}

// Kiểm tra xem điểm có nằm trong mê cung và có thể đi được không
bool isValid(int x, int y, int n, int m, int maze[MAX][MAX], bool visited[MAX][MAX]) {
    return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !visited[x][y]);
}

// Tìm đường ngắn nhất thoát khỏi mê cung
int shortestPathToExit(int n, int m, int r, int c, int maze[MAX][MAX]) {
    bool visited[MAX][MAX] = {false};

    // Khởi tạo hàng đợi với điểm xuất phát
    enqueue((Point){r, c, 0});
    visited[r][c] = true;

    while (!isQueueEmpty()) {
        Point current = dequeue();
        
        // Kiểm tra nếu điểm hiện tại ở biên của mê cung và là ô trống
        if (current.x == 0 || current.x == n - 1 || current.y == 0 || current.y == m - 1) {
            return current.steps;
        }

        // Duyệt qua các hướng
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (isValid(nx, ny, n, m, maze, visited)) {
                visited[nx][ny] = true;
                enqueue((Point){nx, ny, current.steps + 1});
            }
        }
    }

    return -1; // Không tìm thấy đường ra
}

int main() {
    int n, m, r, c;
    int maze[MAX][MAX];

    // Nhập kích thước mê cung và vị trí xuất phát
    scanf("%d %d %d %d", &n, &m, &r, &c);

    // Nhập ma trận mê cung
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    // Tìm đường ngắn nhất và in kết quả
    int result = shortestPathToExit(n, m, r, c, maze);
    printf("%d\n", result);

    return 0;
}
