#include <stdio.h>
#define MAX_N 10

typedef struct {
    int x;
    int y;
} Point;

int maze[MAX_N][MAX_N] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
    {1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void printMaze(int n, Point path[], int pathSize) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int isPath = 0;
            for (int k = 0; k < pathSize; k++) {
                if (path[k].x == i && path[k].y == j) {
                    isPath = 1;
                    break;
                }
            }
            printf("%c ", (maze[i][j] == 1) ? '#' : (isPath ? 'x' : ' '));
        }
        printf("\n");
    }
}

int solveMaze(int startX, int startY, int endX, int endY, int n, Point path[], int pathSize) {
    if (startX < 0 || startX >= n || startY < 0 || startY >= n || maze[startX][startY] == 1) {
        return 0;  
    }

    Point current = {startX, startY};
    path[pathSize] = current;
    pathSize++;

    if (startX == endX && startY == endY) {
        printMaze(n, path, pathSize);  
        return 1;                      
    }

    maze[startX][startY] = 1;  

    if (solveMaze(startX, startY + 1, endX, endY, n, path, pathSize) ||  // 向右
        solveMaze(startX + 1, startY, endX, endY, n, path, pathSize) ||  // 向下
        solveMaze(startX, startY - 1, endX, endY, n, path, pathSize) ||  // 向左
        solveMaze(startX - 1, startY, endX, endY, n, path, pathSize)) {   // 向上
        return 1;  
    }

    maze[startX][startY] = 0;  
    return 0;                 
}

int main() {
    int n = 10;  
    Point path[MAX_N * MAX_N];  
    int pathSize = 0;

    printf("Original Maze:\n");
    printMaze(n, path, pathSize);

    printf("\nSolving Maze:\n");
    if (!solveMaze(0, 0, n - 1, n - 1, n, path, pathSize)) {
        printf("No solution found.\n");
    }

    return 0;
}
