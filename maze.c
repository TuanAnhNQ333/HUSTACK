#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 1000
// khai bao bien va ctdl x, y tung cap la huong di chuyen
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

typedef struct 
{
    int x, y, steps;
} Point;
// 2 hang doi cho xuat phat va diem bien
Point queue1[MAX*MAX], queue2[MAX*MAX]; 
// danh dau cac o da di QUA
bool visited1[MAX][MAX], visited2[MAX][MAX];
// chi so dau cuoi
int front1 = 0, rear1 = 0, front2 = 0, rear2 = 0;
// them p vao cuoi hang doi queue va tang chi so rear
void enqueue(Point queue[], int *rear, Point p)
{
    queue[(*rear)++] = p;
}
// lay phan tu o dau hang doi va tang chi so front
Point dequeue(Point queue[], int *front)
{
    return queue[(*front)++];
}
// kiem tra xem o co rong khong, so sanh front = rear
bool isqueueempty(int front, int rear)
{
    return front == rear;
}
// kiem tra diem co hop le khong 
/*
diem : phai nam trong me cung, la o trong, chua di qua*/
bool isvalid(int x, int y, int n, int m, int maze[MAX][MAX], bool visited[MAX][MAX])
{
    return(x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !visited[x][y]);
}
// tim duong ngan nhat thoat khoi me cung
// thuat toan bidirectionBFS
int bidirectionbfs(int n, int m, int r, int c, int maze[MAX][MAX])
{
    // dat tat ca o trong visited1 va visited2 thanh false
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            visited1[i][j] = visited2[i][j] = false;
        }
    }
    // khoi tao tim kiem tu diem [r,c] trong queue1
    enqueue(queue1, &rear1, (Point){r, c, 0});
    visited1[r][c] = true;
    // khoi tao bfs tu cac o bien
    for(int i = 0; i < n; i ++)
    {
        if(maze[i][0] == 0)
        {
            enqueue(queue2, &rear2, (Point){i, 0, 0});
            visited2[i][0] = true;
        }
        if(maze[i][m - 1] == 0)
        {
            enqueue(queue2, &rear2, (Point){i, m - 1, 0});
            visited2[i][m - 1] = true;
        }
    }
    for(int j = 0; j < m; j ++)
    {
        if(maze[0][j] == 0)
        {
            enqueue(queue2, &rear2, (Point){0, j, 0});
            visited2[0][j] = true;
        }
        if(maze[n - 1][j] == 0)
        {
            enqueue(queue2, &rear2, (Point){n - 1, j, 0});
            visited2[n - 1][j] = true;
        }
    }
    // vong lap bfs 2 chieu
    while(!isqueueempty(front1, rear1) && !isqueueempty(front2, rear2))
    {
        Point current1 = dequeue(queue1, &front1);
        // chay bfs tu queue1
        if(!isqueueempty(front1, rear1))
        {
            Point current1 = dequeue(queue1, &front1);
            // kiem tra neu 2 bfs gap nhau 
            if(visited2[current1.x][current1.y])
            {
                return current1.steps + queue2[front2 - 1].steps;
            }
            // duyet qua 4 lan o lan can cua current1
            for(int i = 0; i < 4; i ++)
            {
                int nx1 = current1.x + dx[i];
                int ny1 = current1.y + dy[i];

                if(isvalid(nx1, ny1, n, m, maze, visited1))
                {
                    visited1[nx1][ny1] = true;
                    enqueue(queue1, &rear1, (Point){nx1, ny1, current1.steps + 1});
                }
            }
        }
        // chay bfs tu queue2
        if(!isqueueempty(front2, rear2))
        {
            Point current2 = dequeue(queue2, &front2);
            // kiem tra neu 2 bfs gap nhau
            if(visited1[current2.x][current2.y])
            {
                return current2.steps + queue1[front1 - 1].steps;
            }
            // duyet qua 4 o lan can cua current2
            for(int i = 0; i < 4; i++)
            {
                int nx2 = current2.x + dx[i];
                int ny2 = current2.y + dy[i];

                if(isvalid(nx2, ny2, n, m, maze, visited2))
                {
                    visited2[nx2][ny2] = true;
                    enqueue(queue2, &rear2, (Point){nx2, ny2, current2.steps + 1});
                }
            }
        }
    }
    return -1;
}
int main()
{
    int n, m, r, c;
    int maze[MAX][MAX];
    scanf("%d %d %d %d", &n, &m, &r, &c);
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            scanf("%d", &maze[i][j]);
        }
    }
    int result = bidirectionbfs(n, m, r, c, maze);
    printf("%d\n", result);
    return 0;
}
/*
Input
8 12 5 6
1 1 0 0 0 0 1 0 0 0 0 1
1 0 0 0 1 1 0 1 0 0 1 1
0 0 1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 1 0 0 1 0 1
1 0 0 1 0 0 0 0 0 1 0 0
1 0 1 0 1 0 0 0 1 0 1 0
0 0 0 0 1 0 1 0 0 0 0 0
1 0 1 1 0 1 1 1 0 1 0 1

Output
7
*/