#include <stdio.h>

#define MAZE_SIZE 7
#define OK 0
#define NG 1
#define VISITED 2

typedef struct {
    int x;
    int y;
} Coordinate;

int stack_top;
int sol_num;
Coordinate stack_visit[100];
Coordinate paths[100][100];
int path_length[100];

// maze[x][y]に迷路図情報を設定する
int maze[MAZE_SIZE][MAZE_SIZE] = {
    {NG, NG, NG, NG, NG, NG, NG},
    {NG, OK, OK, OK, OK, OK, NG},
    {NG, OK, NG, OK, NG, OK, NG},
    {NG, OK, OK, OK, OK, NG, NG},
    {NG, NG, OK, NG, OK, NG, NG},
    {NG, OK, OK, OK, OK, OK, NG},
    {NG, NG, NG, NG, NG, NG, NG}
};
    
// 始点と終点の座標を設定する
int start_x = 1, start_y = 1;
int goal_x = 5, goal_y = 5;

void visit(int x, int y){
    maze[x][y] = VISITED;                                           // 足跡フラグを入れる
    stack_visit[stack_top] = (Coordinate){x, y};                    // スタックに座標を入れる
    if(x == goal_x && y == goal_y){                                 // 終点に到達
        for(int k = 0; k <= stack_top; k++){
            paths[sol_num][k] = stack_visit[k];                     
        }
        path_length[sol_num] = stack_top + 1;
        sol_num = sol_num + 1;                                               
    }else{
        stack_top = stack_top + 1;                                
        if(maze[x][y+1] == OK)                                      // Up                                
            visit(x, y+1);
        if(maze[x+1][y] == OK)                                      // Right
            visit(x+1, y);
        if(maze[x][y-1] == OK)                                      // Down                         
            visit(x, y-1);
        if(maze[x-1][y] == OK)                                      // Left
            visit(x-1, y);
        stack_top = stack_top - 1;                                 
    }
    maze[x][y] = OK;
}

// mazeを反時計回りに90度回転して表示する
void print(int maze[MAZE_SIZE][MAZE_SIZE]){
    int rotated_start_x = start_y;
    int rotated_start_y = MAZE_SIZE - 1 - start_x;
    int rotated_goal_x = goal_y;
    int rotated_goal_y = MAZE_SIZE - 1 - goal_x;

    for(int i = 0; i < MAZE_SIZE; i++){
        for(int j = 0; j < MAZE_SIZE; j++){
            int original_x = j;
            int original_y = MAZE_SIZE - 1 - i;
            
            if(original_x == start_x && original_y == start_y){
                printf("S");
            }else if(original_x == goal_x && original_y == goal_y){
                printf("G");
            }else if(maze[original_x][original_y] == OK){
                printf("□");    
            }else if(maze[original_x][original_y] == NG){
                printf("■");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main(void){
    stack_top = 0;
    sol_num = 0;
    // 迷路の表示
    print(maze);
    // 迷路の探索
    visit(start_x, start_y);
    if(sol_num == 0){
        printf("迷路の解は見つからなかった\n");
    }else{
        for(int u = 0; u < sol_num; u++){
            printf("path %d:\n", u+1);
            for(int v = 0; v < path_length[u]; v++){
                printf("(%d, %d) ", paths[u][v].x, paths[u][v].y);
            }
            printf("\n");
        }
    }
    return 0;
}
