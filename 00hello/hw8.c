#include<stdio.h>
#define way 2
struct stack
{
    top(){

    }
    push(){

    }
    pop(){

    }
    ifempty(){

    }
    iffull(){

    }
};
/*
void MAZE(int fmaze[way][way]){
    
    for(int i=0 ; i<way ; i++){
        for(int j=0 ; j<way ; j++){
            scanf("%d",&fmaze[i][j]); //0是牆壁 1是路 random?
        }
    }
};
*/

int main(){
    int maze[way][way];
    maze[way][way] ={
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
  { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
  { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
  { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
  { 1, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    };
    MAZE(maze);  //迷宮

    int  diry[-1,1,0,0] , dirx[0,0,-1,1] , dx , dy , mice=2; // 0上 1下 2左 3下
    
    for(int i=0 ; i<way ; i++){
        if(maze[0][i] == 0){
            //push.start
            maze[0][i] = mice;
            break;
        }
        else if(maze[i][0] == 0){
            //push.start
            maze[i][0] = mice;
            break;
        }
        else if(maze[9][i] == 0){
            //push.start
            maze[9][i] = mice;
            break;
        }
        else if(maze[i][9] == 0){
            //push.start
            maze[i][9] = mice;
            break;
        }
        if()
            for(int i=0 ; i<4 ; i++){
                if(dx)
            }
    }
    return 0;
}