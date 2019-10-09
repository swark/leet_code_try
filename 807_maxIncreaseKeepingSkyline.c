#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
	int row_max[4]={0};
	int col_max[4]={0};
	int i=0,j=0;
	printf("~%d~\n",**(grid+i+j));
	/*for(i=0;i<gridSize;i++){
		printf("~%d~",grid[i][j]);
		if(grid[i][j]>col_max[i])
				col_max[i]=grid[i][j];
		for(j=0;j<(*gridColSize);j++){
			if(grid[i][j]>row_max[j])
				row_max[j]=grid[i][j];
		}
	}*/
	for(i=0;i<4;i++){
		printf("%d ",row_max[i]);
	}
	printf("------");
	for(i=0;i<4;i++){
		printf("%d ",col_max[i]);
	}
	return 0;
}
int main(int argc, char *argv[]){
	int ans=0;
	int size=4;
	//int **grid=(int**)malloc(4*sizeof(int*));
	int grid_r[4][4]={{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};

	ans=maxIncreaseKeepingSkyline((int **)grid_r,4,&size);
	printf("ans=%d\n",ans);
	return 0;
}