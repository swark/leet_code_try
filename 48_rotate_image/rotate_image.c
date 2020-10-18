#include <stdio.h>
#include <stdlib.h>
void print_matrix(int** matrix,int cSize){
    int i=0,j=0;
    printf("------start-------\n");
    for(i=0;i<cSize;i++){
        for(j=0;j<cSize;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
    printf("--------------\n\n");
}

void swap(int* p, int* q)
{
    *p = *p ^ *q;
    *q = *p ^ *q;
    *p = *p ^ *q;
}
/*
You start from the corner and you move the

upper left corner to the upper right corner
upper right corner to the bottom right corner
bottom right corner to the bottom left corner
bottom left corner to upper left corner.
Then you move to the next column and repeat but with the adjustments.
*/
void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int temp = 0,i=0,j=0;
    for(i = 0; i < (*matrixColSize)/2; i++) 
    {
        for(j = i; j < (*matrixColSize)-i-1; j++) 
        {
            temp=matrix[i][j];
            swap(&temp,&(matrix[j][*matrixColSize-i-1]));
            swap(&temp,&(matrix[*matrixColSize-i-1][*matrixColSize-j-1]));
            swap(&temp,&(matrix[*matrixColSize-j-1][i]));
            swap(&temp,&(matrix[i][j]));
        }
        
    }
}

int main(){
    int test01[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int test02[4][4]={{5,1,9,11},{2,4,8,10},{3,3,6,7},{15,14,12,16}};
    int test03[1][1]={{1}};
    int test04[2][2]={{1}};
    int matrixColSize=3,i,j,k=1;
    int **test=(int**)malloc(sizeof(int*)*matrixColSize);
    for(i=0;i<matrixColSize;i++)
        test[i]=(int*)malloc(sizeof(int)*matrixColSize);

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            test[i][j]=k++;
        }
    }


    //print_matrix(test,3);
    rotate(test,matrixColSize,&matrixColSize);
    print_matrix(test,3);
    return 0;
}