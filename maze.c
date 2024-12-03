#include <stdio.h>

#define MAZE_SIZE 7
#define OK 0
#define NG 1
#define VISITED 2

#define IN_BOUNDS(x, y) ((x) >= 0 && (x) < MAZE_SIZE && (y) >= 0 && (y) < MAZE_SIZE)

typedef struct {
    int x;
    int y;
} Position;

int maze[MAZE_SIZE][MAZE_SIZE];
int stack_top;
int sol_num;
Position stack_visit[100]; // Adjust size as needed
Position paths[100][100];  // Adjust sizes as needed
int path_length[100];
int goal_x, goal_y;

void visit(int x, int y) {
    int k;
    maze[x][y] = VISITED;                                           // Mark as visited
    stack_visit[stack_top] = (Position){x, y};                      // Push current position onto stack
    if(x == goal_x && y == goal_y){                                 // Reached goal
        for(k = 0; k <= stack_top; k++){
            paths[sol_num][k] = stack_visit[k];                     // Copy current path
        }
        path_length[sol_num] = stack_top + 1;
        sol_num++;                                                  // Increment solution count
    }
    else{
        stack_top++;
        // Check each direction with bounds checking
        if(IN_BOUNDS(x, y+1) && maze[x][y+1] == OK)               // Up                                
            visit(x, y+1);
        if(IN_BOUNDS(x+1, y) && maze[x+1][y] == OK)               // Right
            visit(x+1, y);
        if(IN_BOUNDS(x, y-1) && maze[x][y-1] == OK)               // Down                         
            visit(x, y-1);
        if(IN_BOUNDS(x-1, y) && maze[x-1][y] == OK)               // Left
            visit(x-1, y);
        stack_top--;
    }
    maze[x][y] = OK;                                                // Unmark as visited
}

int main(void) {
    int i, j;
    stack_top = 0;
    sol_num = 0;
    // Initialize maze
    for(i = 0; i < MAZE_SIZE; i++){
        for(j = 0; j < MAZE_SIZE; j++){
            maze[i][j] = NG;
        }
    }

    // Set maze paths
    maze[1][1] = OK; maze[1][2] = OK; maze[1][3] = OK; maze[1][4] = OK; maze[1][5] = OK;
    maze[2][1] = OK; maze[2][2] = NG; maze[2][3] = OK; maze[2][4] = NG; maze[2][5] = OK;
    maze[3][1] = OK; maze[3][2] = OK; maze[3][3] = OK; maze[3][4] = OK; maze[3][5] = NG;
    maze[4][1] = NG; maze[4][2] = OK; maze[4][3] = NG; maze[4][4] = OK; maze[4][5] = NG;
    maze[5][1] = OK; maze[5][2] = OK; maze[5][3] = OK; maze[5][4] = OK; maze[5][5] = OK;
        
    // Set start and goal positions
    int start_x = 1, start_y = 1;
    goal_x = 5; goal_y = 5;

    visit(start_x, start_y);
    if(sol_num == 0){
        printf("迷路の解は見つからなかった\n");
    }else{
        // Display all paths
        int u, v;
        for(u = 0; u < sol_num; u++){
            printf("解 %d:\n", u+1);
            for(v = 0; v < path_length[u]; v++){
                printf("(%d, %d) ", paths[u][v].x, paths[u][v].y);
            }
            printf("\n");
        }
    }
    return 0;
}
