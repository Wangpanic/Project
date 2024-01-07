#include <stdio.h>
#include <string.h>
#define block 8


void Chess(int chess[block][block] , int x , int y){
    int rx , ry , dx , dy;

    if(x<0 || y<0 || x>=block || y>=block){
        printf("Not in range.");
    }
    else if(chess[y][x] == 0){
        printf("it is block.");
    }
    else{
        for(dx=-1 ; dx<=1 ; dx++){
            for(dy=-1 ; dy<=1 ; dy++){
                if(dx != 0 || dy != 0){
                rx = x;
                ry = y;
                rx += dx;
                ry += dy;
                for(int i=0 ; i<6 ; i++){
                    if(chess[y][x] != chess[ry][rx] && chess[ry][rx] != 0){
                        rx += dx;
                        ry += dy;
                    }
                    else if(chess[ry][rx] == 0 && chess[ry-dy][rx-dx] != chess[y][x]){
                        printf("(%d , %d)\n", rx , ry);
                        break;
                    }
                        else{break;}
                    }
                }
            }
        }    
    }
}
void judge(int chess[block][block]){
    int x , y;
    for(int i=0 ; i<block ; i++){
        for(int j=0 ; j<block ; j++){
            if(chess[i][j] == 1){
                x = j;
                y = i;
                Chess(chess , x , y);
            }
        }
    }
}
int Next(int chess[block][block] , int x , int y){
    int rx , ry;
    int next[block][block];
    memcpy(next, chess, sizeof(next));
    for(int dx=-1 ; dx<=1 ; dx++){
        for(int dy=-1 ; dy<=1 ; dy++){
            if(dx != 0 || dy != 0){
                rx = x;
                ry = y;
                rx += dx;
                ry += dy;
                for(int i=0 ; i<6 ; i++){
                    if(chess[y][x] != chess[ry][rx] && chess[ry][rx] != 0){
                        next[ry][rx] = next[ry][rx] ^ 3;
                        rx += dx;
                        ry += dy;
                    }
                    else if(chess[ry][rx] == 0 && chess[ry-dy][rx-dx] != chess[y][x]){
                        break;
                    }
                    else{break;}
                }
            }
        }
    }
    memcpy(chess, next, sizeof(next));
    return chess[block][block];
}
/*
int computer(int chess[block][block]){

    return chess[block][block];
}
*/
int main(){
    int px , py;
    int chess[block][block]={
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,1,2,0,0,0},
                 {0,0,0,2,1,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0}
                };
    printf("0 block 1 white 2 black\n");
    printf("player turn:\n");
    judge(chess);
    while(scanf("%d %d", &px , &py) != EOF){
        printf("player turn:\n");
        chess[py][px] = 1;//我下的位置
        Next(chess , px , py);
        //電腦要下的位置
        //Next(chess[block][block] , px , py);//翻子
        judge(chess);
    }
    for(int i=0 ; i<block ; i++){
        for(int j=0 ; j<block ; j++){
            printf("%d ",chess[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}





