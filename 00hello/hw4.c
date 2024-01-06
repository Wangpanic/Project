#include <stdio.h>
#define block 8
int Chess(int chess[block][block] , int x , int y){
    int rx , ry , dx , dy;

    if(x<0 || y<0 || x>=block || y>=block){
        printf("Not in range.");
        return 0;
    }
    else if(chess[y][x] == 0){
        printf("it is block.");
        return 0;
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
                        chess[ry][rx] = 3;
                        printf("(%d , %d)\n", rx , ry);
                        break;
                    }
                    else{break;}
                }
                }
            }
        }
    }
    return 1;
}

int main(){
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
    int x , y ;
    scanf("%d %d", &x , &y);
    Chess(chess , x , y);
    
    for(int i=0 ; i<block ; i++){
        for(int j=0 ; j<block ; j++){
            printf("%d ",chess[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}





