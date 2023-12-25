#include <stdio.h>
#define block 8
int main(){
    /*
    int chess[8][8] = {
    {2,1,1,1,1,1,1,0},
    {2,1,2,1,1,2,1,0},
    {2,2,1,1,1,2,1,1},
    {2,1,2,1,1,2,1,0},
    {2,1,2,2,2,2,1,0},
    {2,2,2,2,2,2,1,0},
    {2,2,2,1,1,2,0,0},
    {0,1,0,0,0,0,0,0}
    };
    */
   
    printf("0 block 1 black 2 white\n");
    for(int i=0 ; i<block ; i++){
        for(int j=0 ; j<block ; j++){
            scanf("%d", &chess[i][j]);
        }
    }
    int x , y , dx , dy , rx , ry;
    scanf("%d %d", &x , &y);
    
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
                        chess[ry][rx] = 3;
                        break;
                    }
                    else{break;}
                }
                }
            }
        }
    }
    for(int i=0 ; i<block ; i++){
        for(int j=0 ; j<block ; j++){
            
            printf("%d ",chess[i][j]);
            
        }
        printf("\n");
    }
    
    return 0;
}





