#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
	//int row_max[gridSize]={0};
	//int col_max[(*gridColSize)]={0};
	int *row_max=(int*)malloc(gridSize*sizeof(int));
	int *col_max=(int*)malloc((*gridColSize)*sizeof(int));
	int i=0,j=0,ans=0;
	for(i=0;i<gridSize;i++){
		row_max[i]=0;
	}
	for(i=0;i<(*gridColSize);i++){
		col_max[i]=0;
	}
	//printf("~%d~~%d~\n",gridSize,*gridColSize);
	for(i=0;i<gridSize;i++){
		for(j=0;j<(*gridColSize);j++){
			if(grid[i][j]>col_max[j])
				col_max[j]=grid[i][j];
			if(grid[i][j]>row_max[i])
				row_max[i]=grid[i][j];
		}
	}
	/*printf("\n-------------------\n");
	for(i=0;i<gridSize;i++){
		printf("%d ",row_max[i]);
	}
	printf("\n==================\n");
	for(i=0;i<(*gridColSize);i++){
		printf("%d ",col_max[i]);
	}
	printf("\n-------------------\n");*/
	for(i=0;i<gridSize;i++){
		for(j=0;j<(*gridColSize);j++){
			if(col_max[j]>row_max[i]){
				ans=ans+(row_max[i]-grid[i][j]);
			}else{
				ans=ans+(col_max[j]-grid[i][j]);
			}
		}
	}
	return ans;
}
int main(int argc, char *argv[]){
	int ans=0,i=0;
	int size=4;
	int **grid=(int**)malloc(4*sizeof(int*));
	for(i=0;i<1;i++){
		grid[i]=(int*)malloc(size*sizeof(int));
	}
	//int grid_r[4][4]={{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
	grid[0][0]=3;grid[0][1]=0;grid[0][2]=8;grid[0][3]=4;
	//grid[1][0]=2;grid[1][1]=4;grid[1][2]=5;grid[1][3]=7;
	//grid[2][0]=9;grid[2][1]=2;grid[2][2]=6;grid[2][3]=3;
	//grid[3][0]=0;grid[3][1]=3;grid[3][2]=1;grid[3][3]=0;
	ans=maxIncreaseKeepingSkyline((int **)grid,1,&size);
	
	printf("ans=%d\n",ans);
	return 0;
}