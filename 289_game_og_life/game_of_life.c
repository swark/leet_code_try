#include <stdio.h>
#include <stdlib.h>
//0:dead 1:alive 2:0->1 3:1->0
void statechange(int* ret,int value){
    *ret=*ret+(value%2);
}
int final_state(int value){
    if(value==2)
        return 1;
    else if(value==3)
        return 0;
    else
        return value;
}
int computefeature(int**board,int i,int j,int rowsize,int colsize){
    int ret=0,temp=0;
    //check boareder
    if(i-1>=0 && j-1>=0){
        statechange(&temp,board[i-1][j-1]);
    }
    if(i-1>=0){
        statechange(&temp,board[i-1][j]);
    }
    if(i-1>=0 && j+1<colsize){
        statechange(&temp,board[i-1][j+1]);
    }
    if(j-1>=0){
        statechange(&temp,board[i][j-1]);
    }
    if(j+1<colsize){
        statechange(&temp,board[i][j+1]);
    }
    if(i+1<rowsize && j-1>=0){
        statechange(&temp,board[i+1][j-1]);
    }
    if(i+1<rowsize){
        statechange(&temp,board[i+1][j]);
    }
    if(i+1<rowsize  && j+1<colsize){
        statechange(&temp,board[i+1][j+1]);
    }

    if(board[i][j]==1){
        if(temp<2 || temp>3){
            board[i][j]=3;
        }
    }else{
        if(temp==3)
            board[i][j]=2;
    }
    return ret; 
}
void gameOfLife(int** board, int boardSize, int* boardColSize){
    int i=0,j=0,temp=0;

    for(i=0;i<boardSize;i++){
        for(j=0;j<*boardColSize;j++){
            computefeature(board,i,j,boardSize,*boardColSize);
        }
    }

    for(i=0;i<boardSize;i++){
        for(j=0;j<*boardColSize;j++){
            board[i][j]=final_state(board[i][j]);
        }
    }
}
int main(){
    int ColSize=3,RowSize=4,i=0,j=0;
    int ** board=(int**)malloc(RowSize*sizeof(int*));
    for(i=0;i<4;i++)
        board[i]=(int*)malloc(ColSize*sizeof(int*));

    board[0][0]=0;
    board[0][1]=1;
    board[0][2]=0;
    
    board[1][0]=0;
    board[1][1]=0;
    board[1][2]=1;

    board[2][0]=1;
    board[2][1]=1;
    board[2][2]=1;

    board[3][0]=0;
    board[3][1]=0;
    board[3][2]=0;
    for(i=0;i<RowSize;i++){
        printf("[");
        for(j=0;j<ColSize;j++){
            printf("%d ",board[i][j]);
        }
        printf("]\n");
    }
    printf("AFTER\n");
    gameOfLife(board,RowSize,&ColSize);
    for(i=0;i<RowSize;i++){
        printf("[");
        for(j=0;j<ColSize;j++){
            printf("%d ",board[i][j]);
        }
        printf("]\n");
    }
    return 0;
}