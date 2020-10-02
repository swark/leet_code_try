/*
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(int* nums,int numsSize, int subSetNum,int nowNum,int idx, int **res, int *line,int** returnColumnSizes, int* returnSize)
{
    if (subSetNum == nowNum) {
        res[*returnSize] = (int *)malloc(sizeof(int) * subSetNum);
        memcpy(res[*returnSize], line, sizeof(int) * subSetNum);
        (*returnColumnSizes)[*returnSize] = subSetNum;
        (*returnSize)++;
        return;
    }
    
    for (int i = idx; i < numsSize; i++) {
        line[nowNum] = nums[i];    
        backtrack(nums, numsSize, subSetNum, nowNum + 1, i + 1, res, line,returnColumnSizes,returnSize);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i=0;
    int **output = malloc(sizeof(int*) * (1<<numsSize));
    int *line= malloc(sizeof(int) * (numsSize));
    memset(line,0,numsSize);
    *returnColumnSizes = malloc(sizeof(int) * (1<<numsSize));
    
    *returnSize = 0; 
    for (i = 0;i <= numsSize; i++) {
        backtrack(nums, numsSize, i, 0, 0, output, line,returnColumnSizes,returnSize);
    }
    if(line)
        free(line);
    return output;
}

int main(){
    char str[5]={0};
    int input[20]={0};
    int i=0,j=0;
    int returnSize;
    int **output,*returnColumnSizes2=NULL;
    do{
        scanf("%s",str);
		if(!strcmp(str,"e"))
			break;
        else
            input[i++]=atoi(str);
        if(i>=20)
            break;
    }while(1);
    printf("size:%d\n",i);
    for(j=0;j<i;j++){
        printf("%d ",input[j]);
    }
    printf("\n");
    output=subsets(input,i,&returnSize,&returnColumnSizes2);
    for(i=0;i<returnSize;i++){
        printf("[");
        for(j=0;j<returnColumnSizes2[i];j++){
            printf("%d",output[i][j]);
            if(j+1<returnColumnSizes2[i])
                printf(" ");
        }
        printf("]\n");
    }
    return 0;
}